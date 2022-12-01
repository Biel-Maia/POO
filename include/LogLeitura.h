#ifndef LOGLEITURA_H
#define LOGLEITURA_H

#include "../include/Log.h"
#include "../include/Data.h"
#include "../include/Usuario.h"

#include <string>


class LogLeitura : public Log
{
  private:
    std::string _classeAcessada;
    std::string _metodoAcessado;
    std::string _nomeAtributoAcessado;

  public:
    LogLeitura
    (
      Usuario usuario,
      Data data,
      std::string classeAlterada,
      std::string metodoAcessado,
      std::string nomeAtributoAcessado
    );
  
  std::string getClasse();
  std::string getMetodo();
  std::string getAtributoAcessado();
};

#endif