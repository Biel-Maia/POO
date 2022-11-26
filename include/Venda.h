#ifndef VENDA_H
#define VENDA_H

#include "../include/Data.h"
#include "../include/Cliente.h"
#include "../include/Lote.h"
#include "../include/Produto.h"
#include "../include/Estoque.h"

#include <map>

class Venda
{
  private:
    Data _data;
    Cliente _cliente;
    std::map<Lote, Produto> _produtos;
    Estoque _quantidade_estoque;
    int _numero_lote; 
    double _valor_final;
    int _id;
    
  public:
    Venda
    (
      Data data,
      Cliente cliente,
      std::map<Lote, Produto> produtos,
      Estoque quantidade_estoque,
      int numero_lote,
      double valor_final,
      int id
    );
};
#endif