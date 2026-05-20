#include <stdio.h>// printf 
#include <stdlib.h>// atoi
#include <signal.h>// signal
#include <unistd.h> // getpid

// Handler de signal qui affiche le signal reçu
void handler(int sig)
{
    printf("Signal reçu : %d\n", sig);
}

// Programme qui attend un signal et affiche son numéro
int main(int argc, char *argv[])
{
    // Vérification des arguments
    if(argc != 2)
    {
        printf("usage : %s <signal>\n", argv[0]);
        return 1;
    }

    // Récupération du signal à attendre sous forme d'entier
    int sig = atoi(argv[1]);

    // l'appel de signal() pour associer le handler au signal spécifié 
    signal(sig, handler);

    // Affichage du PID pour permettre d'envoyer un signal depuis un autre terminal
    printf("PID : %d\n", getpid());

    // Affichage d'un message pour indiquer que le programme est prêt à recevoir des signaux
    printf("En attente de signal...\n");

    // Boucle infinie pour attendre les signaux
    while(1);
        pause(); // pour mas consomme 100% CPU, pause() met le processus en sommeil jusqu'à ce qu'un signal soit reçu


        
    return 0;
}