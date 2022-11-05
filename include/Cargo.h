#ifndef CARGO_H
#define CARGO_H

#include <string>

class Cargo{

  private:
    std::string _nome;

  public:
    Cargo(std::string nome);
    std::string getNome();
};

#endif