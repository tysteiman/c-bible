#ifndef BIBLE_VERSE_H
#define BIBLE_VERSE_H

#include "books.h"

typedef struct Verse {
    book_t book;
    int chapter;
    int number;
    char *text;
} verse_t;

verse_t parseverse(char *line);
void debugverse(verse_t *verse);

#endif