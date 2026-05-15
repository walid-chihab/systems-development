/* ex02_variable_inheritance.c */
#include<stdio.h>//printf
#include<stdlib.h>//exit
#include<unistd.h>//fork
#include<sys/types.h>//pid_t
 int main(){
    pid_t pid;
    int n=0;
    pid=fork();
    if(pid==-1){
        perror("fork");
        exit(0);//exit with error code
    }
    if (pid==0){
        n=n+2;
        printf("Fils n=%d \n",n);
    }
    else {
        n=n+3;
        printf("Père n=%d \n",n);
    }
    return 0;
 }