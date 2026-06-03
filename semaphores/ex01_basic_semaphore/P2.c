/* P2.c */

#include"semaphore.h"
#define key1 200
main(){
int S, n=0;
S=CREAT_SEM(key1);
INIT_SEM(S,0);
P(S);
do{ n=n+3;
printf("%d\t", n);
}while(n%5!=0);
}