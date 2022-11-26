#ifndef LOTE_H
#define LOTE_H

#include "../include/Data.h"
#include "../include/Produto.h"

class Lote
{
  private:
    Data _dataproducao;
    int _numerolote;
    Produto _produto;
    int _quantidade;
  
  public:
    Lote(
      Data dataproducao,
      int numerolote,
      Produto produto,
      int quantidade
    );
    Data getDataproducao();
    Produto getProduto();
    int getQuantidade();
};
#endif