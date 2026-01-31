#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TAMANHO 1000000
#define CUTOFF 16 // Ponto de corte para trocar para Insertion Sort

// Função auxiliar para trocas
void swap(float *a, float *b)
{
    float t = *a;
    *a = *b;
    *b = t;
}

// Função auxiliar: Insertion Sort (Usado pelo R4)
void insertion_sort_range(float *vetor, int inicio, int fim)
{
    for (int i = inicio + 1; i <= fim; i++)
    {
        float temp = vetor[i];
        int j = i - 1;
        while (j >= inicio && vetor[j] > temp)
        {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = temp;
    }
}

// ============================================================
// R1: O INGÊNUO (Pivô no Início)
// Perigoso em vetores ordenados.
// ============================================================
void quicksort_R1(float *vetor, int inicio, int fim)
{
    if (inicio < fim)
    {
        float pivot = vetor[inicio]; // Pivô ruim
        int i = inicio + 1;
        int j = fim;

        while (i <= j)
        {
            while (i <= j && vetor[i] <= pivot)
                i++;
            while (i <= j && vetor[j] > pivot)
                j--;
            if (i < j)
                swap(&vetor[i], &vetor[j]);
        }
        swap(&vetor[inicio], &vetor[j]);

        quicksort_R1(vetor, inicio, j - 1);
        quicksort_R1(vetor, j + 1, fim);
    }
}

// ============================================================
// R2: O CLÁSSICO (Pivô Central)
// Bom, mas usa muita recursão.
// ============================================================
void quicksort_R2(float *vetor, int inicio, int fim)
{
    if (inicio < fim)
    {
        float pivot = vetor[(inicio + fim) / 2];
        int i = inicio;
        int j = fim;

        while (i <= j)
        {
            while (vetor[i] < pivot)
                i++;
            while (vetor[j] > pivot)
                j--;
            if (i <= j)
            {
                swap(&vetor[i], &vetor[j]);
                i++;
                j--;
            }
        }
        if (inicio < j)
            quicksort_R2(vetor, inicio, j);
        if (i < fim)
            quicksort_R2(vetor, i, fim);
    }
}

// ============================================================
// R3: O ROBUSTO (Mediana de 3)
// Resolve o problema do pior caso.
// ============================================================
void quicksort_R3(float *vetor, int inicio, int fim)
{
    if (inicio < fim)
    {
        // Mediana de 3
        int meio = (inicio + fim) / 2;
        if (vetor[meio] < vetor[inicio])
            swap(&vetor[inicio], &vetor[meio]);
        if (vetor[fim] < vetor[inicio])
            swap(&vetor[inicio], &vetor[fim]);
        if (vetor[fim] < vetor[meio])
            swap(&vetor[meio], &vetor[fim]);

        // Esconde pivô
        swap(&vetor[meio], &vetor[fim - 1]);
        float pivot = vetor[fim - 1];

        int i = inicio;
        int j = fim - 1;

        while (1)
        {
            while (vetor[++i] < pivot)
                ;
            while (vetor[--j] > pivot)
                ;
            if (i >= j)
                break;
            swap(&vetor[i], &vetor[j]);
        }
        swap(&vetor[i], &vetor[fim - 1]); // Restaura pivô

        quicksort_R3(vetor, inicio, i - 1);
        quicksort_R3(vetor, i + 1, fim);
    }
}

// ============================================================
// R4: O OTIMIZADO (Mediana de 3 + Insertion + Sedgewick)
// A combinação matadora.
// ============================================================
void quicksort_R4(float *vetor, int inicio, int fim)
{
    // Loop principal substitui a recursão de cauda (Sedgewick)
    while (inicio < fim)
    {

        // 1. OTIMIZAÇÃO: Cutoff para Insertion Sort
        if (fim - inicio < CUTOFF)
        {
            insertion_sort_range(vetor, inicio, fim);
            break; // O trecho pequeno já está ordenado, sai do loop
        }

        // 2. OTIMIZAÇÃO: Mediana de 3
        int meio = (inicio + fim) / 2;
        if (vetor[meio] < vetor[inicio])
            swap(&vetor[inicio], &vetor[meio]);
        if (vetor[fim] < vetor[inicio])
            swap(&vetor[inicio], &vetor[fim]);
        if (vetor[fim] < vetor[meio])
            swap(&vetor[meio], &vetor[fim]);

        // Pivô vai para fim-1 (Sentinela)
        swap(&vetor[meio], &vetor[fim - 1]);
        float pivot = vetor[fim - 1];

        int i = inicio;
        int j = fim - 1;

        // Particionamento rápido
        while (1)
        {
            while (vetor[++i] < pivot)
                ;
            while (vetor[--j] > pivot)
                ;
            if (i >= j)
                break;
            swap(&vetor[i], &vetor[j]);
        }
        // Restaura pivô
        swap(&vetor[i], &vetor[fim - 1]);

        // 3. OTIMIZAÇÃO: Sedgewick (Recursão apenas no menor lado)
        if ((i - inicio) < (fim - i))
        {
            quicksort_R4(vetor, inicio, i - 1); // Recurso na esquerda (menor)
            inicio = i + 1;                     // Loop trata a direita (maior)
        }
        else
        {
            quicksort_R4(vetor, i + 1, fim); // Recurso na direita (menor)
            fim = i - 1;                     // Loop trata a esquerda (maior)
        }
    }
}

// ============================================================
// MAIN DE TESTES
// ============================================================

void preencherAleatorio(float *vetor, int size)
{
    for (int i = 0; i < size; i++)
        vetor[i] = (float)(rand() % 1000000);
}

void preencherOrdenado(float *vetor, int size)
{
    for (int i = 0; i < size; i++)
        vetor[i] = (float)i;
}

void testarAlgoritmo(char *nome, void (*func)(float *, int, int), float *origem, int size)
{
    // Aloca e copia para não estragar o original
    float *copia = (float *)malloc(size * sizeof(float));
    memcpy(copia, origem, size * sizeof(float));

    clock_t inicio = clock();
    func(copia, 0, size - 1);
    clock_t fim = clock();

    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("   %-20s: %.4f s\n", nome, tempo);

    free(copia);
}

int main()
{
    float *vetorMestre = (float *)malloc(TAMANHO * sizeof(float));
    srand(time(NULL));

    printf("=== BATERIA DE TESTES (%d Elementos) ===\n\n", TAMANHO);

    // --- CENÁRIO 1: ALEATÓRIO ---
    printf("[1] Vetor Aleatorio (Teste de Velocidade Pura)\n");
    preencherAleatorio(vetorMestre, TAMANHO);

    testarAlgoritmo("R1 (Ingenuo)", quicksort_R1, vetorMestre, TAMANHO);
    testarAlgoritmo("R2 (Central)", quicksort_R2, vetorMestre, TAMANHO);
    testarAlgoritmo("R3 (Mediana 3)", quicksort_R3, vetorMestre, TAMANHO);
    testarAlgoritmo("R4 (OTIMIZADO)", quicksort_R4, vetorMestre, TAMANHO);

    // --- CENÁRIO 2: JA ORDENADO ---
    printf("\n[2] Vetor Ja Ordenado (Teste de Robustez)\n");
    preencherOrdenado(vetorMestre, TAMANHO);

    printf("   %-20s: PULA (Travaria/Lento)\n", "R1 (Ingenuo)");
    testarAlgoritmo("R2 (Central)", quicksort_R2, vetorMestre, TAMANHO);
    testarAlgoritmo("R3 (Mediana 3)", quicksort_R3, vetorMestre, TAMANHO);
    testarAlgoritmo("R4 (OTIMIZADO)", quicksort_R4, vetorMestre, TAMANHO);

    printf("\n--- RESULTADO ESPERADO ---\n");
    printf("O R4 deve ser cerca de 10-15%% mais rapido que o R2/R3 no aleatorio\n");
    printf("devido ao uso do Insertion Sort nas pontas.\n");

    free(vetorMestre);
    return 0;
}