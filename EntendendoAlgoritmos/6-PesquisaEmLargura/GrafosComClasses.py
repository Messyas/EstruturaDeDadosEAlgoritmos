from collections import deque

# 1.Definindo a "Estrutura do Vértice (Nós)"

class Pessoa: 
    def __init__(self, nome):
        self.nome = nome
        self.amigos = [] #lista de adjacencia, dentro do objeto
    
    def adicionar_amigos(self, lista_de_amigos):
        self.amigos.extend(lista_de_amigos)
    
    def __repr__(self):
        return f"Pessoa(self.nome)"
    
# 2. Criando os Vértices (as "bolinhas" do grafo)
# Note que primeiro criamos as pessoas, para depois conectá-las
voce = Pessoa("voce")
alice = Pessoa("alice")
bob = Pessoa("bob")
claire = Pessoa("claire")
anuj = Pessoa("anuj")
peggy = Pessoa("peggy")
thom = Pessoa("thom")
jonny = Pessoa("jonny")

# 3. Criando as Arestas (as conexões)
# Em vez de strings, estamos adicionando os OBJETOS reais na lista
voce.adicionar_amigos([alice, bob, claire])
bob.adicionar_amigos([anuj, peggy])
alice.adicionar_amigos([peggy])
claire.adicionar_amigos([thom, jonny])
# anuj, peggy, thom e jonny não têm amigos (são o fim da linha)

def pessoa_for_vendedor(pessoa):
    return pessoa.nome[-1] == 'm'

def pesquisa_bfs(pessoa_inicial):
    #Deque com o objeto inicial
    fila = deque()
    fila.append(pessoa_inicial)

    #set para guardar objetos ja visitados
    visitados = set()
    visitados.add(pessoa_inicial)

    while fila:
        pessoa_atual = fila.popleft()

        #verifica se é vendedor
        if pessoa_for_vendedor(pessoa_atual):
            print(f"{pessoa_atual.nome} é um vendedor de manga!")
            return True
        
        #adiciona os amigos (que ja sao objetos) na fila

        for amigo in pessoa_inicial.amigos:
            if amigo not in visitados:
                visitados.add(amigo)
                fila.append(amigo)
    return False

#Executado
pesquisa_bfs(voce)                