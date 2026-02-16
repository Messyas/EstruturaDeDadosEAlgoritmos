def soma(a, b):
    return a + b

#packing

#desempacotar a lista L utilizando seus valores como 
#parametros para a funcao
L = [2, 3]
soma(*L)


#unpacking
#Podemos fazer várias chamadas a uma funcao dentro de um for
def barra(n=10, c = '*'):
    print(c*n)

Li = [[5, '-'], [10, '*'], [5], [6, '.']]

for e in Li:
    barra(*e)

#podemos criar uma funca que receba um num indeterminado
#de parametros utilizando listas

#o operador empacota todos os argumentos posicionais
#extras em uma tupla dentro da funcao, args é uma tupla
#args pode conter qualquer quantidade de valores
def soma(*args): 
    s = 0
    for x in args:
        s += x
    return s

print(soma(1, 2))
print(soma(2))
print(soma(5,6,7,8))
print(soma(10, 20, 30, 40, 50, 60, 70, 80, 90))

#existe tambem **kwargs
#empacota argumetnos nomeados em um dicionario (dict)

def exemplo(**kwargs):
    print(kwargs)

exemplo(a=1, b=2)