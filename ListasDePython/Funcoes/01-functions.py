def maior (a, b):
    return a if a > b else b

def max_value(a, b):
    return max(a, b)

def isMultiplo(a, b):
    return a % b == 0

def area_quadrado(lado):
    if lado < 0:
        raise ValueError("O lado nao pode ser negativo")
    return lado ** 2
    
def area_triangulo(base, altura):
    return (base * altura) / 2

#pesquisa 
L = [10, 20, 25, 30]

def pesquisa (lista, valor):
    for x, e in enumerate(lista):
        if e == valor:
            return x
    return None

def soma (lista):
    total = 0
    for e in lista:
        total += e
    return total

def meida (lista):
    return (soma(lista)/len(lista))


print(maior(10, 4))
print(max_value(10, 4))
print(isMultiplo(10, 5))
print(area_quadrado(6))
print(area_triangulo(10, 7))
print((pesquisa(L, 25)))
