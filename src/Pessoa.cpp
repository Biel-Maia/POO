#include "../include/Pessoa.h"



Pessoa::Pessoa(
    std::string nome,
    std::string documento,
    std::string email,
    std::string endereco,
    std::string telefone
): _nome(nome),
   _documento(documento),
   _email(email),
   _endereco(endereco),
   _telefone(telefone){
}


std::string Pessoa::get_nome() const {
  return this->_nome;
}
