#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>
int main()
{
    char *shared_memory = shmat(shmget((key_t)2348, 1024, 0666 | IPC_CREAT), NULL, 0);
    printf("Process Attached At : %p\n\n", shared_memory);
    printf("Enter Some Data To Write To Shared Memory\n\n");  
    getchar();
    scanf("%s", shared_memory);
}
