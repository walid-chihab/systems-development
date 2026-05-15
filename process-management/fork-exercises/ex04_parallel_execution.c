/* ex04_parallel_execution.c */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
int main(){
    pid_t pid;
    
    pid=fork();
    if(pid==-1){
        perror("fork");
        exit(0);
    }
    if (pid==0){
        for (int i=0; i<101; i+=2){
            printf("%d ,",i);
        }
        printf ("\n le fils a terminé d'afficher les nombres paire \n");
    }
    else {
        wait(NULL);
        for(int i=1; i<100; i+=2){
            printf("%d ,",i);
        }
        printf ("\n le père a terminé d'afficher les nombres impaire \n");
        printf("ma3lina hayd 3lia \n");
    }
    
    return 0;
} 