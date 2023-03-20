#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../colours.h"
#include "process.h"
void swap(Process *p, int a, int b)
{
    Process tmp = p[a];
    p[a] = p[b];
    p[b] = tmp;
}
void sort(Process *p, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        for (j = 0; j < n - i - 1; j++)
            if (p[j].at > p[j + 1].at)
                swap(p, j, j + 1);
}
void fcfs(Process *p, int n)
{
    sort(p, n);
    int time = p[0].at;
    for (int i = 0; i < n; i++)
    {
        if (time < p[i].at)
            time = p[i].at;
        time += p[i].bt;
        p[i].ct = time;
    }
}

int main()
{
    int n;
    printf("Number of processes : ");
    scanf("%d", &n);

    Process *p = newProcess(n);
    fcfs(p, n);
    printProcessTable(n, p);
    findavgTime(n, p);
    return 0;
}
