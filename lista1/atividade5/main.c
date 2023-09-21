#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bubble_sort.h"

int main(int argc, char const *argv[]) {
    if (argc != 2) {
        printf("Uso: %s arq_palavras.txt \n", argv[0]);
        return 1;
    }

    FILE *entrada = fopen(argv[1], "r");
    if (entrada == NULL) {
        perror("Erro ao abrir o arquivo");
        return 2;
    }

    // Contar o número de palavras no arquivo
    int numPalavras = 0;
    char linha[100]; // Assumindo que uma linha tem no máximo 100 caracteres

    while (fgets(linha, sizeof(linha), entrada) != NULL) {
        numPalavras++;
    }

    // Voltar ao início do arquivo
    fseek(entrada, 0, SEEK_SET);

    // Ler as palavras em um array de estruturas
    Palavra *palavras = malloc(numPalavras * sizeof(Palavra));
    for (int i = 0; i < numPalavras; i++) {
        palavras[i].palavra = malloc(100); // Novamente, assumindo no máximo 100 caracteres por palavra
        fgets(palavras[i].palavra, 100, entrada);
        // Remover o caractere de nova linha (se houver)
        char *newline = strchr(palavras[i].palavra, '\n');
        if (newline) {
            *newline = '\0';
        }
    }

    // Chamar o algoritmo de ordenação
    bubbleSort(palavras, numPalavras);

    // Criar o arquivo de saída
    FILE *saida = fopen("arq_palavras_ordenado.txt", "w");
    if (saida == NULL) {
        perror("Erro ao criar o arquivo de saída");
        return 3;
    }

    // Escrever as palavras ordenadas no arquivo de saída
    for (int i = 0; i < numPalavras; i++) {
        fprintf(saida, "%s\n", palavras[i].palavra);
    }

    // Liberar memória alocada
    for (int i = 0; i < numPalavras; i++) {
        free(palavras[i].palavra);
    }
    free(palavras);

    // Fechar os arquivos
    fclose(entrada);
    fclose(saida);

    return 0;
}
