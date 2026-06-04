/* semaphore.h */

/* semaphore.h */

#include<stdio.h>
#include<stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
union semun {
/* Value for SETVAL */
int val;
/* Buffer for IPC_STAT, IPC_SET */
struct semid_ds *buf;
/* Array for GETALL, SETALL */
unsigned short *array;
/* Buffer for IPC_INFO */
struct seminfo *__buf;
};

int CREAT_SEM(int key);
void INIT_SEM(int ids,int valeur);
void P(int ids);
void V(int ids);// pas encore a comprendre 