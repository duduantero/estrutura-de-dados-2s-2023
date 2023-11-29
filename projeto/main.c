#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

int main(int argc, char* argv[]) {
    No* raiz = NULL;

    // Inserção
    ab_inserir_no(&raiz, 4);
    ab_inserir_no(&raiz, 2);
    ab_inserir_no(&raiz, 6);
    ab_inserir_no(&raiz, 7);
    ab_inserir_no(&raiz, 5);
    ab_inserir_no(&raiz, 3);
    ab_inserir_no(&raiz, 1);
    ab_inserir_no(&raiz, 8);


    // Remoção
    raiz = ab_remover_no(raiz, 8);

    // Busca
    printf("Busca 5: %s\n", ab_buscar_valor(raiz, 5) ? "Encontrado" : "Nao encontrado");
    printf("Busca 8: %s\n", ab_buscar_valor(raiz, 8) ? "Encontrado" : "Nao encontrado");

    // Percursos
    printf("Inordem: ");
    ab_imprimir_em_ordem(raiz);
    printf("\nPreordem: ");
    ab_imprimir_preordem(raiz);
    printf("\nPosordem: ");
    ab_imprimir_posordem(raiz);
    printf("\n");

    // Mínimo e Máximo
    printf("Minimo: %d\n", ab_encontrar_minimo(raiz));
    printf("Maximo: %d\n", ab_encontrar_maximo(raiz));

    return 0;
}
