; Array.asm (Sintaxe Intel/NASM)

section .data
    ; Definição do Array na memória
    ; 'dd' significa "Define Doubleword" (4 bytes), igual ao 'int' em C
    numeros: dd 10, 20, 30

section .text
    global main

main:
    ; ACESSO AO ARRAY:
    ; Em C: return numeros[0];
    ; Em Assembly: Movemos o valor da memória para o registrador acumulador (EAX)
    
    ; [numeros] pega o valor no início do array (índice 0)
    mov eax, [numeros]
    
    ; Se quiséssemos o segundo valor (índice 1), teríamos que pular 4 bytes:
    ; mov eax, [numeros + 4] 

    ; 'ret' finaliza a função, retornando o valor que estiver em EAX
    ret