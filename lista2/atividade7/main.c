#include <stdio.h>
#include "fila.h"
#include <locale.h>

int main() {
    setlocale(LC_ALL, "pt_BR.utf8");
    struct ListaDeReproducao minhaLista;
    minhaLista.tamanho = 0;
    minhaLista.indiceMusicaAtual = -1;

    // Adicionar músicas à lista de reprodução
    adicionarMusica(&minhaLista, "Musica 1", "Artista 1");
    adicionarMusica(&minhaLista, "Musica 2", "Artista 2");
    adicionarMusica(&minhaLista, "Musica 3", "Artista 3");
    printf("\n");
    // Mostrar todas as músicas na lista de reprodução
    mostrarListaDeReproducao(&minhaLista);
    printf("\n");

    // Reproduzir a primeira música, se houver alguma
    reproduzirProximaMusica(&minhaLista);
    reproduzirProximaMusica(&minhaLista);
    reproduzirProximaMusica(&minhaLista);
    reproduzirProximaMusica(&minhaLista);
    printf("\n");
    return 0;
}
