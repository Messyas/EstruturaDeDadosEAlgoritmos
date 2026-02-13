#exemplo de for loop normal

quadrados = []

for number in range(10):
    quadrados.append(number * number)

print(quadrados)

print("\n ")

#Maps (programacao funcional)

precos = [1.09, 23.56, 57.84, 4.56, 6.78]
VALOR_DA_TAXA = .08

def get_preco_com_taxa(preco):
    return preco * (1 + VALOR_DA_TAXA)

preco_final = map(get_preco_com_taxa, precos)

print(list(preco_final))

#A terceira maneria de criar e tranformar listas
#LISTA COMPREHENSION

#Equivalmente a rescrever um for loop

print("\n ")

#segue esse padrao:
# nova_lista = [expressao for membro in iterador]
quadrados = [numero * numero for numero in range(10)]
print(quadrados)

print("\n ")
# 1. Expressao: É o proprio membro, uma chamada a um metodo ou qualquer outra
#expressao valida que retorne um valor. No exemplo acima, a expressao 
# "Numero * Numero" é o quadrado do valor do mebro, ou seja so importa o valor
# que a expressao ou chamada de funcao retorna.

# 2. Membro: É o objeto ou valor na lista ou iteravel. 
# No exemplo o valor É numero

# 3. Iterador: Pode ser uma lista, conjunto, sequencia, gerador ou qualquer
# outro objeto que pode retornar seus elementos um de cada vez.
# No exemplo o iteravel é o range(10)

#Por ser bem flexivel geralmente da pra substituir estruturas como Map


preco_final = [get_preco_com_taxa(preco) for preco in precos]

print("\n ")