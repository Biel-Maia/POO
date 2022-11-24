#ifndef ESTOQUE_H
#define ESTOQUE_H

#include "../include/Lote.h"

class Estoque{
  private::
    std::vector<Lote> _estoque;
  public::
    void atualizaEstoque(Lote lote);
    int verificaEstoque(Produto prod);
};
#endif