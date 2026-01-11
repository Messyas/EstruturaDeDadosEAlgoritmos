/**
14) Crie uma funAœo que receba dois parA›metros: um array e um valor do mesmo tipo do array.
 A funAœo devera­ preencher os elementos de array com esse valor. Nao utilize Indices para 
 percorrer o array, apenas aritmetica de ponteiros.
*/

#include <stdio.h>

void trocaNum(int *nums, int valor) {
    int *ptr = nums; //copia o endereco do array original e passa pra um ponteiro

    for (int i = 0; i < 4; i++) {
        *(ptr + i) = valor; //pega o conteudo do array e itera sobre ele, [0][1][2][3]
    }

    for (int i = 0; i < 4; i++) {
        printf("%d\n", *(ptr + i));
    }
}

int main () {
    int nums[4] = {25, 50, 75, 100};
    int valor = 10;

    trocaNum(nums, valor);
  

    return 0;
}