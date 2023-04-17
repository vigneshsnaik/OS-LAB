#ifndef MEMPROCESSES_H
#define MEMPROCESSES_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../colours.h"

typedef struct
{
    int req_mem;
    bool allocated;
    int block;
} Process;
typedef struct
{
    int mem_size;
    bool allocated;
    int blockid;
} Block;
void allocate(int np, Process *p, int nb, Block *b);
void allocatedInfo(int np, Process *p, int nb, Block *b)
{
    printf(F_BOLD F_RVID "+---------+-----------+-----------------+\n" F_RESET);
    printf(F_BOLD F_RVID "| Process | allocated | allocated block |\n" F_RESET);
    printf(F_BOLD F_RVID "+---------+-----------+-----------------+\n" F_RESET);
    for (int i = 0; i < np; i++)
    {
        printf(F_RVID "| %7d |", i);
        if (p[i].allocated)
            printf("      true | %15d |\n" F_RESET, p[i].block);
        else
            printf("     false |                 |\n" F_RESET);
    }
    printf(F_RVID "+---------+-----------+-----------------+\n" F_RESET);
}
Process *newProcess(int n)
{
    Process *p = (Process *)malloc(n * sizeof(Process));
    if (p == NULL)
    {
        printf(F_BOLD F_T_RED "Memory allocation failed\n" F_RESET);
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < n; i++)
    {
        printf("Memory of process %d :", i);
        scanf("%d", &p[i].req_mem);
        p[i].allocated = false;
    }
    return p;
}
Block *newBlock(int n)
{
    Block *b = (Block *)malloc(n * sizeof(Block));
    if (b == NULL)
    {
        printf(F_BOLD F_T_RED "Memory allocation failed\n" F_RESET);
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < n; i++)
    {
        printf("Memory of block %d :", i);
        scanf("%d", &b[i].mem_size);
        b[i].blockid=i;
        b[i].allocated = false;
    }
    return b;
}

int main()
{
    int np, nb;
    printf("Number of processes : ");
    scanf("%d", &np);
    printf("Number of blocks : ");
    scanf("%d", &nb);
    Process *p = newProcess(np);
    Block *b = newBlock(nb);
    allocate(np, p, nb, b);
    allocatedInfo(np, p, nb, b);
    return 0;
}

#endif /* MEMPROCESSES_H */
