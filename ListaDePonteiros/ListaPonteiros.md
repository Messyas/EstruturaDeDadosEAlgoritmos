Este material foi retirado de um pdf publico da UFU:

Universidade Federal de Uberlandia - UFU E+
Faculdade de ComputacA,ao - FACOM Eo
Lista de exercA'Žñcios de programacA,ao em linguagem C

ExercA-cios: Ponteiros

1) Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro, real, e char. Associe as variA­veis aos ponteiros (use &). Modifique os valores de cada variA­vel usando os ponteiros. Imprima os valores das variA­veis antes e apA3s a modificaAœo.
2) Escreva um programa que contenha duas variA­veis inteiras. Compare seus endereAos e exiba o maior endereAo.
3) Escreva um programa que contenha duas variA­veis inteiras. Leia essas variA­veis do teclado. Em seguida, compare seus endereAos e exiba o conteA§do do maior endereAo.
4) FaAa um programa que leia 2 valores inteiros e chame uma funAœo que receba estas 2 variA­veis e troque o seu conteA§do, ou seja, esta funAœo Ac chamada passando duas variA­veis A e B por exemplo e, apA3s a execuAœo da funAœo, A conterA­ o valor de B e B terA­ o valor de A.
5) FaAa um programa que leia dois valores inteiros e chame uma funAœo que receba estes 2 valores de entrada e retorne o maior valor na primeira variA­vel e o menor valor na segunda variA­vel. Escreva o conteA§do das 2 variA­veis na tela.
6) Elaborar um programa que leia dois valores inteiros (A e B). Em seguida faAa uma funAœo que retorne a soma do dobro dos dois nA§meros lidos. A funAœo deverA­ armazenar o dobro de A na prA3pria variA­vel A e o dobro de B na prA3pria variA­vel B.
7) Crie um programa que contenha uma funAœo que permita passar por parA›metro dois nA§meros inteiros A e B. A funAœo deverA­ calcular a soma entre estes dois nA§meros e armazenar o resultado na variA­vel A. Esta funAœo nAœo deverA­ possuir retorno, mas deverA­ modificar o valor do primeiro parA›metro. Imprima os valores de A e B na funAœo principal.
8) Crie um programa que contenha um array de float contendo 10 elementos. Imprima o endereAo de cada posiAœo desse array.
9) Crie um programa que contenha uma matriz de float contendo 3 linhas e 3 colunas. Imprima o endereAo de cada posiAœo dessa matriz.
10) Crie um programa que contenha um array de inteiros contendo 5 elementos. Utilizando apenas aritmActica de ponteiros, leia esse array do teclado e imprima o dobro de cada valor lido.
11) Crie um programa que contenha um array contendo 5 elementos inteiros. Leia esse array do teclado e imprima o endereAo das posiAæes contendo valores pares.
12) FaAa um programa que leia trA¦s valores inteiros e chame uma funAœo que receba estes 3 valores de entrada e retorne eles ordenados, ou seja, o menor valor na primeira variA­vel, o segundo menor valor na variA­vel do meio, e o maior valor na A§ltima variA­vel. A funAœo deve retornar o valor 1 se os trA¦s valores forem iguais e 0 se existirem valores diferentes. Exibir os valores ordenados na tela.
13) Elabore uma funAœo que receba duas strings como parA›metros e verifique se a segunda string ocorre dentro da primeira. Use aritmActica de ponteiros para acessar os caracteres das strings.
14) Crie uma funAœo que receba dois parA›metros: um array e um valor do mesmo tipo do array. A funAœo deverA­ preencher os elementos de array com esse valor. NAœo utilize A-ndices para percorrer o array, apenas aritmActica de ponteiros.
15) Crie uma funAœo que receba como parA›metro um array e o imprima. NAœo utilize A-ndices para percorrer o array, apenas aritmActica de ponteiros.
16) Considere a seguinte declaraAœo: int A, *B, **C, ***D;. Escreva um programa que leia a variA­vel A e calcule e exiba o dobro, o triplo e o quA­druplo desse valor utilizando apenas os ponteiros B, C e D. O ponteiro B deve ser usada para calcular o dobro, C o triplo e D o quA­druplo.
17) Escreva uma funAœo que dado um nA§mero real passado como parA›metro, retorne a parte inteira e a parte fracionA­ria deste nA§mero. Escreva um programa que chama esta funAœo.
ProtA3tipo:Cvoid frac(float num, int* inteiro, float* frac);
18) Implemente uma funAœo que calcule a A­rea da superfA-cie e o volume de uma esfera de raio R. Essa funAœo deve obedecer ao protA3tipo:Cvoid calc_esfera(float R, float *area, float *volume)
A A­rea da superfA-cie e o volume sAœo dados, respectivamente, por:$A = 4 * \pi * R^2$$V = \frac{4}{3} * \pi * R^3$
19) Escreva uma funAœo que aceita como parA›metro um array de inteiros com N valores, e determina o maior elemento do array e o nA§mero de vezes que este elemento ocorreu no array. Por exemplo, para um array com os seguintes elementos: 5, 2, 15, 3, 7, 15, 8, 6, 15, a funAœo deve retorna para o programa que a chamou o valor 15 e o nA§mero 3 (indicando que o nA§mero 15 ocorreu 3 vezes). A funAœo deve ser do tipo void.
20) Implemente uma funAœo que receba como parA›metro um array de nA§meros reais de tamanho N e retorne quantos nA§meros negativos hA­ nesse array. Essa funAœo deve obedecer ao protA3tipo:Cint negativos(float *vet, int N);
21) Escreva um programa que declare um array de inteiros e um ponteiro para inteiros. Associe o ponteiro ao array. Agora, some mais um (+1) a cada posiAœo do array usando o ponteiro (use *).
22) Crie uma funAœo para somar dois arrays. Esta funAœo deve receber dois arrays e retornar a soma em um terceiro array. Caso o tamanho do primeiro e segundo array seja diferente entAœo a funAœo retornarA­ ZERO (0). Caso a funAœo seja concluA-da com sucesso a mesma deve retornar o valor UM (1). Utilize aritmActica de ponteiros para manipulaAœo do array.
23) Escreva uma funAœo que retorna o maior valor de um array de tamanho N. Escreva um programa que leia N valores inteiros, imprima o array com k elementos por linha, e o maior elemento. O valor de k tambAcm deve ser fornecido pelo usuA­rio.
24) Escreva uma funAœo que receba um array de inteiros V e os endereAos de duas variA­veis inteiras, min e max, e armazene nessas variA­veis o valor mA-nimo e mA­ximo do array. Escreva tambAcm uma funAœo main que use essa funAœo.
25) FaAa um programa que possua uma funAœo para:
Ler 2 notas e retornA­-las por parA›metro (chamar uma funAœo dedicada a ler 2 notas vA­lidas e que devolver os 2 nA§meros lidos);
Calcular a mAcdia simples e a mAcdia ponderada e retornA­-las por parA›metro, onde a segunda nota tem peso 2.
FA3rmula mAcdia ponderada: (n1 + n2 * 2) / 3
26) Implemente uma funAœo que calcule as raA-zes de uma equaAœo do segundo grau do tipo $Ax^2 + Bx + C = 0$.
Lembrando que:$$X = \frac{-B \pm \sqrt{\Delta}}{2A}$$Onde:$$\Delta = B^2 - 4AC$$A variA­vel A tem que ser diferente de zero.Se $\Delta < 0$ nAœo existe real.Se $\Delta = 0$ existe uma raiz real.Se $\Delta >= 0$ existem duas raA-zes reais.Essa funAœo deve obedecer ao seguinte protA3tipo:Cint raizes(float A, float B, float C, float *X1, float *X2);
Essa funAœo deve ter como valor de retorno o nA§mero de raA-zes reais e distintas da equaAœo. Se existirem raA-zes reais, seus valores devem ser armazenados nas variA­veis apontadas por X1 e X2.
