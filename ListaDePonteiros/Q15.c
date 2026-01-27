#include <stdlib.h>
#include <stdio.h>

/*
15) Crie uma funcao que receba como parametro um array e o imprima. 
nao utilize indices para percorrer o array, apenas arotmética de ponteiros.
*/
void printArray(int *array) {
    int size = sizeof(array) / array[0];
    for (int i = 0; i < size; i++) {
        printf("%d", *(array + i));
    }
}

int main() {
    int array[] = {1, 2, 3, 4, 5};
    printArray(array);

    return 0;
}