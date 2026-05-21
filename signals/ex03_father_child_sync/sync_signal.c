#include <stdio.h>   // bibliothèque pour printf()
#include <stdlib.h>  // bibliothèque standard
#include <unistd.h>  // contient fork(), pause(), getppid()
#include <signal.h>  // contient signal(), kill(), SIGUSR1

// variable globale qui va stocker le PID du processus fils
pid_t pid_fils; // pid_t = type spécial pour les identifiants de processus (PID)


// fonction appelée quand un signal SIGUSR1 est reçu
void handler(int sig)
{
    // sig contient le numéro du signal reçu
    // ici on ne fait rien
    // le but est juste de réveiller pause()
}

int main()
{ 
    // associe le signal SIGUSR1 à la fonction handler
    // quand le processus reçoit SIGUSR1 -> handler() est exécuté
    signal(SIGUSR1, handler);

    // création d'un nouveau processus
    // fork() duplique le processus actuel
    pid_fils = fork();

    // si fork() retourne 0 -> on est dans le FILS
    if(pid_fils == 0)
    {
        // ----- CODE DU FILS -----

        // boucle des nombres pairs de 2 jusqu'à 100
        printf ("fils :");

        for(int i = 2; i <= 100; i += 2)
        {

             printf(" %d  ", i);

            // si le nombre est multiple de 10
            if(i % 10 == 0 && i != 100)// pour éviter d'envoyer un signal après le dernier nombre et fils pas dourmir
            {
                // envoie le signal SIGUSR1 au père
                // getppid() retourne le PID du père
                printf ("\nfils :");
                kill(getppid(), SIGUSR1);

                // le fils se bloque ici et attend un signal
                pause();
            }
            // affiche le nombre pair
        }
    }
    else
    {
        // ----- CODE DU PÈRE -----
        pause(); // le fils qui va créer le père va attendre ici jusqu'à recevoir un signal du fils pour commencer à afficher les multiples de 3
         printf ("pere :");

        // boucle des multiples de 3 de 3 jusqu'à 99
        for(int i = 3; i <= 99; i += 3)
        {
            // affiche le nombre
            printf(" %d  ", i);

            // si le nombre est multiple de 15 = 3 et 5
            if(i % 15 == 0  && i != 90) // pour éviter d'envoyer un signal après le dernier nombre et père pas dourmir
            {

                printf ("\npère :");

                // envoie un signal SIGUSR1 au fils
                kill(pid_fils, SIGUSR1);

                // le père attend ici jusqu'à recevoir un signal
                pause();
            }
             // affiche le nombre
        }


    }
    return 0;
}