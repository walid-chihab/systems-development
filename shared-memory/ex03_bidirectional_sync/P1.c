/* P1.c */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <signal.h>

/*
    Handler vide.

    Quand P2 envoie SIGUSR1,
    ce handler est exécuté puis
    pause() se débloque.

    On n'a rien à faire dans le handler.
*/
void reveil(int sig)
{
}

int main()
{
    int shmid;
    int *N;
    int pidP2;

    key_t key = 1234;

    shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);

    N = (int *) shmat(shmid, NULL, 0);

    /*
        P1 initialise la valeur de départ.

        Comme c'est P1 qui commence,
        le premier nombre à afficher est 2.
    */
    *N = 2;

    // On installe le handler pour SIGUSR1, le signal que P2 enverra à P1 pour lui rendre la main, et qui réveillera P1 de son paus.
    signal(SIGUSR1, reveil);

    // pour on peut connu a qui envoyer le signale.
    printf("PID de P2 : ");
    scanf("%d", &pidP2);

    // boucle infinie de travail.
    while(1)
    {
        printf("P1 : ");

       
        for(int i = 0 ; i < 5 ; i++)
        {
            printf("%d ", *N);

            *N = *N + 2;
        }

        printf("\n");

        /*
            ATTENTION : partie importante.

            Après le dernier affichage : 2 4 6 8 10,la boucle a déjà ajouté 2.Donc N vaut maintenant:12 mais on va faire le depart de 13 dans p2
        */
        *N = *N + 1;

       //le kill est utilisé pour envoyer un signal à un processus. Ici, P1 utilise kill pour envoyer le signal SIGUSR1 à P2,
        kill(pidP2, SIGUSR1);

        /*
            P1 sera blocker , Il restera endormi jusqu'à ce que P2 lui rende la main.
        */
        pause();
    }

    return 0;
}