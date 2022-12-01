#ifndef VEICULO_H
#define VEICULO_H

#include <string>


class Veiculo 
{
  private:
    std::string _placa;
    std::string _tipo;
    int _capacidade;
  
  public:
    Veiculo
    (
      std::string placa,
      std::string tipo,
      int capacidade
    );

    std::string getPlaca();
    std::string getTipo();
};

#endif