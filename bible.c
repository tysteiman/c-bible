#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("ERROR: Must supply a search argument.\n");
        return 1;
    }

    printf("Search param: '%s'\n", argv[1]);

    return 0;
}

