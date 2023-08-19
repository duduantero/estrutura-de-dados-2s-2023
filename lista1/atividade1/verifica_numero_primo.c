#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    int numero, i;

    numero = atoi(argv[1]);

    if(numero <= 1){
        printf("0");
    }else{
        for(i=3; i < numero; i+=2){
            if(numero%i==0){
                printf("0");
                break;
            }
        }
        if(i==numero){
            printf("1");
        }
    }

    return 0;
}


