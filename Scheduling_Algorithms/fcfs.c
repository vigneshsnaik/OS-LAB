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
void start(int n, Process *p)
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
