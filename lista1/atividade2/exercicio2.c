#include  <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL,"Portuguese");
    int numero[4];
    int total =0;
    int menor,maior;

    for (int i = 1; i < 5; i++){
        numero[i-1] = atoi(argv[i]);
         
    }
    maior = numero[0];
    menor = numero[0]; 

    for(int i = 0;i<4;i++){
        printf("%d",numero[i]);
        if(numero[i] < menor){
            menor = numero[i];
        }
        if (numero[i] > maior)
        {
            maior = numero[i];
        }   
    }

    printf("Menor numero: %d, menor numero: %d",menor,maior);

    return 0;
}

/*
Exercício 2 - Maior e menor elemento do array. Escreva uma função que recebe um array de números inteiros e retorna o menor e o maior elemento do array.

Exemplo: menor_maior_array([5, 7, 9,6])
Saída: 5, 9 
*/