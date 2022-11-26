#ifndef ORDEMCOMPRA_H
#define ORDEMCOMPRA_H

#include "../include/Data.h"
#include "../include/Orcamento.h"

#include <string>
#include <vector>

class OrdemCompra
{
  private:
    Data _data;
    std::vector<Orcamento> _orcamento;

  public:
    OrdemCompra
    (
      Data data,
      std::vector<Orcamento> orcamento
    );
};

#endif