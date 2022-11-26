 #include "../include/Estoque.h"
 #include <iostream>

void Estoque::atualizaEstoque(Lote lote)
{
  _estoque.push_back(lote);
}

int Estoque::verificaEstoque(Produto prod)
{
  int x=0;
  int quantidade=0;
  int tam = _estoque.size();
  
  for(x = 0; x < tam; x++)
  {
    if(_estoque[x].get_produto() == prod)
      quantidade += _estoque[x].get_quantidade();
  }
  
  return quantidade;
}
