#ifndef FILA_H
#define FILA_H
#define MAX_MUSICAS 100

// Estrutura de uma música
struct Musica {
    char titulo[100];
    char artista[100];
};

// Lista de reprodução de músicas
struct ListaDeReproducao {
    struct Musica musicas[MAX_MUSICAS];
    int tamanho;
    int indiceMusicaAtual;
};

// Função para adicionar uma música à lista de reprodução
void adicionarMusica(struct ListaDeReproducao *lista, const char *titulo, const char *artista);

// Função para reproduzir a próxima música
void reproduzirProximaMusica(struct ListaDeReproducao *lista);

// Função para mostrar todas as músicas na lista de reprodução
void mostrarListaDeReproducao(const struct ListaDeReproducao *lista);

#endif  // FILA_H

