#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main (int argc, char *argv[ ], char *envp[ ]) {
    if(argc != 2){
        printf("Invalid arguments!\n");
    }
    int fd = open(argv[1], O_RDWR);
    if(fd == -1){
        perror("Error:");
    }
    return 0;
}