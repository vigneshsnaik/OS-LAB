#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../colours.h"
#include "process.h"

int min(int a, int b)
{
    return (a > b ? b : a);
}

void fcfs(Process *p, int n)
{
    int time = 0, cur_pTime;

    for (int i = 0; i < n; i++)
    {

        time += p[i].bt;
        p[i].ct = time;
    }
    for (int i = 0; i < n; i++)
    {
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
    }
}

int main()
{
    int n;
    Process *p;
    printf("Number of processes : ");
    scanf("%d", &n);

    p = (Process *)malloc(n * sizeof(Process));
    if (p == NULL)
    {
        printf(F_BOLD F_T_RED "Memory allocation failed\n" F_RESET);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++)
    {
        printf("burstTime");
        scanf("%d", &p[i].bt);
        p[i].pid = i + 1;
    }
    fcfs(p, n);
    printProcessTable(n, p);
    findavgTime(n, p);
    return 0;
}
