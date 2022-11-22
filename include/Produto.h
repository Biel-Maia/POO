#ifndef PRODUTO_H
#define PRODUTO_H

#include "../include/Categoria.h"
#include "../include/Data.h"
#include "../include/MateriaPrima.h"

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
    std::map<int, MateriaPrima> _materiaprima;

  public:
    Produto(
    std::string nome,
    int codigo,
    double preco,
    Categoria categoria,
    int lote_min,
    int estoque_min,
    std::map<double, Data> precos,
    std::map<int, MateriaPrima> materiaprima
    );  

    void setPreco(double preco);
};

#endif