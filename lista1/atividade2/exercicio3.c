#include  <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char array[3];
    char string;
    int j;
    for (int i = 0; i < 3; i++)
    {
        array[i] = argv[i+1];
        j = i;
        if (array[i] == array[j]){
            return 1;
        }
    }
    return 0;
}


/*
Exercício 3 - Verificar se um elemento existe no array Escreva uma função que recebe um array de strings e uma string de busca, 
e retorna "1" se a string de busca existe no array, ou "0" caso não exista.

Exemplo: busca_string(["texto", "J", "EDA"], "EDO")
Saída: 0 
*/