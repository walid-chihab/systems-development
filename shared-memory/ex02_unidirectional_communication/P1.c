/* P1.c */

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
    key_t key = 1234;

    // création mémoire partagée pour un entier
    int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);

    // attachement
    int *num = (int *) shmat(shmid, NULL, 0);

    *num = 0;

    printf("P1 : ");

    for (int i = 0; i < 5; i++)
    {
        *num += 2;
        printf("%d ", *num);
    }

    printf("\n");

    // détacher mémoire
    shmdt(num);

    return 0;
}
