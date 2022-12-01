#include "../include/Venda.h"
#include "../include/Cliente.h"
#include "../include/Pagamento.h"
#include "../include/Orcamento.h"


Venda::Venda(
  Data data,
  Cliente cliente,
  Orcamento orcamento,
  double valor_final,
  Pagamento formapagamento,
  int parcelas):
    _data(data),
    _cliente(cliente),
    _orcamento(orcamento),
    _valorFinal(valor_final),
    _formapagamento(formapagamento),
    _parcelas(parcelas){}

void Venda::setCliente(Cliente cliente)
{
  _cliente=cliente; 
}

double Venda::getValorParcelas()
{
  return this->_valorparcelas;
}

void Venda::setValorParcelas(double valorParcelas)
{
  _valorparcelas = valorParcelas;
}