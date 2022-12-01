#ifndef PAGAMENTO_H
#define PAGAMENTO_H

#include <string>


class Pagamento
{
  private:
    std::string _nomeformapagamento;

  public:
    Pagamento(std::string nomeformapagamento);  
  
    std::string getNomeFormaPagamento();
};

#endif