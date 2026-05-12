#include <stdio.h>      // pour printf
#include <unistd.h>     // pour fork()
#include <sys/wait.h>   // pour wait()

int main() {
    pid_t pid;  // variable pour stocker l'ID du processus créé

    pid = fork();  // crée un processus fils

    if (pid < 0) {
        // erreur lors de la création du fils
        perror("Erreur lors de fork");
        return 1;
    }
    else if (pid == 0) {
        // code exécuté par le processus fils
        printf("Je suis le fils\n");
    }
    else { 
        // le père attend la fin du fils pour éviter zombie
        wait(NULL);
        printf("Le fils a terminé\n");
    }

    return 0;
}
