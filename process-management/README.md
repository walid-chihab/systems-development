Exercice 1
Implémenter et exécuter le programme suivant. Commenter le résultat obtenu.
#include<stdio.h>
#include<stdlib.h>
main(){
int pid;
pid=fork();
if(pid==-1){
perror("fork");
exit(0);
}
if(pid==0){
printf("c’est le Fils \n");
}
else{
printf("c’est le Père \n");
}
}
Exercice 2
Variables d’environnement héritages.
Tester le programme suivant et Commenter le résultat obtenu.
#include<stdio.h>
#include<stdlib.h>
int main()
int pid,n=0;
pid=fork();
if(pid==-1){
perror("fork");
exit(0);
}
if (pid==0){

1

n=n+2;
printf("Fils n=%d \n",n);
}
else {
n=n+3;
printf("Père n=%d \n",n);
}
return 0; }
Exercice 3
Implémenter le programme suivant. Commenter le résultat obtenu.
#include<stdio.h>
#include<stdlib.h>
int main()
int pid,n=0;
pid=fork();
if(pid==-1){
perror("fork");
exit(0);
}
if (pid==0){
n=n+2;
printf("Fils n=%d \n",n);
}
else {
n=n+3;
printf("Père n=%d \n",n);
}
n=n+1;
printf("n=%d \n",n);
return 0
}
Exercice 4
Ecrire le programme C qui permet d’avoir l’affichage suivant:
Fils : 2 4 6 8 10 12 ........ 100
Père : 3 6 9 12 15 18 ........ 99
Appel système : fork(), perror()