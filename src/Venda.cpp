#include "../include/Venda.h"

Venda::Venda(
  Data data,
  Cliente cliente,
  std::map<Lote, Produto> produtos,
  Estoque quantidade_estoque,
  int numero_lote,
  double valor_final,
  int id):
    _data(data),
    _cliente(cliente),
    _produtos(produtos),
    _quantidade_estoque(quantidade_estoque),
    _numero_lote(numero_lote),
    _valor_final(valor_final),
    _id(id) {}