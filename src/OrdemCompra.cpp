#include "../include/OrdemCompra.h"
#include "../include/Data.h"
#include "../include/MateriaPrima.h"
#include "../include/Orcamento.h"

OrdemCompra::OrdemCompra(
  Data data,
  MateriaPrima materiaprima,
  std::vector<Orcamento> orcamento):
    _data(data),
    _materiaprima(materiaprima),
    _orcamento(orcamento){}