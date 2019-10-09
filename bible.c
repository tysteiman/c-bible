#include <stdio.h>

#include "opts.h"
#include "parse.h"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("ERROR: Must supply a search argument.\n");
        return 1;
    }

    opts_t opts = parseflags(argc, argv);

    parse(&opts);

    return 0;
}

