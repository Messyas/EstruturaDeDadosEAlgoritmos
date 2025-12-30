/*
Fazer um programa que leia um conjunto de idades de pessoas. 
O final do conjunto de valores é conhecido através do valor 
-1. Calcule e escreva a idade média deste conjunto
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int age = 0;
    int i = 0;
    float total = 0;
    float media = 0;

    printf("Digite uma lista de idades");

    while (true) {
        scanf("%d", &age);
        if (age == -1) {
            printf("fechando...");
            break;
        }
        total = age + total;
        printf("Digite a proxima idade \n");
        i++;
    }

    if (i > 0) {
        media = total/i;
        printf("%g",media);
    } else {
        prinf("Nenhuma idade foi inserida")
    }
   

    return 0;
}