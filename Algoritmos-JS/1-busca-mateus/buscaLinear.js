import { listaLivros as livros } from "./listaLivros.js";

let maisBarato = 0;

//busca o menor valor
for (let atual = 0; atual < livros.length; atual++) {
  if (livros[atual].preco < livros[maisBarato].preco) {
    maisBarato = atual;
  }
}

console.log(
  `O livro mais barato custa R$${livros[maisBarato].preco} e o título é ${livros[maisBarato].titulo}`,
);

let maisCaro = 0;
//busca o menor maior
for (let atual = 0; atual < livros.length; atual++) {
  if (livros[atual].preco > livros[maisCaro].preco) {
    maisCaro = atual;
  }
}

console.log(
  `O livro mais caro custa R$${livros[maisCaro].preco} e o título é ${livros[maisCaro].titulo}`,
);
