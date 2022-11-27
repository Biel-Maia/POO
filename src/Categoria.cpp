#include "../include/Categoria.h"


Categoria::Categoria(std::string nome): 
  _nome(nome){}

std::string Categoria::getNome()
{
  return this->_nome;
}
