#include <stdio.h>

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

    printf("First line: %s\n", line);

    return 0;
}

