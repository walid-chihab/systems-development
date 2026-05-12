#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    pid_t pid;
    pid = fork();

    if (pid < 0) {

        perror("Erreur lors du fork");
        return 1;

    } else if (pid == 0) {

        // processus fils
        sleep(2);
        printf("Je suis le fils\n");

    } else {

        // processus père
        printf("Je suis le pere\n");

        // attendre le fils pour éviter un zombie
        wait(NULL);
    }

    return 0;
}