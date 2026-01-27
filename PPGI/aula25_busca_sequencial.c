/*
Faca uma funcao que receba como parametro um 
vetor de numero reais e retorne uma chave de busca. 
A funcao deve retornar verdadeiro (qualquer valor diferente de zero)
caso a chave nao ocorra no vetor e falso (zero) em caso contrario
*/
#include<stdio.h>

int buscarSequencialmente(float vetor[], unsigned tamanho, float chave) {
    unsigned cont;
    for (cont = 0; cont < tamanho; cont++) {
        if (vetor[cont] == chave) {
            return 1;
        }
    }
    return 0;
}

int main() {
    float vetor[5] = {12.4, 134.24, 143.4, 94.2, 11.3};
    

    if (buscarSequencialmente(vetor, 5, 94.2)) {
        printf("chave encontrada no vetor \n");
    } else {
        printf("Chave nao encontrada no vetor \n");
    }
    return 0;
}