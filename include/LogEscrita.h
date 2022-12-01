#ifndef LOGESCRITA_H
#define LOGESCRITA_H

#include "../include/Log.h"
#include "../include/Data.h"
#include "../include/Usuario.h"

#include <string>


class LogEscrita : public Log
{
  private:
    std::string _classeAlterada;
    std::string _metodo;
    std::string _nomeAtributoAlterado;
    std::string _valorAtributoAlteradoAntes;
    std::string _valorAtributoAlteradoDepois;
  
  public:
    LogEscrita
    (
      Usuario usuario,
      Data data,
      std::string classeAlterada,
      std::string metodo,
      std::string nomeAtributoAlterado,
      std::string valorAtributoAlteradoAntes,
      std::string valorAtributoAlteradoDepois
    );
  
    std::string getClasse();
    std::string getMetodo();
    std::string getNomeAtributoAlterado();
    std::string getValorAtributoAlteradoAntes();
    std::string getValorAtributoAlteradoDepois();
};

#endif