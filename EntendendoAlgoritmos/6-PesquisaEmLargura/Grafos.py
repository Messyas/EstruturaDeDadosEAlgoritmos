#Grafo é um tipo de estrutura de dados utils para lidar com calculo de distancia
#por exemplo, saber o caminho mais curto para n lugar.
#É tambem utilizado para relacionar entidades, por exemplo, rede de amigos de redes sociais

#Processo para se inplementar um grafo em python
#crie uma tabela hash, porque com ela podemos usar uma pessoa como chave e outra como valor
grafo = {}
grafo["voce"] = ["alice", "bob", "claire"]
grafo["bob"] = ["anuj", "goku black", "cruzim"]
grafo["alice"] = ["ricardo milos"]
grafo["claire"] = ["tomasturbando", "jonny bravo"]
grafo["anuj"] = []
grafo["peggy"] = ["gosumm"]
grafo["ricardo milos"] = ["jonny bravo"]
grafo["jonny bravo"] = []
#como as tablas hashes nao sao ordenadas, a ordem aqui nao vai fazer diferenca,
#lembre-se que aqui estamos criando verteces, so importa com quem e nao a ordem em si
#primerio crie uma lista

#contudo existem os dígrafos, que sao grafos onde existe direcao para onde as arestas
#apontam, eles sao representados com linhas com setas. Se nao for direcionado, nao tem seta.

from collections import deque

def pessoa_for_vendedor(nome):
     return nome[-1] == 'm'

def pesquisa(nome):
    fila_de_pesquisa = deque()
    fila_de_pesquisa += grafo[nome] 
    verificadas = []
    while fila_de_pesquisa:
        pessoa = fila_de_pesquisa.popleft()
        if not pessoa in verificadas:
            if pessoa_for_vendedor(pessoa):
                print(pessoa + " e um vendedor de manga!")
                return True
        else:
            fila_de_pesquisa += grafo[pessoa]
            verificadas.append(pessoa)
            print(pessoa + " Nao e vendedor de manga!")
    return False

print(pesquisa("voce"))
