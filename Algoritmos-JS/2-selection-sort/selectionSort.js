import { listaLivros as livros } from "./listaLivros.js";
import { buscarMenorValor as menorValor } from "./menorValor.js";
//1
for (let atual = 0; atual < livros.length; atual++) {
  //verifica qual livro é o mais barato
  let menor = menorValor(livros, atual);
  let livroAtual = livros[atual];
  console.log(`livro atual`, livros[atual]);
  let livroMenorPreco = livros[menor]; //guardamoa informacao, nao a localizcao na memoria, para nao perdermos a referencia do livro que esta na posicao atual
  console.log(`livro menor preco`, livros[menor]);
  livros[atual] = livroMenorPreco; //colocamos o livro mais barato na posicao atual
  livros[menor] = livroAtual; //colocamos o livro que estava na posicao atual na posicao do livro mais barato
}
