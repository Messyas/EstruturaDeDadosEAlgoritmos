#fibo é dado por f = n-1 + n-2
# ex de saida: 1 1 2 3 5 8 13 21

#exemplo sub-otimo
#Esta inplementacao tem complexidade de tempo O(n^2) e Espacial O(n)
def fibonacci(n):
    # caso base
    if n in [1, 2]:
        return 1
    # caso recursivo
    return fibonacci(n-1) + fibonacci(n-2)


for i in range(1, 10):
    print(fibonacci(i))

#Metodo Otimizado
#dynamic programming
from functools import lru_cache

@lru_cache(maxsize=None)
def fibonacci_memo(n):
    if n in [1, 2]:
        return 1
    return fibonacci_memo(n-1) + fibonacci_memo(n-2)

for i in range(1, 10):
    print(fibonacci_memo(i))

#Exemplo com loop - iteracao
#Util necesses casos para evitar esrourar a pilha (stackoverflow)
#Complexidade Linear O(n)
def fibonacci_iterativo(n):
    if n in [1, 2]:
        return 1
    a, b = 1, 1
    # Comeca a partir do terceiro elemento
    for _ in range(3, n + 1):
        a, b = b, a + b # tupla temporaria, assim nao precisa de uma variavel temporaria dedicada
    return b

for i in range(1, 10):
    print(fibonacci_iterativo(i))