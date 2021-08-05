#include <stdio.h>

int main(int argc, char *argv[ ], char *envp[ ]){

    printf("Command line arguments:\n");
    for(int i=1; i<argc; i++){
        printf("%s\n", argv[i]);
    }

    printf("Enviroment arguments:\n");
    for (char **env = envp; *env != 0; env++)
    {
        char *thisEnv = *env;
        printf("%s\n", thisEnv);    
    }

    return 0;
}