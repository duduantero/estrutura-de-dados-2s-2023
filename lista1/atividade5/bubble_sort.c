#include "bubble_sort.h"
#include <string.h>

void swap(Palavra *xp, Palavra *yp) {
    Palavra temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(Palavra *array, int size) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (strcmp(array[j].palavra, array[j + 1].palavra) > 0) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}
