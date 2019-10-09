#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "parse.h"
#include "opts.h"

void parse(opts_t *opts)
{
    char *search = opts->search;

    FILE *fp;
    fp = fopen("kjv.txt", "r");

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
        printf("Number of results: %s%d%s\n", MAIN_COLOR, parser.results, RESET_COLOR);
    }

    fclose(fp);
}

void processLine(char *line, char *search, parse_t *parser, opts_t *opts)
{
    char *find = strcasestr(line, search);

    if (find)
    {
        if (opts->count)
        {
            ++parser->results;
        }
        else
        {
            printLine(line, find, search);
        }
    }
}

void printLine(char *line, char *find, char *search)
{
    int findpos = find - line;
    int findlen  = strlen(search);
    int linelen = strlen(line);

    int i = 0;

    int spaces = 0;

    // colorize verse text
    VERSE();

    // with our current formatting there are always 2 spaces that are printed
    // before getting to the actual verse text -- we treat this as the verse
    // information which is colorized.
    while (spaces < 2)
    {
        printf("%c", line[i]);

        if (line[i] == ' ')
        {
            ++spaces;
        }

        // also bump i since we are indeed moving through the line contents
        ++i;
    }

    // end of verse text
    CLEAR();

    // print everything before the match
    for (; i < findpos; ++i)
    {
        printf("%c", line[i]);
    }

    int f = 0;

    // start color output for match
    COLOR();

    // print match (will be in color)
    for (; f < findlen; ++f)
    {
        printf("%c", line[i]);
        ++i;
    }

    // stop color for rest of line
    CLEAR();

    // print rest of line
    for (; i < linelen; ++i)
    {
        printf("%c", line[i]);
    }
}
