#include "../include/Usuario.h"
#include <string>

Usuario* Usuario::instancia_unica = nullptr;

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

void Usuario::setSenha(std::string senha){
    this->_senha = senha;
}

// Adiciona nova permissao de uso para classe e método
void Usuario::setPermissao(std::string classe, std::string metodo, bool permissao){
    this->permissoes_de_acesso[classe][metodo] = permissao;
}

// Obtém a permissao de uso para classe e método
bool Usuario::getPermissao(std::string classe, std::string metodo){
    return this->permissoes_de_acesso[classe][metodo];
}

Usuario::~Usuario(){
    delete instancia_unica;
}