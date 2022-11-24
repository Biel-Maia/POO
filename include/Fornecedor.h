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

  public:
    Fornecedor(
      std::string nome,
      std::vector<MateriaPrima> materiaprima
    );
};

#endif