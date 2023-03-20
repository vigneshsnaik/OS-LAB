#ifndef PROCESS_H
#define PROCESS_H

#include <stdio.h>
#include <stdlib.h>
#include "../colours.h"

typedef struct
{
    int at, pid, wt, bt, tat, rem_bt, ct;
} Process;

void calculateTime(int n, Process *p)
{
    for (int i = 0; i < n; i++)
    {
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
    }
}

void printProcessTable(int n, Process *p)
{
    calculateTime(n, p);
    printf(F_BOLD F_RVID "+-----+-----+-----+-----+-----+-----+\n" F_RESET);
    printf(F_BOLD F_RVID "| PID |  AT |  BT |  CT |  WT | TAT |\n" F_RESET);
    printf(F_BOLD F_RVID "+-----+-----+-----+-----+-----+-----+\n" F_RESET);
    for (int i = 0; i < n; i++)
    {
        printf(F_RVID "| %3d | %3d | %3d | %3d | %3d | %3d |\n" F_RESET, p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].wt, p[i].tat);
    }
    printf(F_RVID "+-----+-----+-----+-----+-----+-----+\n" F_RESET);
}

void findavgTime(int n, Process *p)
{
    float total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++)
    {
        total_tat += p[i].tat;
        total_wt += p[i].wt;
    }
    printf("Average waiting time = %f\n", (float)total_wt / (float)n);
    printf("Average turn around time = %f\n", (float)total_tat / (float)n);
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
        printf("PID burstTime arrivalTime");
        scanf("%d %d %d", &p[i].pid, &p[i].bt, &p[i].at);
        p[i].rem_bt = p[i].bt;
    }
    return p;
}

#endif /* PROCESS_H */
