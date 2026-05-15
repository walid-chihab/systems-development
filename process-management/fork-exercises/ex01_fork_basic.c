#include<stdio.h>//printf
#include<stdlib.h>//exit
#include<unistd.h>//fork
#include<sys/types.h>//pid_t

int main(){
    pid_t pid;
    pid=fork();
    if(pid==-1){
        perror("fork");
        exit(1);
    }
     
    if(pid==0){
        printf("cest le Fils \n");
    }
    else{
        printf("cest le Père \n");
    }
    return 0;
}