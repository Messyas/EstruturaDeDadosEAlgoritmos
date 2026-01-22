#Tabelas hash sao usadas para armazenamento de alguns tipos de informacoes
#em sistemas grandes isso permite reaprovietar processos, assism nao é necessario recalcular
# ou processar uma pagina de login ou um detemrinado valor toda vez que o usuario utilzar o servico

#exemplo com urls da net

# facebook.com/about -> dados da pagina sobre
# facebook.com -> dados da pagina inicial

#primeiro o facebook checar se a paigna esta armazenda na hash
#somente se nao estiver o servidor processa

#codigo de exemplo:

cache = {}

def pega_dados_do_servidor(url):
    print(url)
    dados_servidor = "Imagina que pegou alguma poha aqui"
    return dados_servidor

def pega_pagina(url):
    if cache.get(url):
        return cache[url]
    else:
        dados = pega_dados_do_servidor(url)
        cache[url] = dados
        return dados
    
pega_pagina("https://www.google.com/about")
pega_pagina("https://www.google.com/about")
pega_pagina("https://www.google.com/about")
pega_pagina("https://www.google.com/about")
#imaginando que cada um foi feito em maquinas diferentes, o que seria enviado seria
#basicmaente a mesma coisa, sem processar novamente todas as vezes de forma cavalar


