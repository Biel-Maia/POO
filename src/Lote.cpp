#include "../include/Lote.h"

Lote::Lote(
  Data dataproducao,
  int numerolote,
  Produto produto,
  int quantidade
  ):
    _dataproducao(dataproducao),
    _numerolote(numerolote),
    _produto(produto),
    _quantidade(quantidade){}

Data Lote::get_dataproducao(){
  return this->_dataproducao;
}

Produto Lote::get_produto(){
  return this->_produto;
}

int Lote::get_quantidade(){
  return this->_quantidade;
}
