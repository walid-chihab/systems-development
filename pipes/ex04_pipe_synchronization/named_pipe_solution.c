#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int tube1[2]; // père -> fils
    int tube2[2]; // fils -> père

    // création des deux tubes
    pipe(tube1);
    pipe(tube2);

    // création du fils
    pid_t pid = fork();

    // ================= FILS =================
    if(pid == 0)
    {
        // le fils lit depuis tube1
        close(tube1[1]);

        // le fils écrit dans tube2
        close(tube2[0]);

        char c;   // caractère de synchronisation
        int n = 2;

        while(n <= 100)
        {
            // attendre le signal du père
            read(tube1[0], &c, 1);

            printf("Fils : ");

            // afficher 5 nombres pairs
            for(int i = 0; i < 5 && n <= 100; i++)
            {
                printf("%d ", n);
                n += 2;
            }

            printf("\n");

            // réveiller le père
            write(tube2[1], "x", 1);
        }

        // fermeture des tubes
        close(tube1[0]);
        close(tube2[1]);
    }

    // ================= PERE =================
    else
    {
        // le père écrit dans tube1
        close(tube1[0]);

        // le père lit depuis tube2
        close(tube2[1]);

        char c;   // caractère de synchronisation
        int n = 13;

        // démarrer le fils
        write(tube1[1], "x", 1);

        while(n <= 100)
        {
            // attendre le fils
            read(tube2[0], &c, 1);

            printf("Père : ");

            // afficher 5 nombres (+3)
            for(int i = 0; i < 5 && n <= 100; i++)
            {
                printf("%d ", n);
                n += 3;
            }

            printf("\n");

            // réveiller le fils
            write(tube1[1], "x", 1);
        }

        // fermeture des tubes
        close(tube1[1]);
        close(tube2[0]);

        // attendre la fin du fils
        wait(NULL);
    }

    return 0;
}