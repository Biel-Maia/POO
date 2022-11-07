#ifndef CLIENTE_H
#define CLIENTE_H
#include "../include/Pessoa.h"

class Cliente : public Pessoa{

  private:
    bool _tipo;

  public:
    Cliente(
    std::string nome,
    std::string documento,
    std::string email,
    std::string endereco,
    std::string telefone,
    bool tipo);
    bool getTipo();

};

#endif