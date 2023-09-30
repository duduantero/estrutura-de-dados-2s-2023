#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

/**
 * @brief Função para criar e inicializar uma pilha vazia.
 *
 * Esta função aloca memória para uma nova pilha, inicializa o topo como NULL
 * e define a quantidade de objetos como zero.
 *
 * @return Um ponteiro para a nova pilha criada.
 */
Pilha* pilha() {
    Pilha *P = (Pilha*)malloc(sizeof(Pilha));
    P->topo = NULL;
    P->qtd_Objetos = 0;
    return P;
}

/**
 * @brief Função para adicionar um objeto à pilha.
 *
 * @param o O objeto a ser adicionado.
 * @param P A pilha à qual o objeto será adicionado.
 */
void pilha_empilhar(Objeto* o, Pilha* P) {
    o->proximo_objeto = P->topo;
    P->topo = o;
    P->qtd_Objetos++;
}

/**
 * @brief Função para remover um objeto da pilha.
 *
 * @param P A pilha da qual o objeto será removido.
 * @return O objeto desempilhado ou NULL se a pilha estiver vazia.
 */
Objeto* pilha_desempilhar(Pilha* P) {
    if (P->qtd_Objetos == 0) {
        // Pilha está vazia, não é possível desempilhar.
        return NULL;
    }
    Objeto* o = P->topo;
    P->topo = P->topo->proximo_objeto;
    P->qtd_Objetos--;
    return o;
}

// Outras funções relacionadas à pilha...

/**
 * @brief Função para liberar a memória alocada para a pilha.
 *
 * @param P A pilha a ser liberada.
 */
void pilha_liberar(Pilha* P) {
    // Libere a memória de todos os objetos na pilha
    while (P->topo != NULL) {
        Objeto* o = pilha_desempilhar(P);
        free(o); // Certifique-se de que a memória do objeto seja liberada também.
    }
    free(P);
}
