#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../colours.h"
#include "process.h"

void fcfs(Process *p, int n)
{
    int time = 0;
    for (int i = 0; i < n; i++)
    {

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
