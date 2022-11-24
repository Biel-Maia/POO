#ifndef PAGAMENTOBOLETO_H
#define PAGAMENTOBOLETO_H

#include "../include/Pagamento.h"

class PagamentoBoleto: public Pagamento{
  private:
  int prazo;

  public:
  PagamentoBoleto(Cliente* _cliente, Data* _data);
  bool pagar(double, int);
    
};

#endif