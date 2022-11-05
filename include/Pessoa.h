#ifndef PESSOA_H
#define PESSOA_H

#include <string>


class Pessoa {

  private:
    const std::string _nome;
    const std::string _cpf;
  
  public:

    Pessoa(
    std::string nome,
    std::string cpf
   );
  
    std::string get_nome() const;
    std::string get_cpf() const;
};

#endif