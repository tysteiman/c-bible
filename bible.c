#include <stdio.h>
#include <string.h>

#define VERSE_LEN_MAX 500

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("ERROR: Must supply a search argument.\n");
        return 1;
    }

    FILE *fp;
    fp = fopen("kjv.txt", "r");

    if (!fp)
    {
        printf("ERROR: could not open file.\n");
        return 1;
    }

    char line[VERSE_LEN_MAX];

    while(fgets(line, VERSE_LEN_MAX, fp))
    {
        if (strcasestr(line, argv[1]))
        {
            printf("%s", line);
        }
    }


    return 0;
}

