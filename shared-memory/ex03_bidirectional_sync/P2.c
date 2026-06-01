/* P2.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <signal.h>

void reveil(int sig)
{
}

int main()
{
    int shmid;
    int *N;
    int pidP1;

    key_t key = 1234;

    shmid = shmget(key, sizeof(int), 0666);

    N = (int *) shmat(shmid, NULL, 0);

    signal(SIGUSR1, reveil);

    printf("PID de P1 : ");
    scanf("%d", &pidP1);

    /*
        IMPORTANT

        P2 ne doit pas commencer.

        L'énoncé veut que P1 affiche
        la première ligne.

        Donc dès le début P2 attend.
    */
    pause();

    while(1)
    {
        printf("P2 : ");

        /*
            P2 possède maintenant la main.

            Il affiche 5 nombres de pas = 3 
            
        */
        for(int i = 0 ; i < 5 ; i++)
        {
            printf("%d ", *N);

            *N = *N + 3;
        }

        printf("\n");

        /*
            Partie importante.

        Donc N vaut :28, Mais P1 doit commencer à : 27
        Donc P2 doit faire : N = N - 1  , pour que P1 puisse commencer à 27.
        */
        *N = *N - 1;

        /*
            Maintenant N vaut 27.

            P1 pourra afficher :

            27 29 31 33 35
        */

        /*
            P2 rend la main à P1.
        */
        kill(pidP1, SIGUSR1);

        /*
            P2 s'endort.

            Il attendra le prochain signal
            envoyé par P1.
        */
        pause();
    }

    return 0;
}