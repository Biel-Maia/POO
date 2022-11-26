#ifndef ORCAMENTO_H
#define ORCAMENTO_H

#include "../include/Data.h"
#include "../include/Fornecedor.h"


class Orcamento
{
  private:
    Data _data;
    int _quantidade;
    double _valor_unitario;
    double _valor_total;
    Fornecedor _fornecedor;

  public:
    Orcamento
    (
      Data data,
      int quantidade,
      double valor_unitario,
      double valor_total,
      Fornecedor fornecedor
    );
};

#endif