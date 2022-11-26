 #include "../include/Estoque.h"
 #include "../include/Produto.h"
 #include <iostream>
#include  <string>

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
    std::string p=_estoque[x].getProduto().getNome();
    if(p == prod.getNome())
      quantidade += _estoque[x].getQuantidade();
  }
  
  return quantidade;
}
