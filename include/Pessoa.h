#ifndef PESSOA_H
#define PESSOA_H

#include <string>

#include "Data.h"


class Pessoa
{
  private:
    const std::string _nome;
    const std::string _documento;
    const std::string _email;
    const std::string _endereco;
    Data _dataNascimento;
    const std::string _telefone;


  public:
    Pessoa(std::string nome,
          std::string documento,
          std::string email,
          std::string endereco,
          Data dataNascimento,
          std::string telefone);
    bool validaCPF(std::string documento);
};
#endif