
#conjunto de chave x valor em um array, a chave identifica o valor da posicao
#para lidar com dados de mesmas chaves sao geradas linkedlists pra cada tipo de chave
#assim é possivel acessar rapidamente um determinado dado, memso em listas grandes
#nao se engane, apesar de ter vantagens em relacao a arrays e linkedlists puras
#na notacao big O, arrays ainda sao mais rapidos em condicoes normais, hashtables
#brilham em casos onde o numero de dados é extremamente grande.

#dicionarios e tuplas em python basicamente usam o mesmo conceito.

lista_telefonica = {}

lista_telefonica["jenny"] = 842424
lista_telefonica["emergency"] = 911

#print(lista_telefonica)

##outro exemplo

votaram = {}

votaram = {
    "Freeza": "Freeza",
    "Numero18": "Bulma",
    "Monark": "Freeza"
}

voted = {}

def verifica_eleitor(nome):
    if votaram.get(nome):
        print("Cai fora!")
    else:
        voted[nome] = True
        print("Deixe votar!")

verifica_eleitor("Goku")
verifica_eleitor("Goku")
verifica_eleitor("Vegeta")
verifica_eleitor("Freeza")

#com dict

dicionario = dict()
# criando um dicionario com palavras chaves
detalhes = dict(altura=175, peso=90)
lista_de_tuplas = [('altura', 195), ('peso', '120')]
max_detalhes = dict(lista_de_tuplas)
print(detalhes)
print(max_detalhes)

