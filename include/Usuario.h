#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario{

  private:
  std::string _tipo;
  std::string _user;
  std::string _senha;

  public:
  Usuario(
    std::string tipo,
    std::string user,
    std::string senha
  );

  std::string getUser();
  std::string getSenha();

};
#endif