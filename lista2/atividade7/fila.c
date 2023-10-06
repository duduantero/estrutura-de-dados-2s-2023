#include <stdio.h>
#include <string.h>
#include "fila.h"

// Função para adicionar uma música à lista de reprodução
void adicionarMusica(struct ListaDeReproducao *lista, const char *titulo, const char *artista) {
    if (lista->tamanho < MAX_MUSICAS) {
        strcpy(lista->musicas[lista->tamanho].titulo, titulo);
        strcpy(lista->musicas[lista->tamanho].artista, artista);
        lista->tamanho++;
    } else {
        printf("A lista de reproducao esta cheia.\n");
    }
}

// Função para reproduzir a próxima música e removê-la da lista
void reproduzirProximaMusica(struct ListaDeReproducao *lista) {
    if (lista->tamanho > 0) {
        if (lista->indiceMusicaAtual < lista->tamanho - 1) {
            lista->indiceMusicaAtual++;
        } else {
            lista->indiceMusicaAtual = 0;
        }
        printf("Tocando agora: %s - %s\n", lista->musicas[lista->indiceMusicaAtual].titulo, lista->musicas[lista->indiceMusicaAtual].artista);

        // Remova a música da lista
        for (int i = lista->indiceMusicaAtual; i < lista->tamanho - 1; i++) {
            strcpy(lista->musicas[i].titulo, lista->musicas[i + 1].titulo);
            strcpy(lista->musicas[i].artista, lista->musicas[i + 1].artista);
        }
        lista->tamanho--;
    } else {
        printf("Nenhuma proxima musica na fila.\n");
    }
}

void mostrarListaDeReproducao(const struct ListaDeReproducao *lista) {
    printf("Lista de Reproducao:\n");

    if (lista->tamanho == 0) {
        printf("A lista de reprodução esta vazia.\n");
    } else {
        for (int i = 0; i < lista->tamanho; i++) {
            printf("%d. %s - %s\n", i + 1, lista->musicas[i].titulo, lista->musicas[i].artista);
        }
    }
}