#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>


void message(int signo) {
    fprintf(stdout, " World!\n");
}



int main(){

    

    pid_t pid = fork();

    if(pid == -1){
        return 2;
    }
    if(pid == 0){
        //Child Process
        printf("Hello");
        fflush(stdout);
        sleep(3);
        kill(getppid(), SIGUSR1);
    }else{
        //Parent Process
        struct sigaction new, old;
        sigset_t smask;
        if (sigemptyset(&smask)==-1){	// block no signal
            perror ("sigsetfunctions");
        }
        new.sa_handler = message;
        new.sa_mask = smask;
        new.sa_flags = 0;	// usually works

        if(sigaction(SIGUSR1, &new, &old) == -1){
            perror ("sigaction");
        }  
        pause();	// wait
    }

    return 0;
}