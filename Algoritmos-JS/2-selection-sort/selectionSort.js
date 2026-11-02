import { listaLivros as livros } from "./listaLivros.js";
import { buscarMenorValor as menorValor } from "./menorValor.js";

for (let atual = 0; atual < livros.length; atual++) {
  let menor = menorValor(livros, atual);
  let livroAtual = livros[atual];
  let livroMaisBarato = livros[menor];

  livros[atual] = livroMaisBarato;
  livros[menor] = livroAtual;
}
