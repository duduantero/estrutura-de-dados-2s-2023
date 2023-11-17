#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No* no(char valor, No* proximo_no) {
    No* novo_no = malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->proximo_no = proximo_no;
    return novo_no;
}

void lista_inserir_no(No* L, No* no) {
    if (L != NULL) {
        if (L->proximo_no == NULL) {
            L->proximo_no = no;
        } else {
            lista_inserir_no(L->proximo_no, no);
        }
    }
}

void lista_imprimir(No* L) {
    if (L != NULL) {
        printf("%c ", L->valor);
        lista_imprimir(L->proximo_no);
    }
}

int lista_quantidade_nos(No* L) {
    if (L != NULL) {
        return 1 + lista_quantidade_nos(L->proximo_no);
    }
    return 0;
}

No* lista_copiar(No* L) {
    if (L != NULL) {
        return no(L->valor, lista_copiar(L->proximo_no));
    }
    return NULL;
}

void lista_concatenar(No* L, No* Lc) {
    if (L != NULL) {
        while (L->proximo_no != NULL) {
            L = L->proximo_no;
        }
        L->proximo_no = Lc;
    }
}

void lista_liberar(No* L) {
    if (L != NULL) {
        lista_liberar(L->proximo_no);
        free(L);
    }
}

int lista_verificar_existencia(No* L, char valor_busca) {
    No* p = L;
    while (p != NULL && p->valor != valor_busca) 
        p = p->proximo_no; 
    return p != NULL;
}

int lista_verificar_ocorrencias(No* L, char valor_busca) {
    int ocorrencias = 0;
    while (L != NULL) {
        if (L->valor == valor_busca) {
            ocorrencias++;
        }
        L = L->proximo_no;
    }
    return ocorrencias;
}

void lista_imprimir_inversa(No* L) {
    if (L != NULL) {
        lista_imprimir_inversa(L->proximo_no);
        printf("%c ", L->valor);
    }
}

void lista_inserir_no_i(No* L, int i) {
    if (i < 0) {
        printf("Índice inválido para inserção.\n");
        return;
    }

    if (i == 0) {
        printf("Insira o valor para o novo nó: ");
        char novo_valor;
        scanf(" %c", &novo_valor);
        No* novo_no = no(novo_valor, L->proximo_no);
        L->proximo_no = novo_no;
        return;
    }

    int indice_atual = 0;
    while (L != NULL && indice_atual < i - 1) {
        L = L->proximo_no;
        indice_atual++;
    }

    if (L == NULL) {
        printf("Índice inválido para inserção.\n");
        return;
    }

    printf("Insira o valor para o novo nó: ");
    char novo_valor;
    scanf(" %c", &novo_valor);
    No* novo_no = no(novo_valor, L->proximo_no);
    L->proximo_no = novo_no;
}

void lista_remover_no_i(No* L, int i) {
    if (i < 0) {
        printf("Índice inválido para remoção.\n");
        return;
    }

    int indice_atual = 0;
    while (L != NULL && indice_atual < i - 1) {
        L = L->proximo_no;
        indice_atual++;
    }

    if (L == NULL || L->proximo_no == NULL) {
        printf("Índice inválido para remoção.\n");
        return;
    }

    No* no_remover = L->proximo_no;
    L->proximo_no = no_remover->proximo_no;
    free(no_remover);
}

void lista_remover_no(No* L, char valor_busca) {
    No* anterior = NULL;
    No* atual = L;

    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            if (anterior == NULL) {
                // Remoção do primeiro nó
                L = atual->proximo_no;
            } else {
                anterior->proximo_no = atual->proximo_no;
            }
            free(atual);
            atual = anterior;
        }

        anterior = atual;
        atual = atual->proximo_no;
    }
}

