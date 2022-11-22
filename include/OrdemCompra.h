#ifndef ORDEMCOMPRA_H
#define ORDEMCOMPRA_H

#include "../include/Data.h"
#include "../include/Materiaprima.h"
#include "../include/Orcamento.h"

#include <string>
#include <vector>

class OrdemCompra{
  private:
    Data _data;
    Materiaprima _materiaprima;
    std::vector<Orcamento> _orcamento;

  public:
    OrdemCompra
    (
      Data data,
      Materiaprima materiaprima,
      std::vector<Orcamento> orcamento,
    );
};

#endif