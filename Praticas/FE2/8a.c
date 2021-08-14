#include <stdio.h>
#include <unistd.h>
#include <signal.h>


void message(int signo) {
    fprintf(stdout, " Hello\n");
}



int main(){

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

    pid_t pid = fork();

    if(pid == -1){
        return 2;
    }
    if(pid == 0){
        //Child Process
        pause();	// wait
    }else{
        //Parent Process
        fprintf(stdout, "\nWorld:");
        kill(pid, SIGUSR1);
    }

    return 0;
}