const inventario = [
  {
    nome: "bloco de terra",
    quantidade: 64,
  },
  {
    nome: "espada de diamante",
    quantidade: 1,
  },
  {
    nome: "mandeira",
    quantidade: 45,
  },
  {
    nome: "coblestone",
    quantidade: 32,
  },
  {
    nome: "sticks",
    quantidade: 12,
  },
];

console.log(inventario);

for (let atual = 0; atual < inventario.length; atual++) {
  let menor = atual;

  //encontra o indice do item com a menor quantidade
  for (let item = atual; item < inventario.length; item++) {
    if (inventario[item].quantidade < inventario[menor].quantidade) {
      menor = item;
    }
  }
  let itemAtual = inventario[atual];
  let itemComMenorQuantidade = inventario[menor];

  inventario[atual] = itemComMenorQuantidade;
  inventario[menor] = itemAtual;
}

console.log(inventario);
