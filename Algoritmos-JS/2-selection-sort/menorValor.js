export function buscarMenorValor(arrProdutos, posicaoInicial) {
  let maisBarato = posicaoInicial; //a gente nao sabe se o primeiro produto é o mais barato, então a gente assume que sim, e depois verifica se existe algum mais barato

  for (let atual = posicaoInicial; atual < arrProdutos.length; atual++) {
    if (arrProdutos[atual].preco < arrProdutos[maisBarato].preco) {
      maisBarato = atual;
    }
  }
  return maisBarato;
}
