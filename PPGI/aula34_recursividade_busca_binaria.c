
// busca binaria com recursao ao inves de loop, uma versao piorada pra memoria
int buscaBinaria(float vetor[], int inicio, int fim, float chave)
{
    int meio;
    if (inicio <= fim)
    {
        meio = (inicio + fim);
        if (chave > vetor[meio])
        {
            return buscaBinaria(vetor, meio + 1, fim, chave);
        }
        else if (chave < vetor[meio])
        {
            return buscaBinaria(vetor, meio - 1, fim, chave);
        }
    }
    return 0;
}
//esse tempo é logaritimico, nao é tao ruim porque ela divide o numero de operacoes
//mas com loop ainda gasta menos memo

int main()
{

    return 0;
}