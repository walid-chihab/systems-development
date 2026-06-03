/* P1.c */

#include"semaphore.h"
#define key1 200
main(){
int S,n=0;

S=CREAT_SEM(key1);
do{ n=n+2;
printf("%d\t", n);
}while(n%5!=0);

V(S);

}