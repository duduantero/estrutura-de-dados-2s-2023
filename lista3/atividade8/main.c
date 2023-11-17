#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char* argv[]) {
    No* n0 = no('C', NULL);
    No* n1 = no('E', NULL);
    No* n2 = no('A', no('D', no('B', no('X', no('Z', NULL)))));
    No* n3 = no('U', NULL);

    lista_inserir_no(n0, n2);
    lista_inserir_no(n0, n1);
    lista_inserir_no(n0, n3);

    printf("Lista original: ");
    lista_imprimir(n0);
    printf("\nQuantidade de nós: %d\n", lista_quantidade_nos(n0));

    No* n_copia = lista_copiar(n0);
    printf("Lista cópia: ");
    lista_imprimir(n_copia);
    printf("\n");

    lista_concatenar(n0, n_copia);
    printf("Lista após concatenação: ");
    lista_imprimir(n0);
    printf("\n");

    lista_liberar(n0);
    n0 = NULL;

    printf("Lista após liberar: ");
    lista_imprimir(n0);
    printf("\n");

    exit(0);
}
