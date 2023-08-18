#include <stdio.h>
/*Crie um programa em linguagem C que recebe um número e imprime no console:

0 - se o número não for primo;

1 - se o número for primo.*/

int verifica_num_primo( int numero){
    int numero, i, resultado = 0;
    for (i = 2; i <= numero / 2; i++) {
    if (numero % i == 0) {
       resultado++;
       break;
    }
 }
 
 if (resultado == 0)
    printf("1");
 else
    printf("0");
}

int  main (int argc, char* argv[]){
    printf("\n %d ",verifica_num_primo(atoi(argv[1])));
}




