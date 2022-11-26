/*#ifndef PAGAMENTOCARTAO_H
#define PAGAMENTOCARTAO_H

#include "../include/Pagamento.h"

class PagamentoCartao: public Pagamento{
  private:
  std::string bandeira;
  int parcelas;
  
  public:
  PagamentoCartao(Cliente* c);
  bool pagar(double valor, std::string bandeira, int parcelas);
    
};

#endif*/