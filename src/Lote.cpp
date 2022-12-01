#include "../include/Lote.h"

Lote::Lote(
  Data dataproducao,
  int numerolote,
  Produto produto,
  int quantidade):
    _dataproducao(dataproducao),
    _numerolote(numerolote),
    _produto(produto),
    _quantidade(quantidade){}

Data Lote::getDataproducao()
{
  return this->_dataproducao;
}

Produto Lote::getProduto()
{
  return this->_produto;
}

int Lote::getQuantidade()
{
  return this->_quantidade;
}

int Lote::getNumeroLote()
{
  return this->_numerolote;
}
