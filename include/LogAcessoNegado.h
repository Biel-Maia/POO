#ifndef LOGACESSONEGADO_H
#define LOGACESSONEGADO_H

#include "../include/Log.h"
#include <string>

class LogAcessoNegado: public Log
{
  private:
    std::string entidade_acessada;
    std::string funcionalidade_acessada;
    
  public:
    LogAcessoNegado(std::string, Data*, std::string, std::string);
    ~LogAcessoNegado();
    bool salvarLog();   //true se log foi salvo, false se houve erro.
    std::string getUser();
};

#endif