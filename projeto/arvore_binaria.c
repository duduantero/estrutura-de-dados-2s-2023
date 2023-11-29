#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arvore_binaria.h"

No* no(int valor) {
    No* novo_no = malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->no_direita = NULL;
    novo_no->no_esquerda = NULL;
    return novo_no;
}

void ab_inserir_no(No** raiz, int valor) {
    if ((*raiz) == NULL) {
        (*raiz) = no(valor);
    } else {
        if (valor > (*raiz)->valor) {
            ab_inserir_no(&(*raiz)->no_direita, valor);
        } else {
            ab_inserir_no(&(*raiz)->no_esquerda, valor);
        }
    }
}

void ab_imprimir_em_ordem(No* raiz) {
    if (raiz != NULL) {
        ab_imprimir_em_ordem(raiz->no_esquerda);
        printf("%d ", raiz->valor);
        ab_imprimir_em_ordem(raiz->no_direita);
    }
}

No* encontrar_minimo(No* raiz) {
    No* atual = raiz;
    while (atual->no_esquerda != NULL) {
        atual = atual->no_esquerda;
    }
    return atual;
}

No* ab_remover_no(No* raiz, int valor) {
    if (raiz == NULL) {
        return raiz;
    }
    if (valor < raiz->valor) {
        raiz->no_esquerda = ab_remover_no(raiz->no_esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->no_direita = ab_remover_no(raiz->no_direita, valor);
    } else {
        if (raiz->no_esquerda == NULL) {
            No* temp = raiz->no_direita;
            free(raiz);
            return temp;
        } else if (raiz->no_direita == NULL) {
            No* temp = raiz->no_esquerda;
            free(raiz);
            return temp;
        }
        No* temp = encontrar_minimo(raiz->no_direita);
        raiz->valor = temp->valor;
        raiz->no_direita = ab_remover_no(raiz->no_direita, temp->valor);
    }
    return raiz;
}

bool ab_buscar_valor(No* raiz, int valor) {
    if (raiz == NULL) {
        return false; // Nó nulo, valor não encontrado
    }
    if (raiz->valor == valor) {
        return true; // Valor encontrado
    }
    if (valor < raiz->valor) {
        return ab_buscar_valor(raiz->no_esquerda, valor);
    }
    return ab_buscar_valor(raiz->no_direita, valor);
}


void ab_imprimir_preordem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        ab_imprimir_preordem(raiz->no_esquerda);
        ab_imprimir_preordem(raiz->no_direita);
    }
}

void ab_imprimir_posordem(No* raiz) {
    if (raiz != NULL) {
        ab_imprimir_posordem(raiz->no_esquerda);
        ab_imprimir_posordem(raiz->no_direita);
        printf("%d ", raiz->valor);
    }
}

int ab_encontrar_minimo(No* raiz) {
    while (raiz->no_esquerda != NULL) {
        raiz = raiz->no_esquerda;
    }
    return raiz->valor;
}

int ab_encontrar_maximo(No* raiz) {
    while (raiz->no_direita != NULL) {
        raiz = raiz->no_direita;
    }
    return raiz->valor;
}
