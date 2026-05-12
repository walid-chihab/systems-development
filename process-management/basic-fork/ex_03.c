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

        printf("Je suis le fils\n");
        printf ("mon PID est : %d \n ",getpid());
        printf ("mon pere PID est : %d \n ",getppid());

    } else {
    
        printf("Je suis le pere\n");
        printf  ("mon PID est : %d \n",getpid() );
        printf ("mon pere PID est : %d \n ",getppid ());
        printf ("Pid de mon fils est : %d \n ",pid );
        // attendre le fils pour éviter un zombie
        wait(NULL);
    }

    return 0;
}