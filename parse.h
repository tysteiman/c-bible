#ifndef BIBLE_PARSE_H
#define BIBLE_PARSE_H

#define VERSE_LEN_MAX 500
#define MAIN_COLOR "\033[1;31m"
#define RESET_COLOR "\033[0m"

#define COLOR()(printf("%s", MAIN_COLOR))
#define CLEAR()(printf("%s", RESET_COLOR))

void parse(char *search);
void processLine(char *line, char *search);
void printLine(long findpos, char *line, int findlen, int linelen);

#endif
