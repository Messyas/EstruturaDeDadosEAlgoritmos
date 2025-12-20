//Entrar com dois valores via teclado, onde o segundo deverá ser maior que o 
//primeiro. Caso contrário solicitar novamente apenas o segundo valor.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b = 0;
    printf("\n Digite um numero a");
    scanf("%d", &a);
    printf("\n Digite um numero b");
    scanf("%d", &b);
    while (b <= a) {
        printf("\n Digite o b novamente numero");
        scanf("%d", &b);
    }

return 0;
}