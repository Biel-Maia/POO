#ifndef VEICULO_H
#define VEICULO_H

#include "../include/Rota.h"
#include <string>

class Veiculo {
  private:
    std::string _tipo;
    int _capacidade;
    Rota _rota;
  public:
    Veiculo(
      std::string tipo,
      int capacidade,
      Rota rota
    );
};
#endif