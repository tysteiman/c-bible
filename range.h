#ifndef BIBLE_RANGE_H
#define BIBLE_RANGE_H

#include "lib.h"

typedef struct Range {
    int from;
    int to;
} range_t;

bool evalrange(char *opt, int target);
bool hasrange(char *text);
range_t parserange(char *text);

#endif