#Use as funcoes escritas no codigo para imaginar a pilha de chamada

def sauda(nome):
    print("Olá " + nome)
    sauda2(nome)
    print("Preparando-se para dizer tchau")
    tchau()

def sauda2(nome):
    print("Como voce esta " + nome + "?")

def tchau():
    print("Ok, Tchau!")

sauda("Messyas")