/**
 * NOTA: Essa aula dele ta melhor que a do livro entendendo algoritmos
 * Algoritmo inventado na decada de 60
 *
 *
 * 1. vai definir um pivor, pra poder dividir o vetor em dois lados
 * os que sao menores que o pivor e os que sao maiores que o pivor.
 * 2. Ordenar a primeira particao, depois ordena a segunda particao.
 *
 */

/**
 * Como particionar da melhor forma?
 *
 * Crie dois indices (two poiters)
 *
 *  1. [i] <- Comeca na posicao 0
 *  2. [j] <- Comeca no fim do vetor
 *
 *  - O objetivo do i é encontrar o "lado" errado dos elementos que
 *  sao MENORES que o pivor.
 *  - Ja o do j é encontrar os que sao maiores.
 *
 *  Se o elemento estiver no lugar errado, por exemplo, se o j for menor que o pivor
 *  ele troca de valor com o i e segue. A ideia é ir balanceando os dois intervalos
 *
 *  A ideia é eles irem se aproximando, encurtando
 * a linha do intervalo total do vetor.
 *
 *  QUANDO TERMINAR - BOOM - acabou o algoritmo de particao
 *
 *  Agora, o algorimo roda novamente com as particoes
 *  e assim segue recursivamente, ordenando varios intervalos cada vez menores
 *  no final o algorimo retorna um vetor ordenado.
 *
 */

void quicksort(float v[], int inicio, int fim)
{
    int i, j;
    float pivot; // do mesmo tipo da minha chave de ordenacao (ou dos elementos de v)
    float tmp;   // dos mesmo tipo dos elementos do vetor

    if (inicio < fim)
    {
        // particiona o vetor
        pivot = v[(inicio + fim) / 2];
        i = inicio;
        j = fim;
        while (i <= j)
        {
            while (v[i] < pivot)
            {
                i++; // avanca enquanto esta do lado certo
            }
            while (v[j] > pivot)
            {
                j--; // recua enquanto esta do lado certo
            }
            if (i <= j)
            {
                tmp = v[i];
                v[i] = v[j];
                v[j] = tmp;
                i++;
                j--;
            }
        }
        quicksort(v, inicio, j);
        quicksort(v, i, fim);
    }
}

int main()
{
    float vetorDesordenado[] = {7, 500, 600, 450, 200, 8, 500, 1000};
    int inicio, fim;
    inicio = vetorDesordenado[0];
    fim = vetorDesordenado[7];
    quicksort(vetorDesordenado, inicio, fim);

    return 0;
}

// quase sempre o melhor
// em poucos casos pode perder pro ordenacao por selecao ou pro heapsort
// Uma avaliacao interessnate é que como o quick sort divide o vetor em
// 2, se o pivor for ruim pode acontecer desses intervalos serem desbalanceados
// entao vai ficar com um lado parado porque ordenou rapido o so de um lado
// vai fazer uma operacao gigante.
// um pivor bom é quando metade dos elementos é menor que ele e
// a outra metade é maior que ele.

// no pior caso é quadratico o(n^2)
// no melhor caso é o(N log N)
// melhor que ordenacao por selecao por exemplo

//Projeto e analise de algorimo daria pra avaliar o custo do algoritmo.