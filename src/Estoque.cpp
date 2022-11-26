 #include "../include/Estoque.h"
 #include <iostream>

void Estoque::atualizaEstoque(Lote lote)
{
  _estoque.push_back(lote);
}

int Estoque::verificaEstoque(Produto prod)
{
  int quantidade;
  quantidade = 0;
  auto::iterator pt;
  for(pt = _estoque.begin(); pt != _estoque.end(); pt++)
  {
    if(pt->get_produto() == prod)
      quantidade += pt->get_quantidade();
  }
  
  return quantidade;
}
