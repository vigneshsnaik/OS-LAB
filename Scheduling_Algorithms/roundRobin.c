#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../colours.h"
#include "process.h"

int min(int a, int b)
{
	return (a > b ? b : a);
}

void roundRobin(Process *p, int n, int q)
{
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
	for (int i = 0; i < n; i++)
	{
		p[i].tat = p[i].ct - p[i].at;
		p[i].wt = p[i].tat - p[i].bt;
	}
}


int main()
{
	int quantum, n;
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
		p[i].rem_bt = p[i].bt;
		p[i].pid = i + 1;
	}
	printf("Time Quantum : ");
	scanf("%d", &quantum);
	roundRobin(p, n, quantum);
	printProcessTable(n, p);
	findavgTime(n, p);
	return 0;
}
