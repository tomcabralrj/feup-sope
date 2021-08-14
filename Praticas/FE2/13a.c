#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



int main(){
    int pipes[2];
    int pid;
    char msg[25];

    if(pipe(pipes) == -1) { perror("pipes():");}
    if((pid=fork()) == -1){ perror("fork():");}
    if(pid != 0){
        close(pipes[0]);
        write(pipes[1], "Operation ", 1+strlen("Operation "));
        close(pipes[1]);
    }else{
        close(pipes[1]);
        read(pipes[0], msg, 1+strlen("Operation "));
        strcat(msg, "System!\n");
        close(pipes[0]);
    }
    printf("%s", msg);

    return 0;
}