#include "../include/Usuario.h"
#include <string>


Usuario* Usuario::instancia_unica = nullptr;

Usuario::Usuario(
  std::string tipo,
  std::string user,
  std::string senha):  
    _tipo(tipo),
    _user(user),
    _senha(senha){
}

std::string Usuario::getUser()
{
  return this->_user;
}

std::string Usuario::getSenha()
{
  return this->_senha;
}

void Usuario::setSenha(std::string senha)
{
    this->_senha = senha;
}

// Adiciona nova permissao de uso para classe e método
void Usuario::setPermissao(std::string classe, std::string metodo, bool permissao)
{
    this->_classe.push_back(classe);
    this->_metodo.push_back(metodo);
    this->_permissao.push_back(permissao);
}

// Obtém a permissao de uso para classe e método
bool Usuario::getPermissao(std::string classe, std::string metodo)
{
    int x=0;
    int y=0;
    int tamClasse=_classe.size();
    int tamMetodo=_classe.size();

    bool z=0;
  
    for(x=0;x<tamClasse;x++)
    {
     for(y=0;y<tamMetodo;x++)
     {
       if(_classe[x]==classe && _metodo[x]==metodo && x==y)
       {
        z=_permissao[x]; 
       }
       else{
       z=false;;
       }
     } 
    }
  return z;
}

Usuario::~Usuario()
{
    delete instancia_unica;
}