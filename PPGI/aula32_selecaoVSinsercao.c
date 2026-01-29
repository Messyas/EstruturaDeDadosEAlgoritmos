/**
 * 1. Ordenação por Seleção (Selection Sort)
 * ---------------------------------------------------------
 * Comportamento: Procura o menor item e coloca na primeira posição.
 * Depois o segundo menor e coloca na segunda, e assim por diante.
 *
 * Cenário Visual (Vetor já ordenado):
 * | 20 | 100 | 150 | 200 | ...
 * O Selection Sort é "cego": mesmo vendo o vetor ordenado acima,
 * ele fará todas as comparações novamente.
 * * Custo (Complexidade de Tempo):
 * N + (N-1) + (N-2) + ... + 1 = (N^2 + N)/2  => O(N^2)
 *
 * nota: Essa formula é a soma de Gauss
 *
 * Ponto Forte (Why use it?):
 * - Faz o MÍNIMO de trocas (swaps) possíveis (O(N)).
 * - Útil quando a operação de ESCRITA na memória é muito cara,
 * mesmo que a comparação seja barata.
 * * ---------------------------------------------------------
 * * 2. Ordenação por Inserção (Insertion Sort)
 * ---------------------------------------------------------
 * Comportamento: Age como organizar cartas de baralho na mão.
 * Pega o próximo item e vai voltando ele até achar o lugar certo.
 * * Melhor Caso (Best Case - O(N)):
 * - Vetores já ordenados ou "quase" ordenados.
 * - O algoritmo apenas olha, vê que está no lugar certo e segue.
 * - É imbatível aqui, superando até QuickSort e MergeSort.
 *
 * Pior Caso (Worst Case - O(N^2)):
 * - Vetor em ordem decrescente (invertido).
 * - Ele terá que empurrar todo mundo para trás a cada inserção.
 * * Nota sobre Bibliotecas (Curiosidade):
 * Algoritmos híbridos como Timsort (Python/Java) e Introsort (C++)
 * usam o Insertion Sort internamente quando detectam partições
 * pequenas ou ordenadas, justamente para ganhar essa performance.
 */