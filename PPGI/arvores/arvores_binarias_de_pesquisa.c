/**
 * Arvore Binaria de Pesquisa (BST) Completa
 */
#include <stdio.h>
#include <stdlib.h>

typedef int tipoDado;

typedef struct tipoNoArvore
{
    tipoDado dado;
    struct tipoNoArvore *esq, *dir;
    struct tipoNoArvore *pai; // Ponteiro para o pai (facilita subir na arvore)
} tipoNoArvore;

typedef struct
{
    struct tipoNoArvore *raiz;
    // O ponteiro 'inicio' geralmente não é mantido na struct principal de BSTs
    // dinâmicas pois muda muito, mas mantivemos a estrutura lógica.
} tipoArvore;

// ============================================================================
// FUNÇÕES AUXILIARES
// ============================================================================

void criarArvore(tipoArvore *arv)
{
    // UTILIZACAO DE PONTEIRO: Passamos 'arv' por referência (*)
    // Se passássemos por valor, alteraríamos uma cópia e a main não veria a mudança.
    arv->raiz = NULL;
}

// Retorna o nó com o valor MÍNIMO (anda tudo para a esquerda)
tipoNoArvore *minimo(tipoNoArvore *no)
{
    if (!no)
        return NULL;
    while (no->esq != NULL)
    {
        no = no->esq;
    }
    return no;
}

// Retorna o nó com o valor MÁXIMO (anda tudo para a direita)
tipoNoArvore *maximo(tipoNoArvore *no)
{
    if (!no)
        return NULL;
    while (no->dir != NULL)
    {
        no = no->dir;
    }
    return no;
}

// ============================================================================
// FORMAS DE INSERÇÃO (Comparativo de Eficiência e Ponteiros)
// ============================================================================

/* * VERSÃO 1: Recursiva Clássica (Retorno de Ponteiro)
 * ---------------------------------------------------
 * ONDE ESTÁ O PONTEIRO? Recebemos o nó atual.
 * POR QUE? A função retorna o endereço do nó (novo ou existente).
 * Quem chamou a função deve atualizar seu ponteiro: raiz->esq = insereV1(...).
 * * PROBLEMA:
 * 1. Overhead de pilha de recursão.
 * 2. É chato gerenciar o ponteiro 'pai' na volta da recursão.
 */
tipoNoArvore *insereNaArvoreV1(tipoNoArvore *raiz, int dado, tipoNoArvore *pai)
{
    if (raiz == NULL)
    {
        tipoNoArvore *novo = (tipoNoArvore *)malloc(sizeof(tipoNoArvore));
        novo->dado = dado;
        novo->esq = NULL;
        novo->dir = NULL;
        novo->pai = pai; // Atualiza quem é o pai deste novo nó
        return novo;
    }

    if (dado < raiz->dado)
    {
        raiz->esq = insereNaArvoreV1(raiz->esq, dado, raiz);
    }
    else if (dado > raiz->dado)
    {
        raiz->dir = insereNaArvoreV1(raiz->dir, dado, raiz);
    }
    // Se for igual, não insere (BST não aceita duplicados nesta implementação)

    return raiz;
}

/* * VERSÃO 2: Recursiva com Ponteiro Duplo (Pointer to Pointer)
 * ---------------------------------------------------
 * ONDE ESTÁ O PONTEIRO? Recebemos `**raiz` (o endereço da variável ponteiro).
 * POR QUE? Permite modificar O CONTEÚDO do ponteiro original lá da função main
 * ou do nó pai, sem precisar de `return`.
 * * Uso: insereNaArvoreV2(&arvore.raiz, 10, NULL);
 */
