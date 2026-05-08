#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_TABELA 10
#define LIMITE_FATOR_CARGA 0.75

/*
    Estrutura do nó da lista encadeada.
    Cada bucket da tabela hash pode apontar
    para vários elementos encadeados.
*/
typedef struct No
{
    int chave;
    struct No *proximo;
} No;

/*
    Estrutura da tabela hash.
*/
typedef struct TabelaHash
{
    No **buckets;   // vetor de ponteiros
    int tamanho;    // tamanho atual da tabela
    int quantidade; // quantidade de elementos
} TabelaHash;

/*
    Função hash.

    Recebe uma chave e transforma em índice.

    indice = chave % tamanho_da_tabela
*/
int funcaoHash(int chave, int tamanhoTabela)
{
    return chave % tamanhoTabela;
}

/*
    Cria a tabela hash dinamicamente.
*/
TabelaHash *criarTabela(int tamanho)
{

    TabelaHash *tabela = malloc(sizeof(TabelaHash));

    tabela->tamanho = tamanho;
    tabela->quantidade = 0;

    /*
        calloc inicializa tudo com NULL.
        Cada posição será um bucket.
    */
    tabela->buckets = calloc(tamanho, sizeof(No *));

    return tabela;
}

/*
    Cria um novo nó.
*/
No *criarNo(int chave)
{

    No *no = malloc(sizeof(No));

    no->chave = chave;
    no->proximo = NULL;

    return no;
}

/*
    Calcula o fator de carga.

    fator_carga = quantidade_elementos / tamanho_tabela
*/
float fatorCarga(TabelaHash *tabela)
{
    return (float)tabela->quantidade / tabela->tamanho;
}

/*
    Rehashing:
    aumenta a tabela e redistribui os elementos.
*/
void redimensionarTabela(TabelaHash *tabela)
{

    int tamanhoAntigo = tabela->tamanho;
    No **bucketsAntigos = tabela->buckets;

    int novoTamanho = tamanhoAntigo * 2;

    printf("\n[REDIMENSIONAMENTO] %d -> %d\n",
           tamanhoAntigo,
           novoTamanho);

    tabela->buckets = calloc(novoTamanho, sizeof(No *));
    tabela->tamanho = novoTamanho;
    tabela->quantidade = 0;

    /*
        Reinserir todos os elementos
        usando o novo tamanho.
    */
    for (int i = 0; i < tamanhoAntigo; i++)
    {

        No *atual = bucketsAntigos[i];

        while (atual != NULL)
        {

            int chave = atual->chave;

            int indice = funcaoHash(chave, tabela->tamanho);

            No *novoNo = criarNo(chave);

            novoNo->proximo = tabela->buckets[indice];
            tabela->buckets[indice] = novoNo;

            tabela->quantidade++;

            atual = atual->proximo;
        }
    }

    free(bucketsAntigos);
}

/*
    Insere elemento na tabela hash.
*/
void inserir(TabelaHash *tabela, int chave)
{

    /*
        Verifica fator de carga.
        Se estiver muito cheio:
        resize + rehash.
    */
    if (fatorCarga(tabela) > LIMITE_FATOR_CARGA)
    {
        redimensionarTabela(tabela);
    }

    int indice = funcaoHash(chave, tabela->tamanho);

    /*
        Colisão:
        insere no início da lista encadeada.
    */
    No *novoNo = criarNo(chave);

    novoNo->proximo = tabela->buckets[indice];
    tabela->buckets[indice] = novoNo;

    tabela->quantidade++;

    printf("Inserido %d no bucket %d\n", chave, indice);
}

/*
    Busca um elemento.
*/
int buscar(TabelaHash *tabela, int chave)
{

    int indice = funcaoHash(chave, tabela->tamanho);

    No *atual = tabela->buckets[indice];

    /*
        Percorre a lista encadeada.
    */
    while (atual != NULL)
    {

        if (atual->chave == chave)
        {
            return 1;
        }

        atual = atual->proximo;
    }

    return 0;
}

/*
    Imprime a tabela.
*/
void imprimirTabela(TabelaHash *tabela)
{

    printf("\n===== TABELA HASH =====\n");

    for (int i = 0; i < tabela->tamanho; i++)
    {

        printf("[%d] -> ", i);

        No *atual = tabela->buckets[i];

        while (atual != NULL)
        {

            printf("%d -> ", atual->chave);

            atual = atual->proximo;
        }

        printf("NULL\n");
    }

    printf("=======================\n");
}

int main()
{

    /*
        Capacidade inicial pequena
        para demonstrar resize.
    */
    TabelaHash *tabela = criarTabela(4);

    inserir(tabela, 22);
    inserir(tabela, 42);
    inserir(tabela, 52);
    inserir(tabela, 62);

    inserir(tabela, 14);
    inserir(tabela, 31);
    inserir(tabela, 72);

    imprimirTabela(tabela);

    printf("\nBusca 52: ");

    if (buscar(tabela, 52))
    {
        printf("ENCONTRADO\n");
    }
    else
    {
        printf("NAO ENCONTRADO\n");
    }

    return 0;
}