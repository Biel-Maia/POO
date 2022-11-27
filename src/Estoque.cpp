#include "../include/Estoque.h"
#include "../include/Produto.h"
#include "../include/Lote.h"

#include <iostream>
#include <string>

Estoque::Estoque(
    Produto produto):
    _produto(produto){}

Produto Estoque::getProduto(){
  return _produto;
}

void Estoque::setLote(Lote lote){
  _lotes.push_back(lote);
}

void Estoque::setQuantidade(int quantidade){
  _quantidade+=quantidade;
}

void Estoque::setQuantidadeMin(int quantidade){
  _quantidademin=quantidade;
}

