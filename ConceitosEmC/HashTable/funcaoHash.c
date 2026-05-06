/**
 *  Formula: h(k) = f(k) mod m
 */

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10

typedef struct No
{
    int chave;          // dado a ser salvo
    struct No *proximo; // Ponteiro para o proximo elemento em caso de colisao
} No;

int calcular_hash(int chave)
{
    return chave % TAMANHO;
}

void inserir(No *tabela[], int chave) {
    int indice = calcular_hash(chave);

    //aloca memoria para o novo no
    No *novo = (No *)malloc(sizeof(No));
    novo->chave = chave;
    //aponta para o antigo "inicio" 
    novo->proximo = tabela[indice];
    //O inicio da tabela agora aponta para o novo no (ele vira o novo inicio)
    tabela[indice] = novo;
}

void imprimir_tabela(No *tabela[]) {
    for (int i = 0; i < TAMANHO; i++) {
        printf("Indice %d: ", i);
        No *atual = tabela[i];
        while (atual != NULL) {
            printf("%d -> ", atual->chave);
            atual = atual->proximo;
        }
        printf("NULL\n");
    }
}

int main()
{
    // dados
    No *tabela[TAMANHO] = {NULL};
    //lista
    int chaves[] = {15, 25, 35, 45, 55, 65, 75, 85, 95, 105};
    int n = sizeof(chaves) / sizeof(chaves[0]);
    //inserir dados na tabela
    for (int i = 0; i < n; i++) {
        inserir(tabela, chaves[i]);
    }
    //imprimir tabela
    imprimir_tabela(tabela);
    
    return 0;
}