#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <string>

class Categoria
{
  private:
    std::string _nome;

  public:
    Categoria(std::string nome);
    std::string getNome();
};

#endif