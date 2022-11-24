#include "../include/Estoque.h"

void Estoque::atualizaEstoque(Lote lote)
{
  _estoque.push_back(lote);
}

int Estoque::verificaEstoque(Produto prod)
{
  int quantidade;
  quantidade = 0;
  auto::interator it;
  for(it = _estoque.begin(); it != _estoque.end(); it++)
  {
    if(it->get_produto() == prod)
      quantidade += it->get_quantidade();
  }
  
  return quantidade;
}