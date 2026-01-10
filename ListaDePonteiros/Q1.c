#include <stdio.h> 

int main () {

    // declaracao das variaveis
    int integer = 5;
    float decimal = 10.50;
    char character = 'M';

    // declaracao dos pointers
    int *integer_pointer;
    float *decimal_pointer;
    char *character_pointer;

    printf("--- Valores Originais ---\n");
    printf("Integer: %d\n", integer);
    printf("Decimal: %f\n", decimal);
    printf("Char: %c\n\n", character);

    // associando os ponteiros com as variaveis
    integer_pointer = &integer;
    decimal_pointer = &decimal;
    character_pointer = &character;

    printf("--- Usando Ponteiros ---\n");
    
    // Para ver o VALOR guardado no endereço (Desreferência)
    // Usamos o * antes do nome do ponteiro para "acessar" o valor.
    printf("Valor via Ponteiro Integer: %d\n", *integer_pointer);
    printf("Valor via Ponteiro Decimal: %f\n", *decimal_pointer);
    printf("Valor via Ponteiro Char: %c\n", *character_pointer);

    // OPÇÃO B: Se você quer ver o ENDEREÇO de memória
    // Usamos %p (pointer) e o nome do ponteiro sem asterisco.
    printf("\n--- Enderecos de Memoria ---\n");
    printf("Endereco Integer: %p\n", (void*)integer_pointer);
    printf("Endereco Decimal: %p\n", (void*)decimal_pointer);
    printf("Endereco Char: %p\n", (void*)character_pointer);

    *integer_pointer = 10;
    *decimal_pointer = 22.20;
    *character_pointer = 's';

    printf("Integer: %d\n", integer);
    printf("Decimal: %f\n", decimal);
    printf("Char: %c\n\n", character);



    return 0;
}