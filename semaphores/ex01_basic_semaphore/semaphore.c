/* semaphore.c */

#include "semaphore.h"
int CREAT_SEM(int key)
{int ids;
ids=semget(key,1,IPC_CREAT|0777);
return ids;
}
void INIT_SEM(int ids,int valeur)
{
union semun ctl;
ctl.val=valeur;
semctl(ids,0,SETVAL,ctl);
}
void P(int ids)
{
struct sembuf arg;
arg.sem_num=0;
arg.sem_op=-1;
arg.sem_flg=SEM_UNDO;
semop(ids,&arg,1);
}
void V(int ids){
struct sembuf arg;
arg.sem_num=0;
arg.sem_op=1;
arg.sem_flg=SEM_UNDO;
semop(ids,&arg,1);
}