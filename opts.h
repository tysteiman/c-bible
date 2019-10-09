#ifndef BIBLE_OPTS_H
#define BIBLE_OPTS_H

typedef struct Opts {
    int count;
    int debug;
    char *search;
} opts_t;

opts_t parseflags(int argc, char **argv);
void debug(opts_t *opts);

#endif
