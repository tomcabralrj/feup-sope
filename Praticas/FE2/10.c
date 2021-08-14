#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>

#define NTHREADS 2


typedef struct{
    int argc;
    char** argv;
    bool passed; 
}threads_output;

typedef struct{
    int order; 
    threads_output* outString;
}thread_info;

void *rot(void *a){
    thread_info result = *(thread_info*)a;
    if(result.order == 0){
        if(result.outString->argc > 1){
            printf("%s ", result.outString->argv[1]);
            fflush(stdout);
            sleep(3);
        }
        result.outString->passed = true;
    }else{
        while(!(result.outString->passed));
        if(result.outString->argc > 2){
            for(int i=2; i<result.outString->argc; i++){
                printf("%s ", result.outString->argv[i]);
                fflush(stdout);
                sleep(3);
            }
        }
    }
    pthread_exit(NULL);
}



int main(int argc, char* argv[]){
    int i;
    pthread_t ids[NTHREADS];
    setbuf (stdout, NULL);

    threads_output* values = malloc(sizeof(threads_output));
    values->argc = argc;
    values->argv = argv;
    values->passed = false;

    for(i=0; i<NTHREADS; i++) {
        thread_info* info = malloc(sizeof(thread_info));
        info->order = i;
        info->outString = values;
		if (pthread_create(&ids[i], NULL, rot, info) != 0){
			exit(-1);	// here, we decided to end process
        }
	}
	// wait for finishing of created threads
	for(i=0; i<NTHREADS; i++) {
        void* returnValue;
		pthread_join(ids[i], &returnValue);	// Note: threads give no termination code
	}
    printf("\n");

    return 0;
}