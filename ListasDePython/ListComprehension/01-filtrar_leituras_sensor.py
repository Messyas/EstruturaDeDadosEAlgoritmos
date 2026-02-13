#Turno do laboratório: filtrar leituras do sensor
#Cenário: Um engenheiro registrou leituras de um 
# sensor (em volts) e quer separar o que é “ruído” do que é “sinal útil”.
#Dados: leituras = [0.02, 1.10, 0.00, 3.30, 2.95, 0.01, 5.00, 4.98]
#Tarefa: gere uteis com valores >= 1.0 e ruidos com valores < 1.0. 
# Depois crie uteis_quadrado com o quadrado de cada valor útil.
#Dicas: faça 1 versão com for e 1 versão com list comprehension; 
# use round(x, 2) na saída.

leituras = [0.02, 1.10, 0.00, 3.30, 2.95, 0.01, 5.00, 4.98]

uteis = [l for l in leituras if l >= 1.0]
ruidos = [l for l in leituras if l < 1.0]

uteis_quadrado = [round(l ** 2, 2) for l in uteis]

print(uteis_quadrado)
