#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "verse.h"
#include "books.h"

verse_t parseverse(char *line)
{
    verse_t verse;

    // out iterator as we parse through the verse line
    int i = 0;

    char abbrev[3];

    for (; i <= 2; ++i)
    {
        abbrev[i] = line[i];
    }

    verse.book = findbook(abbrev);

    char chapter[2];
    int chapteri = 0;

    // we should be able to shift i to +1 since we should be on a space on the next char...
    ++i;

    while (line[i] != ':')
    {
        chapter[chapteri] = line[i];

        ++i;
        ++chapteri;
    }

    chapter[chapteri] = '\0';

    verse.chapter = atoi(chapter);

    char versenumber[3];
    int versei = 0;

    // bump again since we are on the : right now
    ++i;

    while(line[i] != ' ')
    {
        versenumber[versei] = line[i];

        ++i;
        ++versei;
    }

    versenumber[versei] = '\0';

    verse.number = atoi(versenumber);

    // holders for the rest of the line i.e. the verse text itself.
    int texti = 0;
    char text[1000];

    // parse rest of verse text
    ++i; // start back on first char of actual verse
    for (; i < strlen(line); ++i)
    {
        text[texti] = line[i];
        ++texti;
    }

    // terminate string so our strdup doesnt pick up extra letters.
    text[texti] = '\0';

    // just strdup the string for now, fix later
    verse.text = strdup(text);

    return verse;
}

void debugverse(verse_t *verse)
{
    printf("VERSE INFORMATION\n");
    printf("{\n");
    printf("\tBook: %s (%s)\n", verse->book.title, verse->book.abbrev);
    printf("\tChapter: %d\n", verse->chapter);
    printf("\tVerse: %d\n", verse->number);
    printf("\tText: %s", verse->text);
    printf("}\n");
}