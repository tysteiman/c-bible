#ifndef BIBLE_BOOKS_H
#define BIBLE_BOOKS_H

typedef struct BibBookDef {
    char *title;
    char *abbrev;
} book_t;

char *booktitle(char *abbrev);

#endif
