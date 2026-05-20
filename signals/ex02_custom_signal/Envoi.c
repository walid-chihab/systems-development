#include <stdio.h>// printf
#include <stdlib.h>// atoi
#include <signal.h>// signal
#include <unistd.h> // getpid

// Programme qui envoie un signal à un processus spécifié
int main (int argc, char *argv[]){

    // Vérification des arguments
    if(argc != 3 )
    {
        printf ("usage : %s <pid> <num_signal>\n",argv[0]);
        return 1;
    }

    int pid = atoi (argv[1]); // Récupération du PID du processus cible
    int sig = atoi (argv[2]); // Récupération du numéro du signal

    // Envoi du signal au processus cible
    // pour kill 0 succes , -1 erreur
    if(kill(pid, sig) == -1)
    {
        perror("Erreur lors de l'envoi du signal");
        return 1;
    }
    else
    {
        printf("Signal envoyé avec succès\n");
    }

    return 0;
}