#include "../include/Usuario.h"
#include <string>

Usuario::Usuario(
    std::string tipo,
    std::string user,
    std::string senha
):  _tipo(tipo),
    _user(user),
    _senha(senha){
}

std::string Usuario::getUser(){
  return this->_user;
}
std::string Usuario::getSenha(){
  return this->_senha;
}