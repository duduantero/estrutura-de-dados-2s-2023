#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

typedef struct Palavra {
    char *palavra;
} Palavra;

void bubbleSort(Palavra *array, int size);

#endif