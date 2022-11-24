#ifndef ORCAMENTO_H
#define ORCAMENTO_H

#include "../include/Data.h"
#include "../include/Fornecedor.h"
#include "../include/MateriaPrima.h"

class Orcamento
{
  private:
    Data _data;
    int _quantidade;
    MateriaPrima _materiaprima;
    double _valor_unitario;
    double _valor_total;
    Fornecedor _fornecedor;

  public:
    Orcamento
    (
      Data data,
      int quantidade,
      MateriaPrima materiaprima,
      double valor_unitario,
      double valor_total,
      Fornecedor fornecedor
    );
};

#endif