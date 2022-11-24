#ifndef CLIENTE_H
#define CLIENTE_H

#include "../include/Pessoa.h"
#include "../include/Data.h"

class Cliente : public Pessoa
{
  private:
    bool _tipo;

  public:
    Cliente
    (
      std::string nome,
      std::string documento,
      std::string email,
      std::string endereco,
      Data data,
      std::string telefone,
      bool tipo
    );
    
    bool getTipo();
};

#endif