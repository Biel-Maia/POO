#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H

#include <string>

class Departamento{

  private:
    std::string _nome;

  public:
    Departamento(std::string nome);
    std::string getNome();


};

#endif