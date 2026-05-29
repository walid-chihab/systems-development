/* P2.c */

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
    key_t key = 1234;

    // récupération mémoire
    int shmid = shmget(key, sizeof(int), 0666);

    // attachement
    int *num = (int *) shmat(shmid, NULL, 0);

    printf("P2 : ");

    for (int i = 0; i < 5; i++)
    {
        *num += 3;
        printf("%d ", *num);
    }

    printf("\n");

    // détacher
    shmdt(num);

    // suppression mémoire
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}