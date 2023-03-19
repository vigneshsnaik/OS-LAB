#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>
#include "../colours.h"

int main(int argcount, char *args[])
{
    if (argcount != 2)
    {
        printf(F_T_RED "Usage:" F_BOLD " ls directory Name\n" F_RESET);
        exit(EXIT_FAILURE);
    }

    DIR *dir;
    struct dirent *entry;
    struct stat file_info;

    if ((dir = opendir(args[1])) == NULL)
    {
        printf(F_T_RED "Failed to open directory.\n" F_RESET);
        exit(EXIT_FAILURE);
    }
    while ((entry = readdir(dir)) != NULL)
    {
        if ((entry->d_name)[0] == '.')
            printf(F_DIM "%s\n" F_RESET, entry->d_name);
        else
            printf(F_BOLD "%s\n" F_RESET, entry->d_name);
    }
    closedir(dir);

    return 0;
}