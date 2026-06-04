/* P2.c */

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>
#include"semaphore.h"
#define keyS1 200 // pour le semaphores S1
#define keyS2 300 // pour le semaphores S2
#define keyM 120 // pour la memoire partagee

main(){
    //idm : identifiant de la memoire partagee
    //N : pointeur vers la memoire partagee
    //S1 : identifiant du semaphores S1
    //S2 : identifiant du semaphores S2
    int idm, *N, S1, S2;

    idm=shmget(keyM,sizeof(int),IPC_CREAT|0666);
    if(idm==-1){
        perror("shmget");
        exit(0);
    }
    N=(int*)shmat(idm,0,0);
    S1=CREAT_SEM(keyS1);
    S2=CREAT_SEM(keyS2);
    // initialisation du semaphores S2 a 0
    INIT_SEM(S2,0);
    // p(s2)permet de bloquer le processus P2 jusqu'a ce que le processus P1 fasse un V(S2)
    P(S2);
    while (*N <= 100)
    {
        do {
            *N=*N+3;
            printf(" %d",*N);
        } while (*N%5!=0);
    // reveiller p1
        V(S1);
        // le p2 dormire 
        P(S2);
        //
        printf("\n");
    }
    shmdt(N);
    shmctl(idm,IPC_RMID,0);
    return 0 ;
}   