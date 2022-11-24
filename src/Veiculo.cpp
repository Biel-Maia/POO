#include "../include/Veiculo.h"
#include "../include/Rota.h"



Veiculo::Veiculo(
  std::string tipo, 
  int capacidade,
  float velocidade): 
    _tipo(tipo),
     _capacidade(capacidade),
     _velocidade(velocidade){}

float Veiculo::get_velocidade(){
  retun this-> _velocidade;
}