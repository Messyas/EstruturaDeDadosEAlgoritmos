#include <stdio.h>

/*
SELECTION SORT

Este algoritmo é muito bom para ordenar listas muito pequenas de números por exemplo.
Se tiveres um vetor de até 5 a 20 elementos, pode ser a melhor escolha.
EXPANSÃO: Isso ocorre porque algoritmos complexos (como QuickSort ou MergeSort) têm um custo
fixo de preparação (overhead de recursão e alocação). Para listas minúsculas,
a simplicidade bruta do Selection Sort ganha dessa "burocracia".

Caso de uso?
Bom, se você quiser fazer ordenação de bilhões de vetores diferentes, pode ser uma opção.
EXPANSÃO: Imagine que você tem 1 bilhão de vetores, mas cada vetor tem apenas 10 números.
Usar um algoritmo complexo gastaria muita memória de pilha (stack). O Selection Sort
é "in-place" (não gasta memória extra) e muito leve para a CPU iniciar.
*/

void selectionSort(float vetor[], unsigned tamanhoVetor)
{
    // Vamos até o penúltimo porque, se n-1 itens estão certos, o último automaticamente sobra no lugar certo.
    unsigned penultimo = tamanhoVetor - 1;
    float temp;
    unsigned i, cont;
    unsigned posMenor;

    // Loop Externo: Define a fronteira entre a parte ordenada e a não ordenada
    for (i = 0; i < penultimo; i++)
    {
        posMenor = i; // Assumimos inicialmente que o primeiro da fila bagunçada é o menor

        // Loop Interno: Procura o verdadeiro menor número no restante da lista
        for (cont = i + 1; cont < tamanhoVetor; cont++)
        {
            if (vetor[cont] < vetor[posMenor])
            {
                posMenor = cont; // Encontramos um candidato menor! Atualizamos o índice.
            }
        }

        // TROCA (SWAP): Coloca o menor elemento encontrado na posição correta (i)
        // Note que isso acontece apenas UMA vez por iteração do loop externo.
        // Isso economiza operações de escrita (write) na memória.
        if (posMenor != i)
        { // Pequena otimização: só troca se for necessário
            temp = vetor[i];
            vetor[i] = vetor[posMenor];
            vetor[posMenor] = temp;
        }
    }
}

void imprimirVetor(float vetor[], unsigned tamanho)
{
    printf("[ ");
    for (unsigned i = 0; i < tamanho; i++)
    {
        printf("%.2f ", vetor[i]);
    }
    printf("]\n");
}

int main()
{
    // Adicionado valores decimais para provar que funciona com float
    float vetor[] = {500.0, 20.0, 4.5, 100.0, 6.0, 1000.0, 10000.0, 20000.0, -10.0};

    // Cálculo dinâmico do tamanho do vetor
    unsigned tamanho = sizeof(vetor) / sizeof(vetor[0]);

    printf("--- Antes do Selection Sort ---\n");
    imprimirVetor(vetor, tamanho);

    // Chamada da função passando o vetor e o tamanho calculado
    selectionSort(vetor, tamanho);

    printf("\n--- Depois do Selection Sort ---\n");
    imprimirVetor(vetor, tamanho);

    return 0;
}