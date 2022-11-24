#include "../include/Orcamento.h"
#include "../include/MateriaPrima.h"
#include "../include/Data.h"
#include "../include/Fornecedor.h"



Orcamento::Orcamento(
  Data data,
  int quantidade,
  MateriaPrima materiaprima,
  double valor_unitario,
  double valor_total,
  Fornecedor fornecedor):
    _data(data),
    _quantidade(quantidade),
    _materiaprima(materiaprima),
    _valor_unitario(valor_unitario),
    _valor_total(valor_total),
    _fornecedor(fornecedor){}

