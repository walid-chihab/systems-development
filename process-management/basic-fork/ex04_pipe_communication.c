/* ex04_pipe_communication.c */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    // 🔵 PÈRE et 🟢 FILS communiquent via un pipe

    //tableau de 2 entiers pour les descripteurs du pipe
    int fd[2];
    // créer le pipe
    pipe(fd);

    // créer un processus fils
    pid_t pid = fork();

    // PÈRE écrit dans le pipe, 
    if (pid > 0) {
        // PÈRE (écrit)
        close(fd[0]); // ne lit pas 

        // message à envoyer au fils
        char msg[] = "Bonjour fils";

        // écrire le message dans le pipe
        write(fd[1], msg, strlen(msg) + 1);

        // fermer le descripteur d'écriture
        close(fd[1]);
    }
    else {
        //  FILS (lit)

        close(fd[1]); // ne écrit pas

        // buffer pour lire le message
        char buffer[100];

        // lire le message du pipe
        // n = nombre de bytes lus (utile pour ajouter le \0 à la fin du message)
        int n = read(fd[0], buffer, sizeof(buffer));

        buffer[n] = '\0'; // buffer doit être une chaîne de caractères valide

        // afficher le message reçu
        printf("Message reçu : %s\n", buffer);

        // fermer le descripteur de lecture
        close(fd[0]);
    }

    //  nous avons pas traitter "attendre le fils pour éviter un processus zombie"
    return 0;
}