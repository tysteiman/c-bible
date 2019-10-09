#ifndef BIBLE_PARSE_H
#define BIBLE_PARSE_H

#include "opts.h"

#define VERSE_LEN_MAX 500
#define MAIN_COLOR "\033[1;31m"
#define VERSE_COLOR "\033[1;36m"
#define RESET_COLOR "\033[0m"

#define COLOR()(printf("%s", MAIN_COLOR))
#define VERSE()(printf("%s", VERSE_COLOR))
#define CLEAR()(printf("%s", RESET_COLOR))

typedef struct Parse {
    int results;
} parse_t;

void parse(opts_t *opts);
void processLine(char *line, char *search, parse_t *parser, opts_t *opts);
void printLine(char *line, char *find, char *search);

#endif
