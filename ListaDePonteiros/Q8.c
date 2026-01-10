/**
 * Crie um programa que contenha um array de float contendo 10 elementos. Imprima o endereço de cada posição desse array.
 */

#include <stdio.h>

int main () {
    float array[10] = {10.00, 11.0, 12.22, 13.49, 20.34, 50.24, 444.50, 50.34, 294.4, 34.34};
    int arraySize = sizeof(array)/ sizeof(array[0]); // Tamanho total (40 bytes) / tamanho de um elemento (4 bytes) = 10 elementos

    for (int i = 0; i < arraySize; i++) {
        printf("Posicao [%d] - Endereco: %p\n", i, (void*)&array[i]); //esse void faz casting pra exibir os codigos com um ponteiro generico
    }

    return 0;
}