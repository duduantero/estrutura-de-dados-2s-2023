#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H
#include <stdbool.h>

typedef struct No {
    int valor;
    struct No* no_esquerda;
    struct No* no_direita;
} No;

void ab_inserir_no(No** raiz, int valor);
void ab_imprimir_em_ordem(No* raiz);
No* ab_remover_no(No* raiz, int valor);
bool ab_buscar_valor(No* raiz, int valor);
void ab_imprimir_preordem(No* raiz);
void ab_imprimir_posordem(No* raiz);
int ab_encontrar_minimo(No* raiz);
int ab_encontrar_maximo(No* raiz);

#endif // ARVORE_BINARIA_H
