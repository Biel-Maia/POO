#include "../include/LogEscrita.h"
#include "../include/Log.h"
#include "../include/Data.h"
#include "../include/Usuario.h"

#include <string>


LogEscrita::LogEscrita(
  Usuario usuario,
  Data data,
  std::string classeAlterada,
  std::string metodo,
  std::string nomeAtributoAlterado,
  std::string valorAtributoAlteradoAntes,
  std::string valorAtributoAlteradoDepois):
    Log(usuario,data),
    _classeAlterada(classeAlterada),
    _metodo(metodo),
    _nomeAtributoAlterado(nomeAtributoAlterado),
    _valorAtributoAlteradoAntes(valorAtributoAlteradoAntes),
    _valorAtributoAlteradoDepois(valorAtributoAlteradoDepois){}

std::string LogEscrita::getClasse()
{
  return this->_classeAlterada;
}

std::string LogEscrita::getMetodo()
{
  return this->_metodo;
}

std::string LogEscrita::getNomeAtributoAlterado()
{
  return this->_nomeAtributoAlterado;
}

std::string LogEscrita::getValorAtributoAlteradoAntes()
{
  return this->_valorAtributoAlteradoAntes;
}

std::string LogEscrita::getValorAtributoAlteradoDepois()
{
  return this->_valorAtributoAlteradoDepois;
}

