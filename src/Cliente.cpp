#include "../include/Cliente.h"

Cliente::Cliente(
          std::string nome,
          std::string documento,
          std::string email,
          std::string endereco,
          Data dataNascimento,
          std::string telefone,
          bool tipo
          ):
          Pessoa(nome, documento, email, endereco, dataNascimento, 
          telefone),
          _tipo(tipo){}

bool Cliente::validaCNPJ(std::string documento){
  
}

void Cliente::cadastraCliente(Cliente cliente){
  _cliente.push_back(cliente);
}