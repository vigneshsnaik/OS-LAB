#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../colours.h"
#include "process.h"

int min(int a, int b)
{
	return (a > b ? b : a);
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
void startProcess(Process *p, int n, int q)
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
void printProcessTable(int n, Process *p)
{

	// PRINT TABLE
	printf(F_BOLD F_RVID "+----+-----+-----+-----+-----+\n" F_RESET);
	printf(F_BOLD F_RVID "| PN |  BT |  WT | TAT |  CT |\n" F_RESET);
	printf(F_BOLD F_RVID "+----+-----+-----+-----+-----+\n" F_RESET);
	for (int i = 0; i < n; i++)
	{
		printf(F_RVID "| %2d | %3d | %3d | %3d | %3d |\n" F_RESET, p[i].pid, p[i].bt, p[i].wt, p[i].tat, p[i].ct);
	}
	printf(F_RVID "+----+-----+-----+-----+-----+\n" F_RESET);
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
	startProcess(p, n, quantum);
	printProcessTable(n, p);
	findavgTime(n, p);
	return 0;
}
