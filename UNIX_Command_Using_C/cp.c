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
        printf(F_T_RED "Usage:" F_BOLD " cp source_file destination_file\n" F_RESET);
        exit(EXIT_FAILURE);
    }

    int src;
    if ((src = open(args[1], O_RDONLY)) == -1)
    {
        printf(F_DIM F_T_RED "Cannot open the source file\n" F_RESET);
        exit(EXIT_FAILURE);
    }
    printf(F_DIM F_T_GRN "%s Opened successfully\n" F_RESET, args[1]);

    int dest;
    if ((dest = open(args[2], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR)) == -1)
    {
        printf(F_DIM F_T_RED "Cannot open the destination file\n" F_RESET);
        exit(EXIT_FAILURE);
    }
    printf(F_DIM F_T_GRN "%s Opened successfully\n" F_RESET, args[2]);

    char buffer[BUFFER_SIZE];
    ssize_t readBytes, writeBytes;
    while ((readBytes = read(src, buffer, sizeof(buffer))) > 0)
    {
        writeBytes = write(dest, buffer, readBytes);
        if (readBytes != writeBytes)
        {
            printf(F_T_RED "Cannot copy the file" F_RESET);
            exit(EXIT_FAILURE);
        }
    }
    printf(F_BOLD F_T_GRN "%s copied to %s successfully\n" F_RESET, args[1], args[2]);
    close(src);
    close(dest);
}