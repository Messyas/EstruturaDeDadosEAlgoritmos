#include <stdio.h>
#include <string.h> // Necessário para usar strcmp (comparar strings)

// Definição do nosso tipo complexo
typedef struct {
    unsigned int matricula;
    char nome[50];
    char curso[50];
} tipoAluno;

/*
SELECTION SORT (Versão Struct)

Este algoritmo é excelente quando o custo de escrever na memória é alto ou
quando os objetos sendo movidos são grandes (como esta struct).

Por que?
Diferente do Bubble Sort, que ficaria copiando esses dados de "Nome" e "Curso"
pra lá e pra cá o tempo todo, o Selection Sort identifica o destino final
e faz a movimentação (cópia pesada) apenas UMA vez por iteração.
*/

void selectionSortAlunos(tipoAluno vetor[], unsigned tamanhoVetor) {
    unsigned penultimo = tamanhoVetor - 1;
    tipoAluno temp; // A variável temporária agora deve ser do tipo da struct
    unsigned i, cont;
    unsigned posMenor;
    
    for (i = 0; i < penultimo; i++) {
        posMenor = i;
        
        for (cont = i + 1; cont < tamanhoVetor; cont++) {
            // CRITÉRIO DE COMPARAÇÃO:
            // Usamos strcmp. Se o resultado for < 0, significa que vetor[cont].nome
            // vem antes (alfabeticamente) de vetor[posMenor].nome.
            // Se quisesse ordenar por matrícula, seria: if (vetor[cont].matricula < vetor[posMenor].matricula)
            if (strcmp(vetor[cont].nome, vetor[posMenor].nome) < 0) {
                posMenor = cont;
            }
        }
        
        // TROCA (SWAP):
        // Aqui o benefício do Selection Sort brilha. Estamos copiando
        // cerca de 104 bytes (tamanho da struct) de uma vez.
        // Fazer isso poucas vezes é essencial.
        if (posMenor != i) {
            temp = vetor[i];            // Copia o aluno inteiro para o temp
            vetor[i] = vetor[posMenor]; // Copia o aluno menor para a posição i
            vetor[posMenor] = temp;     // Copia o temp para a antiga posição do menor
        }
    }
}

void imprimirTurma(tipoAluno vetor[], unsigned tamanho) {
    printf("-------------------------------------------------------\n");
    printf("%-10s | %-20s | %s\n", "MATRICULA", "NOME", "CURSO");
    printf("-------------------------------------------------------\n");
    for (unsigned i = 0; i < tamanho; i++) {
        // %-20s alinha o texto à esquerda ocupando 20 espaços
        printf("%-10u | %-20s | %s\n", 
               vetor[i].matricula, 
               vetor[i].nome, 
               vetor[i].curso);
    }
    printf("-------------------------------------------------------\n");
}

int main (){
    // Criando uma turma desordenada
    tipoAluno alunos[] = {
        {202301, "Carlos Silva", "Engenharia"},
        {202305, "Ana Beatriz", "Arquitetura"}, // Deverá ser a primeira
        {202302, "Bruno Souza", "Fisica"},
        {202304, "Daniela Lima", "Matematica"},
        {202303, "Zeca Urubu", "Historia"},     // Deverá ser o último
        {202310, "Amanda Costa", "Design"}      // Deverá ser a segunda
    };

    unsigned tamanho = sizeof(alunos) / sizeof(alunos[0]);

    printf("\n>>> Turma Bagunçada:\n");
    imprimirTurma(alunos, tamanho);

    selectionSortAlunos(alunos, tamanho);

    printf("\n>>> Turma Ordenada por Nome:\n");
    imprimirTurma(alunos, tamanho);

    return 0;
}