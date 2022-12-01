#include "../include/LogAcessoNegado.h"
#include "../include/Log.h"
#include "../include/Data.h"
#include "../include/Usuario.h"

#include <string>


LogAcessoNegado::LogAcessoNegado(
  Usuario usuario,
  Data data,
  std::string classe,
  std::string metodo):
    Log(usuario,data),
    _classe(classe),
    _metodo(metodo){}

std::string LogAcessoNegado::getClasse()
{
  return this->_classe;
}
std::string LogAcessoNegado::getMetodo()
{
  return this->_metodo;
}