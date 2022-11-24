#include "../include/Cargo.h"


Cargo::Cargo(std::string nome):
  _nome(nome){}

std::string Cargo::getNome()
{
  return this->_nome;
}