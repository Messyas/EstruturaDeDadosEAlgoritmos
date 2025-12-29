/*
Fazer um programa que leia os valores para preencher uma Matriz 3x3 de números inteiros.
Ao final, o programa deve:

Imprimir a matriz na tela formatada como um quadrado (linhas e colunas alinhadas).
Calcular e mostrar a soma dos números da Diagonal Principal.
*/

#include <stdio.h>
#include <stdlib.h>

int main () {

    int numbers[3][3];
    int somaDiagonal = 0;


    printf("Digite os valores para criar a matriz 3x3:");

    for (int i = 0;  i < 3; i++) {
        for(int j = 0; j < 3; j++) {

            printf("Valor [%d][%d]: ", i, j);
            scanf("%d", &numbers[i][j]);

        }
    }

    printf("\nMatriz digitada:\n");

    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            printf("%4d ", numbers[i][j]); // %4d = deixa coluna alinhada

        }

        printf("\n"); // quebra linha pra formar o quadrado
    }

    for(int i = 0; i < 3; i++) {
        somaDiagonal += numbers[i][i];
    }

    printf("\nSoma da diagonal principal = %d\n", somaDiagonal);


    return 0;
}