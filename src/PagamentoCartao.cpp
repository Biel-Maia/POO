#include "../include/PagamentoCartao.h"

PagamentoCartao(Cliente* _cliente, Data* _data)
{
  this->cliente = _cliente;
  this->data = _data;
} 

bool pagar(double _valor, std::string _bandeira, int _parcelas)
{
  this->valor = _valor;
  this->bandeira = _bandeira;
  this->parcelas = _parcelas;

  this->codigo = rand();
}