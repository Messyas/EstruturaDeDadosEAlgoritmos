#include <stdio.h>
#include <string.h>

/*
 INSERTION SORT

 1. Dado um vetor
 2. Escolha um pivô (Na verdade, o pivô é sempre o "próximo elemento" da fila, o valor (i))
    EXPANSÃO: Diferente do QuickSort onde o pivô pode ser o meio, aqui o pivô é a "carta"
    que você acabou de pegar da mesa e quer inserir na sua mão.
 3. Pegue um valor antes do pivô, um valor (j)
 4. Compare o i com o j, se o vetor[j] for maior que o pivô, ande pra tras ate achar um valor menor que o seu pivô.
    EXPANSÃO: "Andar para trás" aqui significa copiar o valor de [j] para [j+1],
    abrindo um buraco para o nosso pivô entrar depois.

 Tempo de execução:
    Pior caso (lista invertida): O(n^2) - Lento.
    Melhor caso (lista já ordenada): O(n) - Muito rápido! (Isso é um grande diferencial).
*/

void ordernarPorInsercao(float vetor[], unsigned tamanhoDoVetor)
{
    int i, j;
    float pivo; // O pivô deve ser do tipo do elemento (float), não o índice.

    // Começamos do 1, pois assumimos que o elemento 0 já é uma "lista ordenada de 1 item"
    for (i = 1; i < tamanhoDoVetor; i++)
    {
        pivo = vetor[i]; // Guardamos o valor que queremos inserir na parte ordenada
        j = i - 1;       // Começamos a comparar com o vizinho imediato à esquerda

        // Enquanto não chegarmos no início (j >= 0) E o elemento analisado for MAIOR que o nosso pivô...
        // Nota: Use j >= 0 ao invés de j > 0 para garantir que ele verifique o primeiro elemento (índice 0)
        while ((j >= 0) && (vetor[j] > pivo))
        {
            vetor[j + 1] = vetor[j]; // SHIFT: Empurramos o valor grande para a direita
            j--;                     // Recuamos para checar o próximo
        }

        // Achamos o lugar (ou chegamos em -1). Inserimos o pivô no "buraco" que sobrou à frente de j.
        vetor[j + 1] = pivo;
    }
}

// Definição da struct
typedef struct
{
    unsigned int matricula;
    char nome[50];
    char curso[50];
} tipoAluno;

void ordernarPorInsercaoAlunos(tipoAluno vetor[], unsigned tamanhoDoVetor)
{
    int i, j;       // Use int para j, pois ele pode chegar a -1
    tipoAluno pivo; // O PIVÔ PRECISA SER DO TIPO DA ESTRUTURA

    for (i = 1; i < tamanhoDoVetor; i++)
    {
        pivo = vetor[i]; // Copia a struct inteira (Matrícula, Nome, Curso) para a memória temporária
        j = i - 1;

        // Comparação:
        // strcmp(A, B) > 0 significa que A vem DEPOIS de B alfabeticamente.
        // Então: "Enquanto o nome do aluno anterior (vetor[j]) for 'maior' que o meu pivo..."
        while ((j >= 0) && (strcmp(vetor[j].nome, pivo.nome) > 0))
        {
            vetor[j + 1] = vetor[j]; // Copia a struct do vetor[j] para a direita. Custo de cópia alto!
            j--;
        }

        vetor[j + 1] = pivo; // Encaixa o aluno na posição correta
    }
}

// Funções auxiliares para ver rodando
void imprimirFloats(float vetor[], unsigned tamanho)
{
    printf("[ ");
    for (unsigned k = 0; k < tamanho; k++)
        printf("%.1f ", vetor[k]);
    printf("]\n");
}

void imprimirAlunos(tipoAluno vetor[], unsigned tamanho)
{
    for (unsigned k = 0; k < tamanho; k++)
        printf(" - %s (%s)\n", vetor[k].nome, vetor[k].curso);
}

int main()
{
    // --- Teste 1: Floats ---
    printf("--- Teste Float ---\n");
    float notas[] = {7.5, 2.0, 10.0, 4.5, 8.0, 2.0};
    unsigned tamNotas = sizeof(notas) / sizeof(notas[0]);

    imprimirFloats(notas, tamNotas);
    ordernarPorInsercao(notas, tamNotas);
    imprimirFloats(notas, tamNotas);

    // --- Teste 2: Alunos ---
    printf("\n--- Teste Alunos (Struct) ---\n");
    tipoAluno turma[] = {
        {101, "Zelia", "Artes"},
        {102, "Bruno", "TI"},
        {103, "Ana", "Medicina"},
        {104, "Carlos", "Engenharia"}};
    unsigned tamTurma = sizeof(turma) / sizeof(turma[0]);

    printf("Antes:\n");
    imprimirAlunos(turma, tamTurma);

    ordernarPorInsercaoAlunos(turma, tamTurma);

    printf("Depois (Ordenado por Nome):\n");
    imprimirAlunos(turma, tamTurma);

    return 0;
}