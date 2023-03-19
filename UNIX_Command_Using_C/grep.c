#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include "../colours.h"
#define BUFFER_SIZE 1024

int main(int argcount, char *args[])
{
    if (argcount != 3)
    {
        printf(F_T_RED "Usage:" F_BOLD " grep search_key file_name\n" F_RESET);
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(args[2], "r");
    if (file == NULL)
    {
        printf(F_DIM F_T_RED "Cannot open the file\n" F_RESET);
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, file) != NULL)
    {
        if (strstr(buffer, args[1]) != NULL)
        {
            printf("%s", buffer);
        }
    }
    return 0;
}