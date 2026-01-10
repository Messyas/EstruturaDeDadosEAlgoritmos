int main () {

    //declaracao das variaveis
    int integer = 5;
    float decimal = 10.50;
    char character = "M";

    // declaracao dos pointers
    int *interger_pointer;
    float *decimal_pointer;
    char *character_pointer;

    printf("Integer %d\n", integer);
    printf("Decimal %f\n", decimal);
    printf("Char %c\n", character);

    //associando os ponteiros com as variaveis desejadas
    interger_pointer = &integer;
    decimal_pointer = &decimal;
    character_pointer = &character_pointer;

    printf("%i", "Pointer Inteiro", interger_pointer);
    printf("%d", "Pointer Decimal", decimal_pointer);
    printf("%c", "Pointer Character", character_pointer);






    return 0;
}