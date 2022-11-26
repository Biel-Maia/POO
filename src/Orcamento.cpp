#include "../include/Orcamento.h"
#include "../include/Data.h"
#include "../include/Fornecedor.h"



Orcamento::Orcamento(
  Data data,
  int quantidade,
  double valor_unitario,
  double valor_total,
  Fornecedor fornecedor):
    _data(data),
    _quantidade(quantidade),
    _valor_unitario(valor_unitario),
    _valor_total(valor_total),
    _fornecedor(fornecedor){}

