/* P1.c */

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>
#include"semaphore.h"
#define keyS1 200
#define keyS2 300
#define keyM 120

main(){
    int idm, *N, S1, S2;
    //idm : identifiant de la memoire partagee, N : pointeur vers la memoire partagee, S1 : identifiant du semaphores S1, S2 : identifiant du semaphores S2
    idm=shmget(keyM,sizeof(int),IPC_CREAT|0666);
    if(idm==-1)
    {
        perror("shmget");
        exit(0);
    }
    //N est un pointeur vers la memoire partagee
    N=(int*)shmat(idm,0,0);
    S1=CREAT_SEM(keyS1);
    S2=CREAT_SEM(keyS2);
    INIT_SEM(S1,0);
    INIT_SEM(S2,0);
    *N=0;
    while (*N<= 100)
    {
        do {
            *N=*N+2;
            printf(" %d",*N);
        } while (*N%5!=0);
        // reveiller p2
        V(S2);
        // le p1 dormire
        P(S1);
        printf("\n");
    }
    shmdt(N);
    return 0 ;
}