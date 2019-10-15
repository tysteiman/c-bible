#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "opts.h"
#include "lib.h"

opts_t defaultopts()
{
    opts_t opts;
    opts.count = FALSE;
    opts.debug = FALSE;
    opts.book = NULL;
    opts.chapter = NULL;
    opts.verse = NULL;
    opts.search = NULL;

    return opts;
}

opts_t parseflags(int argc, char **argv)
{
    opts_t opts = defaultopts();

    int index;
    int c;

    opterr = 0;

    while ((c = getopt (argc, argv, "ndb:c:v:")) != -1)
        switch (c)
        {
            case 'n':
                opts.count = TRUE;
                break;
            case 'd':
                opts.debug = TRUE;
                break;
            case 'b':
                opts.book = optarg;
                break;
            case 'c':
                opts.chapter = optarg;
                break;
            case 'v':
                opts.verse = optarg;
                break;
            default:
                printf("Unkown flag\n");
                exit(1);
        }

    for (index = optind; index < argc; index++)
    {
        opts.search = argv[index];
    }

    if (opts.debug)
    {
        debug(&opts);
    }

    return opts;
}

void debug(opts_t *opts)
{
    printf("\n");
    printf("Parsed command line flags:\n");
    printf("{\n");
    printf("\tCount: %s\n", opts->count ? "TRUE" : "FALSE");
    printf("\tDebug: %s\n", opts->debug ? "TRUE" : "FALSE");
    printf("\tBook: %s\n", opts->book);
    printf("\tChapter: %s\n", opts->chapter);
    printf("\tVerse: %s\n", opts->verse);
    printf("\tSearch: %s\n", opts->search);
    printf("}\n");
    printf("\n");
}
