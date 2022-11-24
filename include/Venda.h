#ifndef VENDA_H
#define VENDA_H

#include "../include/Estoque.h"
#include "../include/Cliente.h"

#include <map>

class Venda{
  private:
    Data _datavenda;
    Cliente _cliente;
    std::map<Lote, Produto> _produtos;
    int _quantvenda;
    
  public:
};
#endif