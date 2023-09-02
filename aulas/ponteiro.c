#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída.
#include <stdlib.h> // Inclui a biblioteca padrão para alocação dinâmica de memória.

int main(int argc, char const *argv[])
{
    int a = 3; // Declara e inicializa a variável 'a' com o valor 3.
    int b = a; // Declara e inicializa a variável 'b' com o valor de 'a'.
    int* p = &a; // Declara um ponteiro para inteiro 'p' que aponta para 'a'.

    printf("a = %d \n", a); // Imprime o valor de 'a'.
    printf("p = %p \n", (void *)p); // Imprime o endereço de 'a' (necessário o cast para void*).
    printf("*p = %d \n", *p); // Imprime o valor apontado por 'p' (o valor de 'a').
    printf("&a = %p \n", (void *)&a); // Imprime o endereço de 'a'.

    int* p1; // Declara um ponteiro 'p1'.

    p1 = malloc(sizeof(int)); // Aloca dinamicamente memória para armazenar um inteiro.
    printf("p1 = %p \n", p1); // Imprime o endereço de memória alocado.
    printf("*p1 = %d \n", *p1); // O valor inicial no espaço de memória alocado é indefinido.
    *p1 = 2; // Atribui o valor 2 ao espaço de memória alocado.
    printf("*p1 = %d \n", *p1); // Imprime o valor após a atribuição.

    p1++;
    *p1 =5;
    printf("p1 = %p \n", p1);
    printf("*p1 = %d \n", *p1);

    p1[1] = 7;
    printf("p1 = %p \n", &p1[1]);
    printf("*p1 = %d \n", p1[1]);


    return 0; // Retorna 0 para indicar um término bem-sucedido do programa.
}
