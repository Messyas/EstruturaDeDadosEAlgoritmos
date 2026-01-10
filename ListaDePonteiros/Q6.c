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
    int n1 = 2;
    int n2 = 4;

    int sum = toSquared(&n1, &n2);
    printf("%d A soma do dobro dos dois é: ", sum);
    printf("Novo valor de n1: %d\n", n1);   
    printf("Novo valor de n2: %d\n", n2);  

    return 0;
}