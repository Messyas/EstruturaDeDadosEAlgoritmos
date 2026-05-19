#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *esquerda;
    struct No *direita;
} No;

No* criarNo(int valor){
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

/* ==========================================================
 * V1: Busca Recursiva
 * ==========================================================
 * É a implementação mais elegante e direta. 
 * Desvantagem: Em árvores muito profundas e desbalanceadas, 
 * pode causar um "Stack Overflow" devido ao excesso de 
 * chamadas na pilha de execução. O(h) de memória espacial.
 */
No* busca_v1_recursiva(No* raiz, int chave) {
    // Caso base: raiz é nula ou a chave foi encontrada
    if (raiz == NULL || raiz->valor == chave) {
        return raiz;
    }
    
    // Se a chave for menor, busca na subárvore esquerda
    if (chave < raiz->valor) {
        return busca_v1_recursiva(raiz->esquerda, chave);
    }
    
    // Caso contrário, busca na subárvore direita
    return busca_v1_recursiva(raiz->direita, chave);
}

/* ==========================================================
 * V2: Busca Iterativa (Repetição / Didática)
 * ==========================================================
 * Resolve o problema da pilha de execução usando um laço 'while'.
 * É a versão mais amigável para leitura, com os desvios 
 * condicionais bem definidos. Usa O(1) de memória.
 */
No* busca_v2_iterativa(No* raiz, int chave) {
    No* atual = raiz;
    
    while (atual != NULL) {
        if (chave == atual->valor) {
            return atual;     // Encontrou
        } else if (chave < atual->valor) {
            atual = atual->esquerda; // Vai para a esquerda
        } else {
            atual = atual->direita; // Vai para a direita
        }
    }
    
    return NULL; // Não encontrou
}

/* ==========================================================
 * V3: Busca Iterativa Otimizada
 * ==========================================================
 * Mais enxuta. Reutiliza o próprio ponteiro recebido por 
 * parâmetro (em C, os ponteiros são passados por valor, então 
 * não altera a raiz original fora da função) e funde as 
 * verificações. Reduz a quantidade de `if` avaliados por ciclo.
 */
No* busca_v3_otimizada(No* raiz, int chave) {
    // O laço só roda enquanto não for nulo e não for o valor
    while (raiz != NULL && raiz->valor != chave) {
        // Operador ternário para definir o próximo salto
        raiz = (chave < raiz->valor) ? raiz->esquerda : raiz->direita;
    }
    
    // Retorna a raiz atual (pode ser o Nó encontrado ou NULL)
    return raiz;
}

int main() {
    // Montando uma árvore simples para teste:
    //       10
    //      /  \
    //     5    15
    No* raiz = criar_no(10);
    raiz->esquerda = criar_no(5);
    raiz->direita = criar_no(15);

    int chave = 5;

    // Testando as 3 versões
    No* res1 = busca_v1_recursiva(raiz, chave);
    No* res2 = busca_v2_iterativa(raiz, chave);
    No* res3 = busca_v3_otimizada(raiz, chave);

    if (res1 && res2 && res3) {
        printf("Chave %d encontrada com sucesso nas 3 versoes!\n", res1->valor);
    } else {
        printf("Chave nao encontrada.\n");
    }

    // Liberação de memória omitida para brevidade
    return 0;
}