#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "parse.h"
#include "opts.h"
#include "books.h"
#include "verse.h"
#include "lib.h"

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

void processLine(char *line, char *search, parse_t *parser, opts_t *opts)
{
    // parse the line into a verse format that can be easily parsed and evaluated further.
    verse_t verse = parseverse(line);

    // check to see if there is a substring in the current verse of the user's search string
    char *find = strcasestr(verse.text, search);

    // bool that determins whether or not we print the verse or not
    int print = TRUE;

    // if the book flag is passed, evaluate the book to see if the flag matches the verse's book abbrev or title
    if (opts->book)
    {
        // if abbrev nor title match, set print to false
        if (strcasecmp(opts->book, verse.book.abbrev) != 0 && strcasecmp(opts->book, verse.book.title) != 0)
        {
            print = FALSE;
        }
    }

    // check for both `find` substring and `print` boolean to determine whether or not we should print.
    if (find && print)
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

void printVerseInfo(verse_t *verse)
{
    // print verse information
    VERSE();
    printf("%s %d:%d ", verse->book.title, verse->chapter, verse->number);
    CLEAR();
}
