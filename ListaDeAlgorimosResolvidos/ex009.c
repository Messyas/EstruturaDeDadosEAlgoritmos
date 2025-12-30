/*
Elaborar um programa que apresente os valores de conversão de graus Celsius em 
Fahrenheit, de 10 em 10 graus, iniciando a contagem em 10 graus Celsius e 
finalizando em 100 graus Celsius. O programa deve imprimir a tabela na tela.
*/
#include <stdio.h>

float convertCelsiusToFahrenheit(float valueInCelsius) {
    return ((1.8 * valueInCelsius) + 32);
}

int main () {
    float fahrenheitValue = 0;
    for (int i = 10; i <= 100; i = i + 10) {
        fahrenheitValue = convertCelsiusToFahrenheit(i);
        printf("%dC = %.1f%F\n", i, fahrenheitValue);
    }

    return 0;
}