#include "../include/Cliente.h"

#include "../include/Pessoa.h"


  Cliente::Cliente(
      std::string nome,
      std::string documento,
      std::string email,
      std::string endereco,
      std::string telefone,
      bool tipo):
      Pessoa(nome,documento,email,endereco,telefone),
      _tipo(tipo){}
    
  bool Cliente::getTipo(){
  return this->_tipo;  
  }