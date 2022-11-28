#ifndef ORDEMPRODUCAO_H
#define ORDEMPRODUCAO_H

#include "../include/Data.h"
#include "../include/Produto.h"

class OrdemProducao
{
  private:
    Data _data;
    Produto _produto;

  public:
    OrdemProducao
    (
      Data data,
      Produto produto
    );
    //void setProduto(Produto produto);
};

#endif


















