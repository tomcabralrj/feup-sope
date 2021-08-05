#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[ ], char *envp[ ]){
    const char* s;
    printf("Enviroment variables of arguments:\n");
    for (int i=1; i<argc; i++)
    {
        s = getenv(argv[i]);
        printf("%s = %s\n",argv[i], (s!=NULL)? s : "getenv returned NULL");
    }

    return 0;
}