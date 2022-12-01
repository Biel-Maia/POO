#ifndef LOGACESSONEGADO_H
#define LOGACESSONEGADO_H

#include "../include/Log.h"
#include "../include/Data.h"
#include "../include/Usuario.h"

#include <string>


class LogAcessoNegado : public Log
{
  private:
    std::string _classe;
    std::string _metodo;
  
  public:
    LogAcessoNegado
    (
      Usuario usuario,
      Data data,
      std::string classe,
      std::string metodo
    );
  
  std::string getClasse();
  std::string getMetodo();
};

#endif