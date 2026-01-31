#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

/**
 * ALGORITMOS DE ORDENAÇÃO
 */
#define TAMANHO 20000

// 1. QuickSort (O(N log N))
void quicksort(float *vetor, int inicio, int fim)
{
    int i, j;
    float pivot, temp;
    if (inicio < fim)
    {
        pivot = vetor[(inicio + fim) / 2];
        i = inicio;
        j = fim;
        while (i <= j)
        {
            while (vetor[i] < pivot)
                i++;
            while (vetor[j] > pivot)
                j--;
            if (i <= j)
            {
                temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
                i++;
                j--;
            }
        }
        if (inicio < j)
            quicksort(vetor, inicio, j);
        if (i < fim)
            quicksort(vetor, i, fim);
    }
}

// 2. Merge Sort (O(N log N))
void merge(float *vetor, int l, int m, int r, float *temp)
{
    int i = l, j = m + 1, k = l;
    for (int x = l; x <= r; x++)
        temp[x] = vetor[x];
    while (i <= m && j <= r)
    {
        if (temp[i] <= temp[j])
            vetor[k++] = temp[i++];
        else
            vetor[k++] = temp[j++];
    }
    while (i <= m)
        vetor[k++] = temp[i++];
}

void mergeSortRecursivo(float *vetor, int l, int r, float *temp)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSortRecursivo(vetor, l, m, temp);
        mergeSortRecursivo(vetor, m + 1, r, temp);
        merge(vetor, l, m, r, temp);
    }
}

void mergeSort(float *vetor, int tamanho)
{
    float *temp = (float *)malloc(tamanho * sizeof(float));
    if (temp)
    {
        mergeSortRecursivo(vetor, 0, tamanho - 1, temp);
        free(temp);
    }
}

// 3. Shell Sort (O(N^1.5) aprox)
void shellSort(float *vetor, int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            float temp = vetor[i];
            int j;
            for (j = i; j >= gap && vetor[j - gap] > temp; j -= gap)
                vetor[j] = vetor[j - gap];
            vetor[j] = temp;
        }
    }
}

// 4. Selection Sort (O(N^2))
// Procura o menor elemento e joga para o início
void selectionSort(float *vetor, int n)
{
    int i, j, min_idx;
    float temp;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        // Encontra o menor elemento no restante do vetor
        for (j = i + 1; j < n; j++)
        {
            if (vetor[j] < vetor[min_idx])
                min_idx = j;
        }
        // Troca o menor elemento encontrado com o primeiro elemento não ordenado
        if (min_idx != i)
        {
            temp = vetor[min_idx];
            vetor[min_idx] = vetor[i];
            vetor[i] = temp;
        }
    }
}

