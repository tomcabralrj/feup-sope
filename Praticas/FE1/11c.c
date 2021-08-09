#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[ ]){
    if(argc != 3){
        fprintf(stderr,"Arguments invalid!");
        return 1;
    }
    void *buffer = malloc(sizeof(char));
    int fn1, fn2, ch;
    fn1 = open(argv[1], O_RDONLY);
    if(fn1 == -1){
        perror("Error:");
    }
    if(argc > 2){
        fn2 = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT);
        if(fn2 == -1){
            perror("Error:");
        }
    }
    while((ch = read(fn1, buffer, 1)) == 1){
        if(argc > 2){
            write(fn2, buffer, 1);
        }else{
            printf("%c", ((char*)buffer)[0]);
        }
    }
    close(fn1);
    if(argc > 2){close(fn2);}
    
    return 0;


}