//Elaborar um programa que apresente no final o somatório 
//dos valores pares existentes entre 1 e 500.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int somatorio = 0;
    for (int i = 2; i <=  500; i = i + 2) {
        somatorio = somatorio + i;
    }
    printf("%d", somatorio);
    return 0;
}