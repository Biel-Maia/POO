#ifndef CLIENTE_H
#define CLIENTE_H

#include "Pessoa.h"
#include<vector>

class Cliente : public Pessoa
{
  private:
    bool _tipo;
    vector<Cliente> _cliente;
  public:
    Cliente(std::string nome,
          std::string documento,
          std::string email,
          std::string endereco,
          Data dataNascimento,
          std::string telefone,
          bool tipo);
    bool validaCNPJ(std::string documento);
    void cadastraCliente(Cliente cliente);
};

#endif