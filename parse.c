#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "parse.h"
#include "opts.h"
#include "books.h"
#include "verse.h"
#include "lib.h"
#include "range.h"

/**
 * Main entry point to our parse functionality. This is what will open up the text,
 * scan through line-by-line, evaluating the user's search.
 */
void parse(opts_t *opts)
{
    char *search = opts->search;

    FILE *fp;
    fp = fopen(KJV, "r");

    if (!fp)
    {
        printf("ERROR: could not open file.\n");
        exit(1);
    }

    char line[VERSE_LEN_MAX];

    parse_t parser;
    parser.results = 0;

    while(fgets(line, VERSE_LEN_MAX, fp))
    {
        processLine(line, search, &parser, opts);
    }

    if (opts->count)
    {
        printf("Number of results for search (%s): %s%d%s\n", search, MAIN_COLOR, parser.results, RESET_COLOR);
    }

    fclose(fp);
}

/**
 * Main entry point into parsing an individual line. This is where we break down the line
 * into a verse_t object in order to parse the line easiser and pass the verse around.
 * Up to this point we haven't looked at the verse itself or done any matching.
 */
void processLine(char *line, char *search, parse_t *parser, opts_t *opts)
{
    // parse the line into a verse format that can be easily parsed and evaluated further.
    verse_t verse = parseverse(line);

    // check to see if there is a substring in the current verse of the user's search string
    char *find = strcasestr(verse.text, search);

    // check to see whether or not we have verse flags to narrow down the search by book, chapter, verse, etc.
    // if the line doesn't match the more specific flags, match is set to FALSE and will not print.
    bool match = evalverseflags(opts, &verse);

    // check for both `find` substring and `match` boolean to determine whether or not we should print.
    // this is so we check not only is there a substring but the verseflags also match.
    if (find && match)
    {
        if (opts->count)
        {
            ++parser->results;
        }
        else
        {
            printLine(&verse, find, search);
        }
    }
}

/**
 * Evaluate the more specific verse flags as in book, chapter, verse. This will run
 * case insensitive matching on book names. and will match on either abbrev or title.
 */
bool evalverseflags(opts_t *opts, verse_t *verse)
{
    // match up and see if our book flag matches the current verse
    if (!evalbookflag(opts->book, &verse->book))
    {
        return FALSE;
    }

    // evaluate chapter opt
    if (!evalrange(opts->chapter, verse->chapter))
    {
        return FALSE;
    }

    // evaluate verse opt
    if (!evalrange(opts->verse, verse->number))
    {
        return FALSE;
    }

    return TRUE;
}

/**
 * Evaluate whether or not the book opt matches the current verse's book.
 */
bool evalbookflag(char *opt, book_t *book)
{
    // if the book flag is passed, evaluate the book to see if the flag matches the verse's book abbrev or title
    if (opt)
    {
        // if abbrev nor title match, set print to false
        if (strcasecmp(opt, book->abbrev) != 0 && strcasecmp(opt, book->title) != 0)
        {
            return FALSE;
        }
    }

    return TRUE;
}

/**
 * Function responsible for printing out the individual verse_t object.
 */
void printLine(verse_t *verse, char *find, char *search)
{
    int findpos = find - verse->text;
    int findlen  = strlen(search);
    int linelen = strlen(verse->text);

    int i = 0;

    printVerseInfo(verse);

    // print everything before the match
    for (; i < findpos; ++i)
    {
        printf("%c", verse->text[i]);
    }

    int f = 0;

    // start color output for match
    COLOR();

    // print match (will be in color)
    for (; f < findlen; ++f)
    {
        printf("%c", verse->text[i]);
        ++i;
    }

    // stop color for rest of line
    CLEAR();

    // print rest of line
    for (; i < linelen; ++i)
    {
        printf("%c", verse->text[i]);
    }
}

/**
 * Quick helper to print out the verse meta information i.e. [book chapter:verse]
 */
void printVerseInfo(verse_t *verse)
{
    // print verse information
    VERSE();
    printf("%s %d:%d ", verse->book.title, verse->chapter, verse->number);
    CLEAR();
}
