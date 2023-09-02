#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Definição da estrutura Ponto para armazenar os dados de x e y
struct Ponto {
    float x;
    float y;
};

int main(int argc, char *argv[]) {
    setlocale(LC_NUMERIC, "en_US.UTF-8");
    // Verifica se o número correto de argumentos foi fornecido
    if (argc != 2) {
        printf("Uso: %s arquivo.csv\n", argv[0]);
        return 1;
    }

    // Abre o arquivo CSV especificado em modo de leitura
    FILE *arquivo = fopen(argv[1], "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 2;
    }

    // Conta o número de registros (linhas) no arquivo CSV
    int num_registros = 0;
    char linha[100];

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        num_registros++;
    }

    // Volta para o início do arquivo
    fseek(arquivo, 0, SEEK_SET);

    // Aloca dinamicamente memória para armazenar os pontos do arquivo CSV
    struct Ponto *pontos = malloc(num_registros * sizeof(struct Ponto));

    // Lê os pontos do arquivo CSV e converte-os para números
    int i = 0;
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char *token = strtok(linha, ",");
        pontos[i].x = atof(token);
        token = strtok(NULL, ",");
        pontos[i].y = atof(token);
        i++;
    }

    // Calcula a média de x e y
    float soma_x = 0;
    float soma_y = 0;

    for (i = 0; i < num_registros; i++) {
        soma_x += pontos[i].x;
        soma_y += pontos[i].y;
    }

    float media_x = soma_x / num_registros;
    float media_y = soma_y / num_registros;

    // Calcula a soma dos produtos (x - média_x) * (y - média_y) e a soma dos quadrados (x - média_x) ^ 2
    float soma_xy = 0;
    float soma_x2 = 0;

    for (i = 0; i < num_registros; i++) {
        soma_xy += (pontos[i].x - media_x) * (pontos[i].y - media_y);
        soma_x2 += (pontos[i].x - media_x) * (pontos[i].x - media_x);
    }

    // Calcula o coeficiente angular e o coeficiente linear da regressão linear
    float coef_angular = soma_xy / soma_x2;
    float coef_linear = media_y - coef_angular * media_x;

    // Exibe a equação da regressão linear
    printf("Equação da regressão linear: y = %.2fx + %.2f\n", coef_angular, coef_linear);

    // Libera a memória alocada
    free(pontos);
    fclose(arquivo);

    return 0;
}
