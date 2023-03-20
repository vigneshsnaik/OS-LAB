#include <stdio.h>
#include <stdbool.h>
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
int min(int a, int b)
{
	return (a > b ? b : a);
}

void roundRobin(Process *p, int n)
{
	sort(p, n);
	int q;
	printf("Time Quantum : ");
	scanf("%d", &q);
	int time = 0, cur_pTime;
	bool done = false;
	while (!done)
	{
		done = true;
		for (int i = 0; i < n; i++)
		{
			if (p[i].rem_bt)
			{
				done = false;
				cur_pTime = min(p[i].rem_bt, q);
				p[i].rem_bt -= cur_pTime;
				time += cur_pTime;
				if (!p[i].rem_bt)
					p[i].ct = time;
			}
		}
	}
}

int main()
{
	int n;
	printf("Number of processes : ");
	scanf("%d", &n);
	Process *p = newProcess(n);
	roundRobin(p, n);
	printProcessTable(n, p);
	findavgTime(n, p);
	return 0;
}
