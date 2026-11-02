import { listaLivros } from "./listaLivros.js";

let maisBarato = 0;
let atual = 0;

for (atual; atual < listaLivros.length; atual++) {
  if (listaLivros[atual].preco < listaLivros[maisBarato].preco) {
    maisBarato = atual;
  }
}

console.log(`O livro mais barato custa R$${listaLivros[maisBarato].preco}`);
