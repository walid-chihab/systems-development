/* P1.c */

#include"semaphore.h"// #include"sem.h" 
#define key1 200 //
int main(){ 
    // S est un sémaphore binaire, initialisé à 0
    int S,n=0;

    // Créer le sémaphore S avec la clé key1 
    S=CREAT_SEM(key1);

    do{ 
        n=n+2;
        printf("%d\t", n);
    }while(n%5!=0);

    // V(S) : libérer le sémaphore S
    V(S);
    return 0;
}