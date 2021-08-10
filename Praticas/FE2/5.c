#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    int pid = fork();

    if(pid == -1){
        fprintf(stderr, "Child is not created!");
    }else if(pid == 0){
        fprintf(stdout, "Hello\n");
    }else{
        wait(NULL);
        fprintf(stdout, "World!\n");
    }


    return 0;
}