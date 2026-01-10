/**
 * Crie um programa que contenha uma matriz de float contendo 3 linhas e 3 colunas. 
 * Imprima o endereço de cada posição dessa matriz.
 */

#include <stdio.h>

 int main () {
    float matriz [3][3] = {{0}};

    printf("--- Enderecos da Matriz 3x3 ---\n");

    for (int i = 0; i < 3; i++ ) {
        for (int j = 0; j < 3; j++) {
            printf("Linha %d, Coluna %d: %p\n", i, j, (void*)&matriz[i][j]);
        }
    }

    return 0;
 }