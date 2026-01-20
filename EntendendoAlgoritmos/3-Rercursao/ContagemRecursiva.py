
# com iteracoa
def soma(lista):
    valor = 0
    for i in lista:
        valor += i
    return valor


#E com recursao?
#[] => 0
#[i] => i

def soma_recursiva(lista):
    if not lista:
        return 0
    return lista.pop(0) + soma_recursiva(lista)

print(soma_recursiva([1, 2, 3]))