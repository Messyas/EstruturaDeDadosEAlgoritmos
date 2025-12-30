/*
Fazer um programa que leia uma palavra (max 50 letras) digitada pelo usuário.
O programa deve calcular o tamanho dessa palavra e imprimi-la de trás para frente.
*/

/**
Primeira resposta:

void printInvetedWord(char word[50]) {
    int length = strlen(word);
    printf("Palavra invetida: \n");

    for (int i = length - 1; i >= 0; i--) {
        printf("%c", word[i]);
    }
    printf("\n");
}

int main () {
char word[50];

printf("Digite qualquer palavra: \n");
scanf("%s", word);

printInvetedWord(word);

return 0;
}

*/

//Segunda resposta que utiliza "IN-PLACE" ou "troca" para trocar a posicao
//do caractere sem fazer uma copia, sendo mais performatico e economico em 
//termos de memoria.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// exemplo de como em pouscas iteracoes ja da pra inverter um array de caracteres
// [m] [e] [s] [s] [y] [a] [s]
// [s] [e] [s] [s] [y] [a] [m]
// [s] [a] [y] [s] [s] [e] [m]
void printInvetedWord(char word[]) {
   int start = 0;
   int end = strlen(word) - 1;
   char temp; //variavel auxiliar para troca

   while (  start < end  ) {
    temp = word[start]; //copia o valor do incio
    word[start] = word[end]; //sobrescreve o valor do inicio pelo o do fim
    word[end] = temp; //sobrescreve o valor do fim pelo o do incio

    //move os indices para o centro
    start++; //move pro proximo
    end--; //move pro anterior
   }
   printf("%s Inverted Word: ", word);
}

int main () {
char word[50];

printf("Digite qualquer palavra: \n");
scanf("%s", word);

printInvetedWord(word);

return 0;
}