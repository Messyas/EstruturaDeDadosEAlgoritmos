#include <stdio.h>
#include <stdlib.h>

int main()
{
    int array[5];

    printf("Digite 5 numeros inteiros.\n");

    for (int i = 0; i < 5; i++)
    {
        scanf("%i", &array[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        if (array[i] % 2 == 0)
        {
            printf("O numero %d e par. E seu endereco e: %p\n", array[i], (void *)&array[i]);
        }
    }

    return 0;
}