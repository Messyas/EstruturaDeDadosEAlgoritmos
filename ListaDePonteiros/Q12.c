/*
Faça um programa que leia 3 valores, chame uma função para ordená-los 
(o menor deve ficar na primeira variável, o maior na última). 
A função retorna 1 se os três forem iguais e 0 se houver diferentes.
*/

#include <stdio.h>

int ordenar(int *a, int *b, int *c) {
    int iguais = 0;
    
    if (*a == *b && *b == *c) {
        iguais = 1;
    }
    int temp;

    if (*a > *b) {
        temp = *a;
        *a = *b;
        *b = temp;
    }

    if (*a > *c) {
        temp = *a;
        *a = *c;
        *c = temp;
    }

    if (*b > *c) {
        temp = *b;
        *b = *c;
        *c = temp;
    }
    
    return iguais;
}

int main() {
    int n1, n2, n3;

    printf("Digite 3 numeros: ");
    scanf("%d %d %d", &n1, &n2, &n3);

    int resultado = ordenar(&n1, &n2, &n3);

    printf("\nValores ordenados: %d, %d, %d\n", n1, n2, n3);
    if (resultado == 1) {
        printf("Todos os valores sao iguais.\n");
    } else {
        printf("Existem valores diferentes.\n");
    }

    return 0;
}