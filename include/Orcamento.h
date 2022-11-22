#ifndef ORCAMENTO_H
#define ORCAMENTO_H

#include "../include/Data.h"
#include "../include/Fornecedor.h"
#include "../include/Materiaprima.h"

class Orcamento{
  private:
    Data _data;
    int _quantidade;
    Materiaprima _materiaprima;
    double _valor_unitario;
    double _valor_total;
    Fornecedor _fornecedor;

  public:
    Orcamento
    (
       Data _data,
      int _quantidade,
      Materiaprima _materiaprima,
      double _valor_unitario,
      double _valor_total,
      Fornecedor _fornecedor
    );

    double calculaValor();
};

#endif