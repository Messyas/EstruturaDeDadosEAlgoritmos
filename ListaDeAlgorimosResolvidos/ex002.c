//Exibir o produto dos numeros inteiros no intervalo de um a cem
#include <stdio.h>
#include <stdlib.h>

int main()
{
    double produto = 1.0;
    int i = 1;
    while (i <= 100) {
        produto = produto * i;
        i++;
    }
    printf("%e", produto);
    // poderia ser ld (long float que e como e compilado)
    // no caso com int nao seria conpilador por causa do limite de memoria.
    //existe ainda o g (especificador automatico mais intelignte)

    return 0;
}
