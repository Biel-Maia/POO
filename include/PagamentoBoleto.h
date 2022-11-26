#ifndef PAGAMENTOBOLETO_H
#define PAGAMENTOBOLETO_H

#include "../include/Pagamento.h"

class PagamentoBoleto: public Pagamento
{
  private:
    int _prazo;

  public:
    PagamentoBoleto
    (
      int codigo, 
      double valor, 
      Data* data, 
      Cliente* cliente,
      int prazo
    );

    bool pagar(double, int);   
};

#endif