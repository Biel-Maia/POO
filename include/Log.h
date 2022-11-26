#ifndef LOG_H
#define LOG_H

#include "../include/Data.h"

#include <string>
#include <fstream>
using namespace std;

class Log
{
  protected:
    std::string user_usuario;
    Data *data;
    
  public:
    Log(std::string, Data*);
    virtual ~Log();
    virtual bool salvarLog() = 0;  // true se log foi salvo, false se houve erro.
    int getMatricula();
    std::string getUser();
};

#endif