// 5. Bubble Sort (O(N^2))
void bubbleSort(float *vetor, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                float temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

// 6. Wrapper para o qsort do sistema
int compararFloats(const void *a, const void *b)
{
    float fa = *(const float *)a;
    float fb = *(const float *)b;
    return (fa > fb) - (fa < fb);
}

// ============================================================
//  AUXILIARES
// ============================================================

void preencherVetorAleatoriamente(float *vetor, int size)
{
    for (int i = 0; i < size; i++)
        vetor[i] = (float)(rand() % 100000);
}

void copiaVetor(float *destino, float *origem, int size)
{
    memcpy(destino, origem, size * sizeof(float));
}

bool estaOrdenado(float *vetor, int size)
{
    for (int i = 0; i < size - 1; i++)
        if (vetor[i] > vetor[i + 1])
            return false;
    return true;
}

// ============================================================
//  MAIN
// ============================================================

int main()
{
    float *vetorMestre = (float *)malloc(TAMANHO * sizeof(float));
    float *vetorTeste = (float *)malloc(TAMANHO * sizeof(float));

    if (!vetorMestre || !vetorTeste)
        return 1;

    srand(time(NULL));
    printf("=== BATERIA DE TESTES (Tamanho: %d) ===\n\n", TAMANHO);

    preencherVetorAleatoriamente(vetorMestre, TAMANHO);

    // --- QuickSort ---
    printf("[1] QuickSort... ");
    copiaVetor(vetorTeste, vetorMestre, TAMANHO);
    clock_t inicio = clock();
    quicksort(vetorTeste, 0, TAMANHO - 1);
    clock_t fim = clock();
    double tQuick = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf(estaOrdenado(vetorTeste, TAMANHO) ? "OK (%.4fs)\n" : "ERRO\n", tQuick);

    // --- Merge Sort ---
    printf("[2] Merge Sort... ");
    copiaVetor(vetorTeste, vetorMestre, TAMANHO);
    inicio = clock();
    mergeSort(vetorTeste, TAMANHO);
    fim = clock();
    double tMerge = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf(estaOrdenado(vetorTeste, TAMANHO) ? "OK (%.4fs)\n" : "ERRO\n", tMerge);

    // --- Shell Sort ---
    printf("[3] Shell Sort... ");
    copiaVetor(vetorTeste, vetorMestre, TAMANHO);
    inicio = clock();
    shellSort(vetorTeste, TAMANHO);
    fim = clock();
    double tShell = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf(estaOrdenado(vetorTeste, TAMANHO) ? "OK (%.4fs)\n" : "ERRO\n", tShell);

    // --- System qsort ---
    printf("[4] System qsort... ");
    copiaVetor(vetorTeste, vetorMestre, TAMANHO);
    inicio = clock();
    qsort(vetorTeste, TAMANHO, sizeof(float), compararFloats);
    fim = clock();
    double tSys = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf(estaOrdenado(vetorTeste, TAMANHO) ? "OK (%.4fs)\n" : "ERRO\n", tSys);

    // --- ALGORITMOS LENTOS (Selection e Bubble) ---
    // Só executam se o vetor for <= 50.000, senão demora demais
    if (TAMANHO <= 50000)
    {

        // --- Selection Sort ---
        printf("[5] Selection Sort... ");
        copiaVetor(vetorTeste, vetorMestre, TAMANHO);
        inicio = clock();
        selectionSort(vetorTeste, TAMANHO);
        fim = clock();
        double tSel = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf(estaOrdenado(vetorTeste, TAMANHO) ? "OK (%.4fs)\n" : "ERRO\n", tSel);

        // --- Bubble Sort ---
        printf("[6] Bubble Sort... ");
        copiaVetor(vetorTeste, vetorMestre, TAMANHO);
        inicio = clock();
        bubbleSort(vetorTeste, TAMANHO);
        fim = clock();
        double tBub = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf(estaOrdenado(vetorTeste, TAMANHO) ? "OK (%.4fs)\n" : "ERRO\n", tBub);

        printf("\n--- COMPARACAO FINAL (Lentos vs Rapidos) ---\n");
        printf("QuickSort foi %.1fx mais rapido que Selection Sort\n", tSel / tQuick);
    }
    else
    {
        printf("\n[!] Selection e Bubble Sort pulados (Tamanho > 50.000).\n");
    }

    free(vetorMestre);
    free(vetorTeste);
    return 0;
}

/**
 * Alguns pontos legais sobre os principais algoritmos
 *
 * quick sort vs merge sort
 *
 * QuickSort:
 * 1.Usa menos ram, bem otimizado pra isso (in place).
 * 2.Em geral tende a ser mais rapido, exceto no pior caso que o algorimo vira O(n^2)
 * 3.Menos estavel
 * 4.Ruim para listas encadeadas, ele é melhor pra array
 * 5.Apanha no pior caso, se o pivor cair no elemento sais alto ou mais baixo
 * pode dar bem ruim (tempo quadratico)
 *
 * MergeSort:
 * 1. Confiavel como um relogio suiço, sempre vai ser O(n log n), mesmo nos casos
 * onde todos os elementos ja estao quase ordenados.
 * 2. Nao troca os elementos corretos aleatoriamente durante a ordenecao
 * 3. Muito melhor para listas encadeadas (linked Lists)
 * 4. Util quando precisa garantir que o programa nunca demora mais do que
 * o esperado (sistemas de tempo real)
 *
 * A ordenacao por selecao pode ate ser usado pra micro vetores, mas é so isso
 * O resto acredito que so é utils saber que nao se deve usar, principlamente o bolha podre
 */