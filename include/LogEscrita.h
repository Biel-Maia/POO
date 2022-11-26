#ifndef LOGESCRITA_H
#define LOGESCRITA_H

#include "../include/Log.h"
#include <string>

class LogEscrita: public Log
{
  private:
    std::string entidade_alterada;
    std::string nome_atributo, atributo_antigo, atributo_novo;
    
  public:
    LogEscrita(std::string, Data*, std::string, std::string, std::string, std::string);
    ~LogEscrita();
    bool salvarLog();  // true se log foi salvo, false se houve erro.
    std::string getUser();
};

#endif