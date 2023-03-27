#include <stdio.h>
#include "process.h"
void swap(Process *p, int a, int b)
{
    Process tmp = p[a];
    p[a] = p[b];
    p[b] = tmp;
}
void sort(int n, Process *p)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        for (j = 0; j < n - i - 1; j++)
            if (p[j].at > p[j + 1].at)
                swap(p, j, j + 1);
}
void readPriority(int n, Process *p)
{
    for (int i = 0; i < n; i++)
    {
        while (p[i].priority <= 0 || p[i].priority >= 10)
        {
            printf("priority of process %d : ", p[i].pid);
            scanf("%d", &p[i].priority);
        }
    }
}

void start(int n, Process *p)
{
    readPriority(n, p);
    sort(n, p);
    int time = p[0].at;
    int completed = 0;
    int selected_process = -1;

    while (completed < n)
    {
        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= time && p[i].rem_bt > 0)
            {
                if (selected_process == -1 || p[i].priority < p[selected_process].priority)
                {
                    selected_process = i;
                }
            }
        }
        if (selected_process == -1)
        {
            time++;
            continue;
        }
        p[selected_process].rem_bt--;
        if (p[selected_process].rem_bt == 0)
        {
            completed++;
            p[selected_process].ct = time + 1;
        }
        time++;
        selected_process = -1;
    }
}
