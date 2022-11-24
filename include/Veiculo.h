#ifndef VEICULO_H
#define VEICULO_H


#include <string>

class Veiculo 
{
  private:
    std::string _tipo;
    int _capacidade;
    float _velocidade;
  
public:
    Veiculo
    (
      std::string tipo,
      int capacidade,
      float velocidade
    );
    float get_velocidade();
};

#endif