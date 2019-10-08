#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "parse.h"

void parse(char *search)
{
    FILE *fp;
    fp = fopen("kjv.txt", "r");

    if (!fp)
    {
        printf("ERROR: could not open file.\n");
        exit(1);
    }

    char line[VERSE_LEN_MAX];

    while(fgets(line, VERSE_LEN_MAX, fp))
    {
        processLine(line, search);
    }
}

void processLine(char *line, char *search)
{
    char *find = strcasestr(line, search);

    long findpos = find - line;
    int findlen  = strlen(search);
    int linelen = strlen(line);

    if (find)
    {
        printLine(findpos, line, findlen, linelen);
    }
}

void printLine(long findpos, char *line, int findlen, int linelen)
{
    int i = 0;

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
