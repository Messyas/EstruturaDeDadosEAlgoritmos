# 1)

# O Grafo (com pesos/distâncias)
grafo = {}
grafo["inicio"] = {}
grafo["inicio"]["a"] = 6
grafo["inicio"]["b"] = 2

grafo["a"] = {}
grafo["a"]["fim"] = 1

grafo["b"] = {}
grafo["b"]["a"] = 3
grafo["b"]["fim"] = 5

grafo["fim"] = {} # O nó final não tem vizinhos

# Tabela de Custos (iniciando com o que já sabemos do início)
infinito = float("inf")
custos = {}
custos["a"] = 6
custos["b"] = 2
custos["fim"] = infinito

# Tabela de Pais (para reconstruir o caminho depois)
pais = {}
pais["a"] = "inicio"
pais["b"] = "inicio"
pais["fim"] = None

# Lista de processados
processados = []


# 2) Calcula o menos custo entre as arestas

def ache_no_custo_mais_baixo(custos):
    custo_mais_baixo = float("inf")
    nodo_custo_mais_baixo = None
    
    for nodo in custos:
        custo = custos[nodo]
        # Verifica se é o menor custo E se ainda não foi processado
        if custo < custo_mais_baixo and nodo not in processados:
            custo_mais_baixo = custo
            nodo_custo_mais_baixo = nodo
            
    return nodo_custo_mais_baixo # O return tem que ser FORA do for!


# 3) ALGORITMO DE DIJKSTRA

# Passo 1: Pegar o nó mais barato não processado
nodo = ache_no_custo_mais_baixo(custos) 

while nodo is not None:
    custo = custos[nodo]
    vizinhos = grafo[nodo]
    
    # Passo 2: Percorrer os vizinhos
    for n in vizinhos.keys():
        novo_custo = custo + vizinhos[n]
        
        # Passo 3 e 4: Se for mais barato chegar no vizinho por aqui, atualiza
        if custos[n] > novo_custo:
            custos[n] = novo_custo
            pais[n] = nodo
            
    # Passo 5: Marca como processado
    processados.append(nodo)
    
    # Passo 6: Pega o próximo nó para repetir o loop
    nodo = ache_no_custo_mais_baixo(custos)

# --- 4. RESULTADO ---

print(f"Custo mínimo até o fim: {custos['fim']}")
print(f"Caminho reverso (pais): {pais}")