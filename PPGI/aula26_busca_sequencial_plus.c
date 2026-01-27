/*
Faca uma funcao que receba como parametro um 
vetor de alunos (tipoaluno) e um nome para busca. A funcao deve
retornar -1 caso o aluno buscado nao exista no vetor, e retonrar a posicao
de ocorrencia em caso contraio.
*/

#include <stdio.h>
#include <string.h> 

typedef struct tipoAluno { 
    char nome[50];
    int matricula;
    char curso[30];
} tipoAluno;

int buscarAlunoSequencialmente(tipoAluno vetor[], 
                unsigned tamanhoVetor, 
                char chave[]) {
    unsigned cont;

    for (cont = 0; cont < tamanhoVetor; cont++) {
        if (strcmp(vetor[cont].nome, chave) == 0) { 
            return cont;
        }
    }
    return -1;
}

int main() {
    tipoAluno alunos[7]; 

    strcpy(alunos[0].nome, "Maria Joana");
    strcpy(alunos[0].curso, "CC");

    strcpy(alunos[1].nome, "Messyas");
    strcpy(alunos[1].curso, "ADS");

    strcpy(alunos[2].nome, "solanna");
    strcpy(alunos[2].curso, "Psescotapa");

    for(int i = 0; i < 3; i++) {
        alunos[i].matricula = i;
    }

    char nome[] = "Messyas"; 
    char *chave = nome; 
    
    int pos = buscarAlunoSequencialmente(alunos, 3, chave);

    if (pos != -1) {
        printf("Curso: %s\n", alunos[pos].curso);
        printf("Matricula: %d\n", alunos[pos].matricula); 
    } else {
        printf("Aluno nao encontrado \n");
    }

    return 0;
}