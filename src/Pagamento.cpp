#include "../include/Pagamento.h"

#include <string>


Pagamento::Pagamento(std::string nomeformapagamento):
    _nomeformapagamento(nomeformapagamento){}

std::string Pagamento::getNomeFormaPagamento()
{
  return this->_nomeformapagamento;
}

