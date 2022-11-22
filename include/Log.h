#ifndef LOG_H
#define LOG_H

#include "../include/Data.h"

#include <string>
#include <fstream>
using namespace std;

class Log{
    protected:
        std::string user_usuario;
        Data *data;
    public:
        Log();
        Log(std::string, Data*);
        virtual ~Log();
        // true se log foi salvo, false se houve erro.
        virtual bool salvarLog() = 0;
        int getMatricula();
};

#endif