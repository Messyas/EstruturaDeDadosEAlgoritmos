#include <stdlib.h>
#include <stdio.h>

int toSquared(int *num1, int *num2)
{
    *num1 = (*num1) * 2;
    *num2 = (*num2) * 2;
    return *num1 + *num2;
}

int main()
{
    int num1 = 2;
    int num2 = 4;

    int sum = toSquared(&num1, &num2);
    printf("%d A soma do dobro dos dois é: ", sum);

    return 0;
}