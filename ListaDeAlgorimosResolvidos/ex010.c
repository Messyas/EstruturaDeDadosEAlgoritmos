/*
Fazer um programa que leia 10 números inteiros e os armazene em um vetor. 
Depois de ler todos, calcule a média e imprima na tela apenas os números 
que são maiores que a média.
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
int main () {
    int numbers[SIZE];
    int sum = 0;
    float mean = 0.0;
    printf("Digite uma lista de 10 numeros: \n");
    for (int i = 0; i < SIZE; i++) {
        printf("Digite o proximo numero.");
        scanf("%d", &numbers[i]);
        sum += numbers[i];
    }

    mean = (float)sum/SIZE;
    printf("%f", mean);

    for (int i = 0; i < SIZE; i++) {
        if (numbers[i] > mean) {
            printf("%d", numbers[i]);
        }
    }
 
    return 0;
}