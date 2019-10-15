#ifndef BIBLE_PARSE_H
#define BIBLE_PARSE_H

#include "opts.h"
#include "verse.h"
#include "lib.h"
#include "range.h"

#define KJV "kjv.txt"

#define VERSE_LEN_MAX 1000
#define MAIN_COLOR "\033[1;31m"
#define VERSE_COLOR "\033[1;32m"
#define RESET_COLOR "\033[0m"

#define COLOR()(printf("%s", MAIN_COLOR))
#define VERSE()(printf("%s", VERSE_COLOR))
#define CLEAR()(printf("%s", RESET_COLOR))

typedef struct Parse {
    int results;
} parse_t;

void parse(opts_t *opts);
void processLine(char *line, char *search, parse_t *parser, opts_t *opts);
void printLine(verse_t *verse, char *find, char *search);
void printVerseInfo(verse_t *verse);
bool evalverseflags(opts_t *opts, verse_t *verse);
bool evalbookflag(char *opt, book_t *book);
bool evalrange(char *opt, int target);
bool hasrange(char *text);
range_t parserange(char *text);

#endif
