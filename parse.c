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
        if (strcasestr(line, search))
        {
            printf("%s", line);
        }
    }
}

