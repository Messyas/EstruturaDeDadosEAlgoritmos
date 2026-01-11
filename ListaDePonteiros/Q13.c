/*
Elabore uma função que receba duas strings como parâmetros e verifique se 
a segunda string ocorre dentro da primeira. Use aritmética
de ponteiros para acessar os caracteres das strings.
*/

#include <stdio.h>
#include <stdlib.h>

int isIn(char *frase, char *palavra) {
    while (*frase != '\0') {
        char *pFrase = frase;
        char *pPalavra = palavra;

        while (*pFrase == *pPalavra && *palavra != '\0') {
            pFrase++;
            pPalavra++;
        }

        if(*pPalavra == '\0') {
            return 1;
        }
        frase++;
    }
    return 0;
}

int main() {
    char frase[] = "O rato roeu a roupa";
    char palavra[] = "roeu";

    if (isIn(frase, palavra)) {
        printf("A palavra '%s' esta contida na frase.\n", palavra);
    } else {
        printf("Nao encontrou.\n");
    }
    return 0;
}