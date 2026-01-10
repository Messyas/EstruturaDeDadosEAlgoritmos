#include <stdio.h>
#include <stdlib.h>

void printNumbers(int *a, int *b)
{
    printf("-----------------\n");
    printf("%d\n", *a);
    printf("%d\n", *b);
    printf("-----------------\n");
}

void printChar(char *a, char *b)
{
    printf("-----------------\n");
    printf("%c\n", *a);
    printf("%c\n", *b);
    printf("-----------------\n");
}

void reverseNumber(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

void reverseChar(char *a, char *b) 
{
    char temp = *b;
    *b = *a;
    *a = temp;
}

int main()
{
    int a = 20;
    int b = 40;

    char ac = 'a';
    char bc = 'b';


    printNumbers(&a, &b);
    reverseNumber(&a, &b);
    printNumbers(&a, &b);

    printChar(&ac, &bc);
    reverseChar(&ac, &bc);
    printChar(&ac, &bc);

    return 0;
}