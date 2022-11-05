#ifndef PESSOA_H
#define PESSOA_H

#include <string>

class Pessoa {

  private:
     std::string _nome;
     std::string _documento;
     std::string _email;
     std::string _endereco;
     std::string _telefone;
  
  public:

    Pessoa(
    std::string nome,
    std::string documento,
    std::string email,
    std::string endereco,
    std::string telefone
   );
  
  
    std::string get_nome() const;
};

#endif