#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../colours.h"

int *allocateIntArray(int n)
{
	int *arr = (int *)malloc(n * sizeof(int));
	if (arr == NULL)
	{
		printf(F_BOLD F_T_RED "Memory allocation failed\n" F_RESET);
		exit(EXIT_FAILURE);
	}
	return arr;
}
void findWaitingTime(int n, int *bt, int *wt, int quantum)
{
	bool done = false;
	int *rem_bt = allocateIntArray(n);
	for (int i = 0; i < n; i++)
		rem_bt[i] = bt[i];
	int t = 0;
	while (!done)
	{
		done = true;
		for (int i = 0; i < n; i++)
		{
			if (rem_bt[i] > 0)
			{
				done = false;
				if (rem_bt[i] > quantum)
				{
					t += quantum;
					rem_bt[i] -= quantum;
				}
				else
				{
					t = t + rem_bt[i];
					wt[i] = t - bt[i];
					rem_bt[i] = 0;
				}
			}
		}
	}
}
void findTurnAroundTime(int n, int *bt, int *wt, int *tat)
{
	for (int i = 0; i < n; i++)
		tat[i] = bt[i] + wt[i];
}
void findavgTime(int n, int *bt, int quantum)
{
	int *wt = allocateIntArray(n), *tat = allocateIntArray(n), total_wt = 0, total_tat = 0;
	findWaitingTime(n, bt, wt, quantum);
	findTurnAroundTime(n, bt, wt, tat);
	printf(F_BOLD F_RVID "+----+-----+-----+-----+\n" F_RESET);
	printf(F_BOLD F_RVID "| PN |  BT |  WT | TAT |\n" F_RESET);
	printf(F_BOLD F_RVID "+----+-----+-----+-----+\n" F_RESET);
	for (int i = 0; i < n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		printf(F_RVID "| %2d | %3d | %3d | %3d |\n" F_RESET, i + 1, bt[i], wt[i], tat[i]);
	}
	printf(F_RVID "+----+-----+-----+-----+\n" F_RESET);
	printf("Average waiting time = %f\n", (float)total_wt / (float)n);
	printf("Average turn around time = %f\n", (float)total_tat / (float)n);
	free(wt);
	free(tat);
}
int main()
{
	int *burst_time, quantum, n;
	printf("Number of processes : ");
	scanf("%d", &n);
	burst_time = allocateIntArray(n);
	for (int i = 0; i < n; i++)
	{
		printf("Burst time of process %d : ", i + 1);
		scanf("%d", &burst_time[i]);
	}
	printf("Time Quantum : ");
	scanf("%d", &quantum);
	findavgTime(n, burst_time, quantum);
	free(burst_time);
	return 0;
}
