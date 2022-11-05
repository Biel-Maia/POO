#include "pessoa.h"


Pessoa::Pessoa(
  std::string nome,
  std::string cpf
): _nome(nome),
   _cpf(cpf) {
}


std::string Pessoa::get_nome() const {
  return this->_nome;
}

std::string Pessoa::get_cpf() const {
  return this->_cpf;
}