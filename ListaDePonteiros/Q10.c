#include <stdio.h>
#include <stdlib.h>

int main()
{
    int array[5];

    printf("Digite 5 numeros inteiros.\n");

    for (int i = 0; i < 5; i++)
    {
        scanf("%d", (array + i));
    }

    for (int i = 0; i < 5; i++)
    {
        printf("Posicao %d: %d\n", i, *(array + i) * 2);
    }

    return 0;
}