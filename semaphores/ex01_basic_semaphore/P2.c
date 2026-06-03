/* P2.c */

#include"semaphore.h"
#define key1 200
intmain(){
    int S, n=0;
    S=CREAT_SEM(key1);
    // Initialiser le sémaphore S à 0
    INIT_SEM(S,0);
    // P(S) : attendre que le sémaphore S soit libéré
    P(S);
    do{ 
        n=n+3;
        printf("%d\t", n);
    }while(n%5!=0);
    // c pas grave de preparer n pour le p2 , car son deux processus separer chaqun a sa propre variable n
    return 0;
}