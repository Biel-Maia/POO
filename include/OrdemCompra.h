#ifndef ORDEMCOMPRA_H
#define ORDEMCOMPRA_H

#include "../include/Data.h"
#include "../include/MateriaPrima.h"
#include "../include/Orcamento.h"

#include <string>
#include <vector>

class OrdemCompra
{
  private:
    Data _data;
    MateriaPrima _materiaprima;
    std::vector<Orcamento> _orcamento;

  public:
    OrdemCompra
    (
      Data data,
      MateriaPrima materiaprima,
      std::vector<Orcamento> orcamento,
    );
};

#endif