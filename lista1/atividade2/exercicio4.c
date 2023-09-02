#include  <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int array[9];
    int op = 0;
    
   while (op == 0)
   {
    for(int i = 0; i< 9; i++){
    printf("Informe um número");
    scanf("%d",&array[i]);
   }

   }
   
   
    
    
    
    return 0;
}



/*
Exercício 4 - Contar a quantidade de ocorrências de um elemento no array. Escreva uma função que recebe um array de números inteiros e um número inteiro de busca, 
e retorna a quantidade de vezes que o número de busca aparece no array.

Exemplo: conta_int_array([5, 7, 9, 6, 7, 11, 6, 5], 7)
Saída: 2
*/