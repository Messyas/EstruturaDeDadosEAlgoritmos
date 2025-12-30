\*
Fazer um programa que leia uma palavra. O programa deve verificar se ela é um 
Palíndromo. (Palíndromo é uma palavra que é igual quando lida de 
trás para frente. Ex: "ANA", "OSSO", "RADAR").
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool checkPalindrome (char *word) {
    int start = 0;
    int end = strlen(word) - 1;

    //two pointers
    while (start < end) {
        if(word[start] != word[end]) {
            return false;
        }

        start++;
        end--;
    }

    return true;
}

int main () {
    char word[50];
    bool result = false; 

    printf("Digite uma palavra para verificar se e palindromo: \n");
    scanf("%s", word);

    result = verifyIfIsPalindromo(word);

    if (result == false) {
        printf("Nao e palindroma! \n");
    } else {
        printf("A palavra e palindroma! \n");
    }

return 0;
}