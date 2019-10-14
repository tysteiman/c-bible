#ifndef BIBLE_OPTS_H
#define BIBLE_OPTS_H

typedef struct Opts {
    int count;    // -n
    int debug;    // -d
    char *book;   // -b
    char *search; // extra param
} opts_t;

opts_t parseflags(int argc, char **argv);
void debug(opts_t *opts);

#endif
