/**
 * Faça uma funcao que receba dois vetores ardenados, com seus respectivos
 * tamanhos, e um terceiro veto que sabe-se que tem tamanho maior que a soma dos tamanhos
 * dos dois primeiros. A funcao copia para o terceiro vetor o conteudo dos dois primerios vetores
 * de maneira que o terceiro tenha a uniao dos elementos dos dois primeiros e esteja ordenado.
 * Use o algorimo de intercalacao para isso.
 */

/**
 * Intercalacao (Merge)
 * Um problema onde tem 1 vetor ordenado e outro veto ordenado
 * Eu quero gerar um novo vetor ordenado a partir dos dois
 * Quando os dois estao ordenaods, pode-se usar um algorimo chamado
 * Intercalacao de vetores
 *
 */

void intercala(float v1[], unsigned tamV1, float v2[], unsigned tamV2, float aux[])
{
    unsigned i, j, k;
    i = 0;
    j = 0;
    k = 0; // i = j = k = 0 se tu quiser ficar calvo

    // 1) Enquanto o tamanho total dos 2 vetores nao forem percorridos
    while ((i < tamV1) && (j < tamV2))
    {
        if (v1[i] < v2[j])
        {
            aux[k] = v1[i];
            i++;
        }
        else
        {
            aux[k] = v2[j];
            j++;
        }
        k++;
    }

    while (i < tamV1)
    {
        aux[k] = v1[i];
        i++;
        k++;
    }

    while (i < tamV2)
    {
        aux[k] = v2[i];
        i++;
        k++;
    }
}

// se quiser da pra substituir k por i + j, mas pra fins didaticos eu resolvi deixar.

int main()
{
    int vetor1[] = {1, 10, 20, 40, 50};
    int vetor2[] = {2, 30, 60, 80, 400, 500};

    return 0;
}