#include "../include/Departamento.h"


Departamento::Departamento(std::string nome):
  _nome(nome){}

std::string Departamento::getNome()
{
   return this->_nome;
}