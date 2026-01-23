#Grafo é um tipo de estrutura de dados utils para lidar com calculo de distancia
#por exemplo, saber o caminho mais curto para n lugar.
#É tambem utilizado para relacionar entidades, por exemplo, rede de amigos de redes sociais

#Processo para se inplementar um grafo em python
#crie uma tabela hash, porque com ela podemos usar uma pessoa como chave e outra como valor
grafo = {}
grafo["voce"] = ["alice", "bob", "claire"]
grafo["bob"] = ["anuj", "peggy"]
grafo["alice"] = ["peggy"]
grafo["claire"] = ["thom", "jonny"]
grafo["anuj"] = []
grafo["peggy"] = []
grafo["thon"] = []
grafo["jonny"] = []
#como as tablas hashes nao sao ordenadas, a ordem aqui nao vai fazer diferenca,
#lembre-se que aqui estamos criando verteces, so importa com quem e nao a ordem em si
#primerio crie uma lista

#contudo existem os dígrafos, que sao grafos onde existe direcao para onde as arestas
#apontam, eles sao representados com linhas com setas. Se nao for direcionado, nao tem seta.

#Esse exemplo a seguir se trata de um algoritmo de busca em largura
#Em ingles: Breadth-First Search - BFS
#Ele usa uma fila (FIFO)para gerenciar os nos,
#Ele visita todos os vizinhos (Vertices) antes 
#de ir para os vizinhos dos vizinhos
from collections import deque

def pessoa_for_vendedor(nome):
     return nome[-1] == 'm'

def pesquisa(nome):
    fila_de_pesquisa = deque() #lista de adjacencias, nesse caso as arestas sao implicitas
    fila_de_pesquisa += grafo[nome] #poderia usar um construtor de lista que seria igual
    #seria a mesma coisa fila.extend(grafo[pessoa])
    verificados = []
    while fila_de_pesquisa:
        pessoa = fila_de_pesquisa.popleft()
        if not pessoa in verificados:
            if pessoa_for_vendedor(pessoa):
                print(pessoa + " é um vendedor de mongá!")  
                return True
            else: 
                fila_de_pesquisa += grafo[pessoa]
                verificados.append(pessoa) 

    return False

print(pesquisa("voce"))

#esse tipo de pesquisa tem tempo de execucao dado de forma diferemte
#como voce cria uma nova lista para adicionar novas pessoas
#oq geralmente vai levar um tempo constante O(1). 
# Fazer isso pra cada pessoa era o tempo de execucuao O (numero de pessoas) no total.
# Entao a pesquisa em largura para este caso, tem tempo de execucao O (num de pessoas x num de arestas)
# Geralmente representado por O (V + A)



#Quando usar esse metodo com Dicionario (Hashtable)?
#Ele tam uma serie de vantagnes:
#1. É mais rapido de escrever
#2. Serializacao,é muito facil de salvar em um arquivo json e enviar pra uma api, pois é teto puro
#3. Simplicidade para testes tecnicos
#Desvantagens:
#1. A estrutura do objeto é simples aqui, entao representar uma entidade pode ficar mais dificil, 
# acessar atributos etc, o dicionario fica baguncado e voce precisa de sub grafos. Melhor usar classes

#usado para problemas de distancia minimas, pode ser usado para labirintos
#redes e problemas de fluxo
