import entrada
L = []

for x in range(10):
    L.append(entrada.valida("Entre um numero: ", 0, 20))
print("Soma: %d % (sum(L))")