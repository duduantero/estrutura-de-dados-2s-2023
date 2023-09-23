#include <stdio.h>
#include <stdlib.h>
#include "bubble_sort.h"

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        printf("Uso: %s num1 num2 num3 ... \n", argv[0]);
        return 1;
    }

    int numElementos = argc - 1;
    int *numeros = (int *)malloc(numElementos * sizeof(int));

    for (int i = 1; i <= numElementos; i++) {
        numeros[i - 1] = atoi(argv[i]);
    }

    bubbleSort(numeros, numElementos);

    printf("Saída:");
    for (int i = 0; i < numElementos; i++) {
        printf(" %d", numeros[i]);
    }
    printf("\n");

    free(numeros);

    return 0;
}
