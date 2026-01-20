# 4.1 Escreva o código para a função soma, vista anteriormente.

def soma(lista):
    # 1) definir o caso base:
    if lista == []:
        return 0
    
    # 2) Caso recursivo:
    return lista[0] + soma(lista[1:]) #Pega o primerio elemento e soma com o resto da lista 

lista = [2, 4, 6, 3, 24, 56, 244]
#print(soma(lista))

# 4.2 Escreva uma função recursiva que conte o número de itens em uma lista

def conte(lista):
    #caso base
    if lista == []:
        return 0
    #caso recursivo
    return 1 + conte(lista[1:])

#print(conte(lista))

# 4.3 Encontre o valor mais alto em uma lista

def maximo(lista):
    if len(lista) == 2: # se so sobraram 2 entao verifica qual o maior
        # Retorne o item lista[0], se o primeiro item for maior maior que o segundo, senao retorne o segundo
        return lista[0] if lista[0] > lista[1] else lista[1]
    sub_max = maximo(lista[1:])
    return lista[0] if lista[0] > sub_max else sub_max


print(maximo(lista))

# 4.4 Determine o caso base e o caso recursivo para o algoritimo de pesquisa binaria

# Caso base: Array com pelo menos 1 elemento
# Caso recursivo: Se o item buscado for igual ao comparado, é o item procurado
#caso contrario, nao esta presente no array