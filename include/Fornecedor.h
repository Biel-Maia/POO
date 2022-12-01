#ifndef FORNECEDOR_H
#define FORNECEDOR_H

#include "../include/MateriaPrima.h"

#include <string>
#include <vector>


class Fornecedor
{
  private:
    std::string _nome;
    std::vector<MateriaPrima> _materiaprima;
    std::vector<double> _precomateriaprima;

  public:
    Fornecedor(std::string nome);
    
    void setMateriaPrima(MateriaPrima materiaprima);
    void setPrecoMateriaPrima(double preco);
    void setPrecoMateriaPrimaPosicao(int posicao,double preco);
    void getMateriasPrimasFornecedor();
    std::string getNome();
};

#endif