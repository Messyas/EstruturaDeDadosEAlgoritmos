/**
 * Recursividade veio da matemativa
 * Exemplo de fatorial
 * f(x)={ f(x-1) * x > 0 }
 *      { 1        x == 0} ops: otimizando poderia ser x <= 1 pra nao calcular ate 0 sem necessidade
 *
 * f(5)=f(4)*5= <- OPS NAO DA PRA CONTINUAR SEM SABER F(4)
 * f(4)=f(3)*4= <- entao teve que se criar uma nova instancia para calcular
 * f(3)=f(2)*3= <- isso continuou porque ainda existem operacoes possiveis
 * f(2)=f(1)*2=
 * f(1)=f(0)*1=
 * f(0)=1
 *
 * E agora podemos voltar respondendo as questoes que tinham dependencia:
 *
 * f(0)=1
 * f(1)=f(0)*1= 1*1 = 1
 * f(2)=f(1)*2= 1*2 = 2
 * f(3)=f(2)*3= 2*3 = 6
 * f(4)=f(3)*4= 4*6 = 24
 * f(5)=f(4)*5= 24*5 = 120
 *
 * funcao recursiva converte pra si mesma, ela é definida em funcao de si mesma
 *
 *  1. Tem que ter um caso recursivo, que deve convergir pra o ->
 *  2. Caso base, que é o caso de parada da funcao
 */

#include <stdio.h>

// Esta funcao utiliza loops
unsigned long fatorial(unsigned numero)
{
    unsigned long fat = 1;
    unsigned cont;

    for (cont = 2; cont <= numero; cont++)
    {
        fat = fat * cont;
    }
    return fat;
}

// esta funcao utiliza chamadas recursivas
/*
Como a abordagem recursiva utiliza variaveis LOCAIS que vao pra
pilha de execucao
*/
unsigned long fat(unsigned x)
{
    if (x > 1) // 1
    {
        return fat(x - 1) * x; // 2
    }
    return 1; // 3
}

int main()
{
    unsigned long valor;
    unsigned x;

    x = 5;          // 4
    valor = fat(x); // 5

    printf("fatorial de %u é: %lu\n", x, valor); // 6

    return 0; // 7
}

/*
Variaveis globais -> area estatica, junto com o codigo do programa
Variaveis locais, ficam em uma pilha de exeucucao

a pilha de chamada, no caso de variavel e funcoes (que nao deixam de ser tambem)
seguem a seguinte logica:
epilha a referencai, ve que tem uma outra operacao que é obrigatoria pra proxima etapa
entao salva o resultado futuro dessa chamada e chama a proxima etapa, isso acontece ate
terminar.

lado bom da recursividade: É utils para aprender a pensar sobre problemas recusivos
lado ruim: desempenho ruim
*/