#include <stdio.h>

#include "opts.h"
#include "parse.h"

int main(int argc, char **argv)
{
    opts_t opts = parseflags(argc, argv);

    parse(&opts);

    return 0;
}

