#include "../include/Estoque.h"
#include "../include/Produto.h"
#include "../include/Lote.h"
#include "../include/OrdemProducao.h"

#include <iostream>
#include <string>

Estoque::Estoque(
  Produto produto):
    _produto(produto){}

Produto Estoque::getProduto()
{
  return _produto;
}

void Estoque::setLote(Lote lote)
{
  _lotes.push_back(lote);
}

void Estoque::setQuantidade(int quantidade)
{
  _quantidade += quantidade;
}

void Estoque::setQuantidadeMin(int quantidade)
{
  _quantidademin = quantidade;
}

void Estoque::verificaEstoque()
{
  int estoque = getEstoque();
  int estoque_min = getEstoqueMin();

  if(estoque < estoque_min)
  {
    Data data;
    OrdemProducao ordem_producao = OrdemProducao(data.dateNow(), this->getProduto());
  } 
}

int Estoque::getEstoqueMin()
{
  return _quantidademin;
}

int Estoque::getEstoque()
{
  return _quantidade;
}
