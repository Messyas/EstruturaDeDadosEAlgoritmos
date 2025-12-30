#include <stdio.h>
#include <stdbool.h>

int main()
{
    typedef struct {
        float altura;
    } Pessoa;
    
    Pessoa usuario;
    int menor_altura = 10.0;
    
    while(true) {
        printf("Digite sua altura:");
        scanf("%f", &usuario.altura);
        
        if (usuario.altura == 0) {
            break;
        }
        
        if (usuario.altura < menor_altura) {
            menor_altura = usuario.altura;
        }
    }
    
    printf("Menor altura encontrada:", menor_altura);
    
    return 0;
}   