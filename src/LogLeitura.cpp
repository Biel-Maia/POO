#include "../include/LogLeitura.h"
#include "../include/Log.h"
#include "../include/Data.h"
#include "../include/Usuario.h"

#include <string>


LogLeitura::LogLeitura(
  Usuario usuario,
  Data data,
  std::string classeAcessada,
  std::string metodoAcessado,
  std::string nomeAtributoAcessado):
    Log(usuario,data),
    _classeAcessada(classeAcessada),
    _metodoAcessado(metodoAcessado),
    _nomeAtributoAcessado(nomeAtributoAcessado){}

std::string LogLeitura::getClasse()
{
  return this->_classeAcessada;
}
std::string LogLeitura::getMetodo()
{
  return this->_metodoAcessado;
}

std::string LogLeitura::getAtributoAcessado()
{
  return this->_nomeAtributoAcessado;
}