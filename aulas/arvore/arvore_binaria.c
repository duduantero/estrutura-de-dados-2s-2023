#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

No* no(int valor){
    No* no = malloc(sizeof(No));
    no->no_direita = NULL;
    no->no_esquerda = NULL;
}

//dereferenciação (*raiz)
ab_inserir_no(No** raiz, int valor){
    if ((*raiz) == NULL){
        (*raiz) = no(valor);
    }
    else{
        if(valor > (*raiz)->valor){
            ab_inserir_no(&(*raiz)->no_direita,valor);
        }else{
            ab_inserir_no(&(*raiz)->no_esquerda,valor);
        }
    }
}
 ab_imprimir_em_ordem(No* raiz){
    if(raiz != NULL){
        ab_imprimir_em_ordem(raiz->no_esquerda);
        printf("%d ", raiz->valor);
        ab_imprimir_em_ordem(raiz->no_direita);
    }
    
 }