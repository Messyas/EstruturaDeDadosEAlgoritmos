#Algoritmo de Ordenação
#Tempo se execucao O log(n^2) - Tempo Qruadratico

def busca_menor(lista):
    menor = lista[0] #Armazena o menor valor
    menor_indice = 0 #Armazena o índice do menor valor

    for i in range (1, len(lista)):
        if lista[i] < menor:
            menor = lista[i]
            menor_indice = i
    return menor_indice

def ordenacao_por_selecao(lista): #Recebe o array desordenado
    nova_lista = []
    for i in range(len(lista)):
        menor = busca_menor(lista) #pega o menor elemento do array
        nova_lista.append(lista.pop(menor)) #retira o menor elemento da lista e o coloca no final
    return nova_lista

print(ordenacao_por_selecao([30, 20, 10]))