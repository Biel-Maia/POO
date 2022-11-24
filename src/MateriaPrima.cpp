#include "../include/MateriaPrima.h"
#include "../include/Fornecedor.h"
#include "../include/Orcamento.h"
#include "../include/OrdemCompra.h"

#include <string>
#include <vector>


MateriaPrima::MateriaPrima(
  std::string nome,
  int unidade_medida,
  int quantidade_estoque,
  int quantidade_estoque_min,
  std::vector<Fornecedor> fornecedor,
  std::vector<Orcamento> orcamento):
    _nome(nome),
    _unidade_medida(unidade_medida),
    _quantidade_estoque(quantidade_estoque),
    _quantidade_estoque_min(quantidade_estoque_min),
    _fornecedor(fornecedor),
    _orcamento(orcamento){}