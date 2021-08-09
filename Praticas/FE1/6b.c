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
        dup2(STDERR_FILENO, STDOUT_FILENO);
        printf("Error: %s\n", strerror(errno));
    }
    return 0;
}