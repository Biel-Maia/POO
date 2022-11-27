#ifndef PAGAMENTO_H
#define PAGAMENTO_H

#include <string>

using namespace std;

class Pagamento
{
  private:
  string _nomeformapagamento;

  public:
    Pagamento
    (
    string nomeformapagamento
    );  
  string getNomeFormaPagamento();
};

#endif