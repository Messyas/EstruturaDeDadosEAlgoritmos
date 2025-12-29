/*8. Fazer um programa que leia o sexo (1=Masculino, 2=Feminino) e a altura de 
um conjunto de pessoas. O final do conjunto é determinado quando a altura digitada for 0.
Ao final, o programa deve calcular e mostrar: 
a) A média de altura das mulheres. 
b) A maior e a menor altura de todo o grupo.
*/
#include <stdio.h>
#include <stdbool.h>

// Boa prática: Struct fora da main
typedef struct {
    float altura;
    int sexo;
} Pessoa;

int main()
{
    Pessoa usuario;
    
    // Inicialização correta: cada variável recebe seu valor
    float total_altura_homens = 0;
    float total_altura_mulheres = 0;
    
    // Precisamos contar quantas pessoas de cada sexo para fazer a média depois
    int contagem_homens = 0;
    int contagem_mulheres = 0;

    // Inicializando Min e Max
    float maior_altura = 0.0;
    float menor_altura = 10.0; 

    while(true) {
        printf("Digite sua altura (0 para sair): ");
        scanf("%f", &usuario.altura);

        if (usuario.altura == 0) {
            break;
        }

        printf("Digite seu sexo (1-Masc, 2-Fem): ");
        scanf("%d", &usuario.sexo);

        if (usuario.altura < menor_altura) {
            menor_altura = usuario.altura;
        }
        if (usuario.altura > maior_altura) {
            maior_altura = usuario.altura;
        }

        // --- LÓGICA DE ACUMULAÇÃO
        if (usuario.sexo == 1) {
            total_altura_homens = total_altura_homens + usuario.altura;
            contagem_homens++;
        } 
        else if (usuario.sexo == 2) {
            total_altura_mulheres = total_altura_mulheres + usuario.altura;
            contagem_mulheres++;
        }
    }    
    // Média das mulheres (proteção contra divisão por zero)
    if (contagem_mulheres > 0) {
        float media_mulheres = total_altura_mulheres / contagem_mulheres;
        printf("\nMedia de altura das mulheres: %.2f", media_mulheres);
    }
    printf("\nMenor altura do grupo: %.2f", menor_altura);
    printf("\nMaior altura do grupo: %.2f", maior_altura);
    
    return 0;
}