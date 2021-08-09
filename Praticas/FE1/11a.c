#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[ ]){
    if(argc != 3){
        fprintf(stderr,"Arguments invalid!");
        exit(0);
    }
    void *buffer = malloc(sizeof(char));
    int fn1, fn2, ch;
    fn1 = open(argv[1], O_RDONLY);
    if(fn1 == -1){
        perror("Error:");
    }
    fn2 = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT);
    if(fn2 == -1){
        perror("Error:");
    }
    while((ch = read(fn1, buffer, 1)) == 1){
        write(fn2, buffer, 1);
    }
    close(fn1);
    close(fn2);
    
    return 0;


}