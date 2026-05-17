/* ignore_sigint.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[]){//
    if (argc != 2) {//
        printf("Usage : %s <secondes>\n", argv[0]);//
        return 1; //
    }

    int secondes = atoi(argv[1]);// Convertir l'argument en entier  
    
    signal (SIGINT, SIG_IGN);
    
    sleep (secondes);

    signal (SIGINT, SIG_DFL);

     while (1) ;// Attente infinie pour tester le comportement après avoir rétabli le signal par défaut

    return 0;
    //si vous appuyez sur Ctrl+C pendant l'exécution du programme, il ignorera le signal SIGINT pendant la période.
    //apres la period de someile,si vous appuyez à nouveau sur Ctrl+C, le programme se terminera normalement car le signal SIGINT aura été rétabli à son comportement par défaut.
}
