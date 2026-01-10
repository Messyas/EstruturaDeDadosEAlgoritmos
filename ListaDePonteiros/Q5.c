#include <stdlib.h>
#include <stdio.h>

void whoIsGreater(int *one, int *two)
{
    if (*one == *two)
    {
        printf("Os dois numeros sao iguais");
        return;
    }

    if (*one > *two)
    {
        printf("troca desnecessaria, o 1 é maior que o segundo");
    }
    else
    {
        int temp = *one;
        *one = *two;
        *two = temp;
        printf("Agora o valor esta correto e trocado, de modo queo one e maior que o segundo.");
    }
}

int main()
{
    int one = 20;
    int two = 40;

    whoIsGreater(&one, &two);

    return 0;
}