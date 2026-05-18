#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define TAMANHO 100000 // Teste com 100 mil elementos

/**
 * Merge Sort (O(N log N))
 * - Estável (mantém a ordem de iguais)
 * - Previsível (sempre leva o mesmo tempo)
 * - Usa memória auxiliar O(N)
 */
void mergeSort(float v[], float vaux[], int inicio, int fim)
{
    int meio, i, j, k;

    if (inicio < fim)
    {
        meio = (inicio + fim) / 2;

        // Chamada recursiva para dividir
        mergeSort(v, vaux, inicio, meio);
        mergeSort(v, vaux, meio + 1, fim);

        // --- INTERCALAÇÃO (MERGE) ---
        i = inicio;
        j = meio + 1;
        k = inicio;

        // Loop principal: compara os dois lados
        while ((i <= meio) && (j <= fim))
        {
            if (v[i] <= v[j]) // Usar <= garante a ESTABILIDADE do algoritmo
            {
                vaux[k] = v[i];
                i++;
            }
            else
            {
                vaux[k] = v[j];
                j++;
            }
            k++;
        }

        // Copia o resto da esquerda (se sobrou)
        while (i <= meio)
        {
            vaux[k] = v[i];
            i++;
            k++;
        }

        // Copia o resto da direita (se sobrou)
        while (j <= fim)
        {
            vaux[k] = v[j];
            j++;
            k++;
        }

        // Copia do auxiliar de volta para o original
        for (k = inicio; k <= fim; k++)
        {
            v[k] = vaux[k];
        }
    }
}

// --- FUNÇÕES AUXILIARES PARA O TESTE ---

void preencherAleatorio(float *vetor, int size)
{
    for (int i = 0; i < size; i++)
    {
        vetor[i] = (float)(rand() % 100000);
    }
}

bool estaOrdenado(float *vetor, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (vetor[i] > vetor[i + 1])
            return false;
    }
    return true;
}

int main()
{
    // Alocação dinâmica para suportar vetores grandes sem estourar a stack
    float *vetor = (float *)malloc(TAMANHO * sizeof(float));

    // IMPORTANTE: O Merge Sort precisa de um vetor auxiliar do mesmo tamanho.
    // Alocamos ele UMA vez aqui fora para não alocar dentro da recursão.
    float *vetorAux = (float *)malloc(TAMANHO * sizeof(float));

    if (!vetor || !vetorAux)
    {
        printf("Erro de memoria!\n");
        return 1;
    }

    srand(time(NULL));

    printf("--- TESTE MERGE SORT ---\n");
    printf("Tamanho: %d elementos\n", TAMANHO);

    printf("Preenchendo...\n");
    preencherAleatorio(vetor, TAMANHO);

    printf("Ordenando...\n");
    clock_t t_inicio = clock();

    // Chamada inicial
    mergeSort(vetor, vetorAux, 0, TAMANHO - 1);

    clock_t t_fim = clock();
    double tempo = (double)(t_fim - t_inicio) / CLOCKS_PER_SEC;

    printf("Tempo gasto: %f segundos\n", tempo);

    printf("Verificando integridade...\n");
    if (estaOrdenado(vetor, TAMANHO))
    {
        printf("SUCESSO: Vetor ordenado corretamente!\n");
    }
    else
    {
        printf("ERRO: O vetor NAO esta ordenado.\n");
    }

    // Liberar memória
    free(vetor);
    free(vetorAux);

    return 0;
}