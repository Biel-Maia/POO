#ifndef PESSOA_H
#define PESSOA_H

#include "../include/Data.h"
#include <string>


class Pessoa {

  private:
     std::string _nome;
     std::string _documento;
     std::string _email;
     std::string _endereco;
     Data        _data; 
     std::string _telefone;
  
  public:

    Pessoa(
    std::string nome,
    std::string documento,
    std::string email,
    std::string endereco,
    Data        data,
    std::string telefone
   );
  
  
    std::string get_nome();
};

#endif