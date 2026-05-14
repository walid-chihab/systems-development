/* ex05_multiple_children.c */

#include <stdio.h>
#include <unistd.h>     // fork, sleep, getpid
#include <sys/wait.h>   // wait
#include <stdlib.h>     // exit

int main() {
    pid_t pid1, pid2;

    // Création du premier fils
    pid1 = fork();
    if (pid1 < 0) {
        perror("Erreur fork1");
        // En cas d'erreur de fork, on affiche un message et on termine le programme
        exit(1);
    }

    if (pid1 == 0) {
        // Premier fils
        printf("FILS 1 (PID = %d) : je dors 2 secondes\n", getpid());
        sleep(2);
        // Après le sleep, le fils affiche son pid et se termine
        printf("FILS 1 (PID = %d) : réveillé\n", getpid());
        exit(0);// 0 en cas de succès, on termine le fils avec exit(0) pour indiquer que tout s'est bien passé
    }

    // Création du deuxième fils
    pid2 = fork();
    if (pid2 < 0) {
        perror("Erreur fork2");
        exit(1); //1 en cas d'erreur de fork, on affiche un message et on termine le programme
    }

    if (pid2 == 0) {
        // Deuxième fils
        printf("FILS 2 (PID = %d) : je dors 4 secondes\n", getpid());
        sleep(4);//4 secondes de sommeil pour le deuxième fils
        printf("FILS 2 (PID = %d) : réveillé\n", getpid());
        exit(0);
    }
    //chaque wait attend la fin d'un fils, le père affiche un message après chaque fils terminé
    // Père : attend ses deux fils (pas de sleep, wait suffit)
    printf("Père : j'attends la fin des deux fils...\n");
    wait(NULL);   // attend le premier fils terminé
    printf("Père : un fils est terminé\n");
    wait(NULL);   // attend le deuxième
    printf("Père : les deux fils ont terminé. Fin.\n");

    return 0;
}