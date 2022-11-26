#ifndef PAGAMENTO_H
#define PAGAMENTO_H

#include "../include/Cliente.h"
#include "../include/Data.h"

class Pagamento
{
  private:
    int _codigo;
    double _valor;
    Data* _data;
    Cliente* _cliente;

  public:
    Pagamento
    (
      int codigo, 
      double valor, 
      Data* data, 
      Cliente* cliente
    );  
};

#endif