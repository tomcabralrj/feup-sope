#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>


int main(){
    int np;
    char msg[25];
    int pid;
    if((pid = fork()) == -1){ perror("fork()");}
    if(pid != 0){
        if(mkfifo("output_13b", 0666) < 0){ perror("mkfifo");}
        while((np = open("output_13b.txt", O_WRONLY)) < 0);
        write(np, "Operating ", 10);
        close(np);
    }else{
        if(mkfifo("output_13b", 0666) < 0){ perror("mkfifo");}
        while((np = open("output_13b.txt", O_RDONLY)) < 0);
        read(np, msg, 25);
        strcat(msg, "System!\n");
        close(np);
    }

    printf("%s", msg);


    return 0;
}