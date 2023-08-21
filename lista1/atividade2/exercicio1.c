#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int soma_array(int array[4]){
    int total =0;
    for(int i =0; i<4;i++){
        total = total + array[i];
    }
    return total;
}


int main(int argc, char const *argv[])
{
    setlocale(LC_ALL,"Portuguese");
    int numero[4];
    int j =0;
    for (int i = 1; i < 5; i++){
        numero[j] = atoi(argv[i]);
        printf("%d - %d \n",i,numero[j]);
    }

    int resultado =soma_array(numero);
    printf("A soma dos elementos do array: %d",resultado);

    return 0;
}






/**
Exercício 1 - Soma dos elementos de um array. Escreva uma função que recebe um array de números inteiros e retorna a soma de todos os elementos;

Exemplo: soma_array([5, 7, 9,6])
Saída: 27 
*/
