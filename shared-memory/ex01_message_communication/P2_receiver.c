/* P2_receiver.c */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    //il faut la meme clee que p1 (tres important )
    key_t key = 1234;

    //recuperer la memoire partager par p1
    int shmid = shmget(key ,1024, 0666);

    //attacher la memoire au processus p2
    char *msg = (char *) shmat(shmid , NULL , 0) ;

    //afficher le message recu 
    printf("p2 a recu : %s\n " ,msg);

    // // convertir en majuscules
    for (int i = 0; msg[i] != '\0'; i++) {
        msg[i] = toupper(msg[i]);
    }

    // afficher en majuscules
    printf("P2 en majuscules : %s\n", msg);

     // détacher la mémoire
    shmdt(msg);

    // // supprimer la mémoire (important à la fin)
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}