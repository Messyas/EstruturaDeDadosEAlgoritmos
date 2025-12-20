//Fazer um programa que leia 20 idades de pessoas. 
// Calcule e escreva a idade média deste grupo.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int idade = 0;
    float soma = 0;
    int i = 1;
    float media = 0;
    while (i <= 20) {
        printf("Digite sua idade: ");
        scanf("%d", &idade);
        soma = soma + idade;
        i++;
    }
    media = soma / 20;
    printf("%f", media);
    return 0;
}