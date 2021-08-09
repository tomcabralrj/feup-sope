#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if(argc != 3){
        fprintf(stderr, "Argument invalid!");
        return 1;
    }
    FILE * fn1;
    FILE * fn2;

    fn1 = fopen(argv[1], "r");
    fn2 = fopen(argv[2], "w");
    int ch; 
    while(1){
        ch = fgetc(fn1);
        if(feof(fn1)){
            break;
        }
        fputc(ch, fn2);
    }
    fclose(fn1);
    fclose(fn2);
    return 0;

}