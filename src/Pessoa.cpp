#include "../include/Pessoa.h"

#include "../include/Data.h"
#include <string>

Pessoa::Pessoa(
    std::string nome,
    std::string documento,
    std::string email,
    std::string endereco,
    Data        data,
    std::string telefone
): _nome(nome),
   _documento(documento),
   _email(email),
   _endereco(endereco),
   _data(data),
   _telefone(telefone){
}


std::string Pessoa::get_nome(){
  return this->_nome;
}
