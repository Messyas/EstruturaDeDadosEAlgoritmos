#include <stdio.h>

int main () {

    int first = 10;
    int second = 20;

    int *first_ptr = &first;
    int *second_ptr = &second;
    
    // Imprimindo para você visualizar o que está acontecendo
    printf("Endereco de first:  %p\n", (void*)first_ptr);
    printf("Endereco de second: %p\n", (void*)second_ptr);

    // Comparação de ENDEREÇOS (sem o *)
    // Quem foi criado primeiro geralmente tem o maior endereço na Stack
    if (first_ptr > second_ptr) {
        printf("\nO maior endereco e o da variavel 'first': %p\n", (void*)first_ptr);
    } else {
        printf("\nO maior endereco e o da variavel 'second': %p\n", (void*)second_ptr);
    }

    return 0;
}