void insereNaArvoreV2(tipoNoArvore **raiz, int dado, tipoNoArvore *pai)
{
    if (*raiz == NULL)
    {
        // Alocamos memória e fazemos o ponteiro original apontar para ela
        *raiz = (tipoNoArvore *)malloc(sizeof(tipoNoArvore));
        (*raiz)->dado = dado;
        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
        (*raiz)->pai = pai;
    }
    else
    {
        if (dado < (*raiz)->dado)
        {
            // Passamos o endereço do ponteiro da esquerda
            insereNaArvoreV2(&((*raiz)->esq), dado, *raiz);
        }
        else if (dado > (*raiz)->dado)
        {
            // Passamos o endereço do ponteiro da direita
            insereNaArvoreV2(&((*raiz)->dir), dado, *raiz);
        }
    }
}

/* * VERSÃO 3: Iterativa (A Melhor para Performance)
 * ---------------------------------------------------
 * POR QUE É A MELHOR?
 * 1. Não usa pilha de recursão (Stack Overflow nunca acontece).
 * 2. Em árvores desbalanceadas (ex: inserir 1, 2, 3, 4, 5...), a recursiva
 * faria N chamadas. A iterativa faz apenas um loop while.
 * 3. Facilita muito o controle do ponteiro 'pai'.
 */
void insereNaArvoreV3(tipoArvore *arv, int dado)
{
    tipoNoArvore *novo = (tipoNoArvore *)malloc(sizeof(tipoNoArvore));
    novo->dado = dado;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->pai = NULL; // Será ajustado abaixo

    if (arv->raiz == NULL)
    {
        arv->raiz = novo;
        return;
    }

    tipoNoArvore *atual = arv->raiz;
    tipoNoArvore *anterior = NULL;

    // Busca a posição (Desce na árvore sem recursão)
    while (atual != NULL)
    {
        anterior = atual; // Guarda a referência do pai
        if (dado < atual->dado)
        {
            atual = atual->esq;
        }
        else if (dado > atual->dado)
        {
            atual = atual->dir;
        }
        else
        {
            free(novo); // Dado já existe
            return;
        }
    }

    // Insere e liga o ponteiro pai
    novo->pai = anterior;
    if (dado < anterior->dado)
    {
        anterior->esq = novo;
    }
    else
    {
        anterior->dir = novo;
    }
}

// ============================================================================
// OPERAÇÕES DE BUSCA E NAVEGAÇÃO
// ============================================================================

// Busca Iterativa (Mais rápida que recursiva)
tipoNoArvore *busca(tipoNoArvore *raiz, int dado)
{
    while (raiz != NULL && raiz->dado != dado)
    {
        if (dado < raiz->dado)
            raiz = raiz->esq;
        else
            raiz = raiz->dir;
    }
    return raiz; // Retorna o nó ou NULL
}

// Sucessor: O próximo valor mais alto que o atual
// Lógica:
// 1. Se tem filho à direita, o sucessor é o mínimo da direita.
// 2. Se não tem, subimos pelo pai até encontrarmos uma curva para a esquerda.
tipoNoArvore *sucessor(tipoNoArvore *x)
{
    if (x == NULL)
        return NULL;

    // Caso 1: Tem subárvore direita
    if (x->dir != NULL)
    {
        return minimo(x->dir);
    }

    // Caso 2: Não tem direita, sobe pelos pais
    tipoNoArvore *y = x->pai;
    while (y != NULL && x == y->dir)
    { // Enquanto eu for filho da direita (estou crescendo)
        x = y;
        y = y->pai;
    }
    return y;
}

// Antecessor: O valor imediatamente anterior
tipoNoArvore *antecessor(tipoNoArvore *x)
{
    if (x == NULL)
        return NULL;

    // Caso 1: Tem subárvore esquerda -> pega o maior da esquerda
    if (x->esq != NULL)
    {
        return maximo(x->esq);
    }

    // Caso 2: Sobe pelos pais até deixar de ser filho da esquerda
    tipoNoArvore *y = x->pai;
    while (y != NULL && x == y->esq)
    {
        x = y;
        y = y->pai;
    }
    return y;
}

// ============================================================================
// REMOÇÃO (A operação mais complexa)
// ============================================================================

