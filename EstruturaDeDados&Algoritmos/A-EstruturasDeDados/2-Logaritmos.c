/* MATERIAL DE APOIO: LOGARITMOS EM COMPUTAÇÃO E DSA
Autor: [Seu Nome]
Linguagem: C standard (C99 ou superior)
Compilação: gcc logs_dsa.c -o logs_dsa -lm (necessário flag -lm para math.h)

OBJETIVO:
Demonstrar programaticamente o que significa "complexidade logarítmica".
Em resumo: O logaritmo de N na base 2 é o número de vezes que precisamos 
dividir N pela metade até chegar a 1.
*/

#include <stdio.h>
#include <math.h>  // Necessário para funções log() e log2()

/*
  FUNÇÃO AUXILIAR: Simula um algoritmo O(log n)
  Esta função não usa matemática pronta. Ela conta quantas iterações
  são necessárias para reduzir 'n' a 1 dividindo-o sucessivamente por 2.
  
  Exemplo clássico de uso: Busca Binária.
*/
int calcular_log2_manual(long long n) {
    int operacoes = 0;
    long long valor_atual = n;

    // Enquanto o valor for maior que 1, dividimos ao meio (divisão inteira)
    while (valor_atual > 1) {
        valor_atual = valor_atual / 2;
        operacoes++;
    }
    return operacoes;
}

int main() {
    // ---------------------------------------------------------
    // 1. CONCEITO BÁSICO: A INVERSA DA EXPONENCIAÇÃO
    // ---------------------------------------------------------
    printf("=== 1. Conceito Basico ===\n");
    double n = 64.0;
    
    // log2(64) pergunta: "2 elevado a qual numero da 64?"
    // Resposta: 2^6 = 64, entao log2(64) = 6.
    double resultado = log2(n);
    
    printf("Entrada (N): %.0f\n", n);
    printf("Log base 2 de %.0f e: %.2f\n", n, resultado);
    printf("Isso significa que 2^%.0f = %.0f\n\n", resultado, n);

    // ---------------------------------------------------------
    // 2. INTUIÇÃO PARA DSA: O PODER DA DIVISÃO (HALVING)
    // ---------------------------------------------------------
    /*
      Aqui está a chave para entender Big O.
      Imagine que temos um array ordenado de 1.000.000 de elementos.
      Se usarmos Busca Binária, não percorremos 1 milhão de itens.
      A cada passo, cortamos o problema pela metade.
    */
    printf("=== 2. Intuicao DSA (O Loop de Divisao) ===\n");
    
    long long datasets[] = {8, 1024, 1048576, 1000000000}; // 8, 1K, 1M, 1B
    int qtd_datasets = 4;

    for(int i = 0; i < qtd_datasets; i++) {
        long long tamanho = datasets[i];
        int passos = calcular_log2_manual(tamanho);

        printf("Tamanho do input (N): %lld\n", tamanho);
        printf("Passos para chegar a 1 (dividindo por 2): %d\n", passos);
        printf("-> Complexidade O(log n) executaria aprox. %d instrucoes.\n", passos);
        printf("----------------------------------------------------\n");
    }

    /* OBSERVAÇÃO CRÍTICA PARA O ALUNO:
      Note como o input cresce absurdamente (de 8 para 1 Bilhão),
      mas o número de passos cresce muito pouco (de 3 para 29).
      É por isso que algoritmos O(log n) são extremamente eficientes.
    */

    // ---------------------------------------------------------
    // 3. OUTRAS APLICAÇÕES: DÍGITOS E ÁRVORES
    // ---------------------------------------------------------
    printf("\n=== 3. Outras Aplicacoes Praticas ===\n");

    // APLICACAO A: Altura de uma Árvore Binária Balanceada
    // Se você tem N nós, a altura mínima é log2(N).
    // Isso define o pior caso de busca em árvores balanceadas (AVL, Red-Black).
    long long nos = 100;
    printf("[Arvores] Uma arvore binaria com %lld nos tem altura aprox: %.0f\n", 
           nos, ceil(log2(nos)));

    // APLICACAO B: Contar dígitos de um número (Base 10)
    // log10(N) nos dá a magnitude do número. 
    // floor(log10(N)) + 1 = Quantidade de dígitos inteiros.
    long long numero_grande = 123456789;
    int digitos = (int)floor(log10(numero_grande)) + 1;
    
    printf("[Math Tricks] O numero %lld possui %d digitos (calculado via log10).\n", 
           numero_grande, digitos);

    return 0;
}