#Pag 90
# Exercicio 4.8

#Criar uma tabala de multiplicacao com todos os elementos do array. 

def tabelas_de_multiplicacao(lista):
    #muiltiplicar cada numero por todos 2x4, 2x5 etc.
    #nested loop O(n^2)
    for i in lista:
        for j in lista:
            print(f"{i} X F{j} = {i * j}")
    

tabelas_de_multiplicacao([2, 4, 5, 6, 8])