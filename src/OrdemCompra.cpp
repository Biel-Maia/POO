#include "../include/OrdemCompra.h"
#include "../include/Data.h"
#include "../include/Orcamento.h"

OrdemCompra::OrdemCompra(
  Data data,
  std::vector<Orcamento> orcamento):
    _data(data),
    _orcamento(orcamento){}