#include<stdio.h>
#include<string.h>

int main() {
    int x = 10;
    int y = 20;
    int tmpInt; // variavel temporaria necessaria pra guardar o valor de uma das variaveis

    printf("%d \n", x)
    printf("%d \n", y)

    tmpInt = x;
    x = y;
    y = tmpInt;


    return 0;
}