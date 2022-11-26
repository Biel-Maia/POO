#ifndef PRODUTO_H
#define PRODUTO_H

#include "../include/Categoria.h"
#include "../include/Data.h"

#include <string>
#include <map>

class Produto
{
  private:
    std::string _nome;
    int _codigo;
    double _preco;
    Categoria _categoria;
    int _lote_min;
    int _estoque_min;
    std::map<double, Data> _precos;

  public:
    Produto
    (
      std::string nome,
      int codigo,
      double preco,
      Categoria categoria,
      int lote_min,
      int estoque_min,
      std::map<double, Data> precos
    );  
    int get_codigo();
    void setPreco(double preco);
    std::string getNome();
};

#endif