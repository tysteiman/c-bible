#include <stdio.h>

#include "opts.h"
#include "parse.h"

int main(int argc, char **argv)
{
    opts_t opts = parseflags(argc, argv);

    if (!opts.search)
    {
        printf("ERROR: Must supply a search argument.\n");
        return 1;
    }

    parse(&opts);

    return 0;
}

