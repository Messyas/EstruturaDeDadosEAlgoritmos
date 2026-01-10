#include <stdio.h>

void sum(int *num1, int *num2)
{
    *num1 = (*num1 + *num2);
}

int main()
{
    int n1 = 2;
    int n2 = 4;

    printf("%d A: \n", n1);
    printf("%d B: \n", n2);
    sum(&n1, &n2);
    printf("%d A: \n", n1);
    printf("%d B: \n", n2);

    return 0;
}