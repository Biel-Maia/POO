#ifndef PAGAMENTO_H
#define PAGAMENTO_H

#include "../include/Cliente.h"
#include "../include/Data.h"

class Pagamento{
  private:
  int codigo;
  double valor;
  Data* data;
  Cliente* cliente;

  public:
  Pagamento(Cliente* c, Data* d);
    
};

#endif