/*
 * Função auxiliar para "transplantar" subárvores.
 * Troca a subárvore enraizada em 'u' pela subárvore enraizada em 'v'.
 * Essa função arruma os ponteiros dos pais corretamente.
 */
void transplante(tipoArvore *arv, tipoNoArvore *u, tipoNoArvore *v)
{
    if (u->pai == NULL)
    { // u era a raiz
        arv->raiz = v;
    }
    else if (u == u->pai->esq)
    { // u era filho esquerdo
        u->pai->esq = v;
    }
    else
    { // u era filho direito
        u->pai->dir = v;
    }
    if (v != NULL)
    {
        v->pai = u->pai;
    }
}

void remover(tipoArvore *arv, int chave)
{
    tipoNoArvore *z = busca(arv->raiz, chave);
    if (z == NULL)
        return; // Valor não existe

    // CASO 1: Não tem filho à esquerda (pode ter na direita ou ser folha)
    if (z->esq == NULL)
    {
        transplante(arv, z, z->dir);
    }
    // CASO 2: Não tem filho à direita (só tem na esquerda)
    else if (z->dir == NULL)
    {
        transplante(arv, z, z->esq);
    }
    // CASO 3: Tem DOIS filhos
    else
    {
        // Achamos o sucessor (o menor valor da subárvore direita)
        tipoNoArvore *y = minimo(z->dir);

        // Se o sucessor não é filho direto de z, precisamos arrumar a direita de y primeiro
        if (y->pai != z)
        {
            transplante(arv, y, y->dir);
            y->dir = z->dir;
            y->dir->pai = y;
        }

        // Substitui z por y
        transplante(arv, z, y);
        y->esq = z->esq;
        y->esq->pai = y;
    }
    free(z);
}

// ============================================================================
// MAIN DE TESTES
// ============================================================================

void imprimirOrdem(tipoNoArvore *raiz)
{
    if (raiz != NULL)
    {
        imprimirOrdem(raiz->esq);
        printf("%d ", raiz->dado);
        imprimirOrdem(raiz->dir);
    }
}

int main()
{
    tipoArvore arvore;
    criarArvore(&arvore);

    // Teste de Performance / Stack Overflow
    // Se você usar a insereNaArvoreV1 (recursiva) com 100.000,
    // provavelmente dará estouro de pilha no Windows (que tem stack pequena por padrão).
    // A V3 (Iterativa) aguenta tranquilamente.

    printf("Inserindo elementos de forma iterativa (V3)...\n");
    insereNaArvoreV3(&arvore, 50);
    insereNaArvoreV3(&arvore, 30);
    insereNaArvoreV3(&arvore, 20);
    insereNaArvoreV3(&arvore, 40);
    insereNaArvoreV3(&arvore, 70);
    insereNaArvoreV3(&arvore, 60);
    insereNaArvoreV3(&arvore, 80);

    printf("Arvore em ordem: ");
    imprimirOrdem(arvore.raiz);
    printf("\n");

    // Teste de Busca e Predecessor
    tipoNoArvore *no = busca(arvore.raiz, 40);
    if (no)
    {
        printf("Elemento 40 encontrado.\n");
        tipoNoArvore *ant = antecessor(no);
        tipoNoArvore *suc = sucessor(no);
        if (ant)
            printf("- Antecessor de 40: %d\n", ant->dado); // Deve ser 30
        if (suc)
            printf("- Sucessor de 40: %d\n", suc->dado); // Deve ser 50
    }

    // Teste de Remoção
    printf("Removendo raiz (50)...\n");
    remover(&arvore, 50);

    printf("Arvore apos remocao: ");
    imprimirOrdem(arvore.raiz); // A raiz deve ter mudado para 60 (sucessor)
    printf("\n");

    if (arvore.raiz)
        printf("Nova raiz: %d\n", arvore.raiz->dado);

    return 0;
}