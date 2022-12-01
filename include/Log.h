#ifndef LOG_H
#define LOG_H

#include "../include/Data.h"
#include "../include/Usuario.h"

#include <string>
#include <fstream>

using namespace std;

class Log
{
  protected:
    Usuario _usuario;
    Data _data;
    
  public:
    Log(Usuario usuario, Data data);
    
    Usuario getUsuario();
    Data getData();
};

#endif