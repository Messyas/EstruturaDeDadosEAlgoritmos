#Toda funcao recursiva deve ter uma condicao de parada

#Resulta em Loop Infinito
def regressiva_errada(i):
    print(i)
    return (i-1)

def regressiva_correta(i):
    print(i)
    if i <= 1:
        return
    else:
        regressiva_correta(i-1)

regressiva_correta(10)