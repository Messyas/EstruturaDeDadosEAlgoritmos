#Qual seria o caso base para a Ordenacao de um array

#[] => []
#[i] => [i]
#[i, j] => [i, j] se i <= j ou [j, i] se j < i

def quicksort(lista):
    if len(lista) < 2:
        return lista
    
    meio = len(lista) // 2
    pivo = lista.pop(meio)
    menores = [i for i in lista if i <= pivo]
    maiores = [i for i in lista if i > pivo]

    return quicksort(menores) + [pivo] + quicksort(maiores)

print(quicksort([2, 5, 4, 1, 10, 20, 22, 42, 55, -13, -34, -34, 0, 123, 2424]))

#A complexidade desse algoritmo depende da escolha do pivo
#Caso ruim O(n^2)
#Caso otimo O(n log n)
