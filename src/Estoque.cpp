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
  int x = 0;
  int y = 0;
  
  x = this->_quantidade;
  y = quantidade;
  
  int z = 0;
  z = x + y;
  
  _quantidade = z;
}

void Estoque::setQuantidadeMin(int quantidade)
{
  _quantidademin = 0;
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

void Estoque::realizarVenda(int qtd)
{
  _quantidade = 0;
  _quantidade = qtd;
}

int Estoque::getEstoqueMin()
{
  return _quantidademin;
}

int Estoque::getEstoque()
{
  return _quantidade;
}

void Estoque::iniciaEstoque() 
{
  _quantidade = 0;
}
void Estoque::iniciaEstoqueMin()
{
  _quantidademin = 0;
}
