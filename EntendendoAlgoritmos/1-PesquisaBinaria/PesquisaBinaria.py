def pesquisa_binaria(lista, item):
    baixo = 0
    alto =  len(lista) - 1
    while baixo <= alto:
        meio = (baixo + alto) // 2
        chute = lista[meio]
        if chute == item:
            return meio
        if chute > item:
            alto = meio - 1
        else:
            baixo = meio + 1
    return None
        
lista_ordernada = [1,2,3,4,5,6,7,8,9,10]
item_pesquisado = 9

item = pesquisa_binaria(lista_ordernada, item_pesquisado)
print(item)