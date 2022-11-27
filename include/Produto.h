#ifndef PRODUTO_H
#define PRODUTO_H

#include "../include/Categoria.h"
#include "../include/Data.h"
#include "../include/MateriaPrima.h"

#include <string>
#include <map>
#include <vector>

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
    std::vector<MateriaPrima> _materiaprima;
    std::vector<int> _quantidade;

  public:
    Produto
    (
      std::string nome,
      int codigo,
      double preco,
      Categoria categoria,
      int lote_min,
      int estoque_min
    );  
    int get_codigo();
    void setPreco(double preco);
    std::string getNome();
    void setMateriaPrima(MateriaPrima materiaprima);
    void setQuantidade(int quantidade);
    double getPreco();
};

#endif