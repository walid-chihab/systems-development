/* P1_sender.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(int argc, char *argv[]) {

    // vérifier si un message est passé en paramètre
    if (argc < 2) {
        printf("Usage: ./P1 <message>\n");
        exit(1);
    }
    key_t key = 1234 ;

    //creation du memoire partager 
    int  shmid = shmget( key , 1024 ,IPC_CREAT | 0666);

    //attacher au proccesus P1
     char *msg = (char *) shmat (shmid , NULL , 0);

     //copier le message passer en parametre dans la memoire partager 
     strcpy(msg ,argv[1]);

     //afficher la confirmation de l'envoi de messsage
     printf ("p1 envois : %s ", msg);

     //detacher la memoire 
     shmdt(msg);

     return 0;
     
}