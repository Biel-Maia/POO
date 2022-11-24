#include "../include/Cliente.h"

#include "../include/Pessoa.h"
#include "../include/Data.h"


Cliente::Cliente(
  std::string nome,
  std::string documento,
  std::string email,
  std::string endereco,
  Data data,
  std::string telefone,
  bool tipo):
    Pessoa(nome,documento,email,endereco,data,telefone),
    _tipo(tipo){}
    
bool Cliente::getTipo()
{
  return this->_tipo;  
}