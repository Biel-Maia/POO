#include "../include/Veiculo.h"
#include "../include/Rota.h"

#include <string>

Veiculo::Veiculo(
  std::string placa,
  std::string tipo, 
  int capacidade):
    _placa(placa),
    _tipo(tipo),
     _capacidade(capacidade){}

std::string Veiculo::getPlaca(){
  return this->_placa;
}
std::string Veiculo::getTipo(){
  return this->_tipo;
}