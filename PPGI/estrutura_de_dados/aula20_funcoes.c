/**
Fatorial de um numero
*/

#include<stdio.h>

unsigned long fatorial (unsigned numero) {
    unsigned long fat = 1;
    unsigned cont;

    for (cont = 2; cont <= numero; cont++) {
        fat = fat * cont;
    }
    return fat;
}

unsigned somaNaturais(unsigned n) {
    unsigned soma = 0;
    unsigned cont;
    for (cont = 1; cont <= n; cont++) {
        soma = soma + cont;
    }
    return soma;
}

int main() {
    unsigned long valor;
    int n = 5;

    printf("%lu\n", fatorial(n));
    valor = somaNaturais(100);
    printf("%lu\n", valor);

    return 0;
}