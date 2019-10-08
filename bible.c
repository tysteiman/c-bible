#include <stdio.h>

#include "parse.h"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("ERROR: Must supply a search argument.\n");
        return 1;
    }

    parse(argv[1]);

    return 0;
}

