#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("ERROR: Must supply a search argument.\n");
        return 1;
    }

    FILE *fp;
    fp = fopen("kjvdat.txt", "r");

    if (!fp)
    {
        printf("ERROR: could not open file.\n");
        return 1;
    }

    char line[100];

    fgets(line, 100, fp);

    if (strcasestr(line, argv[1]))
    {
        printf("LINE MATCHES SEARCH (%s): %s\n", argv[1], line);
    }

    return 0;
}

