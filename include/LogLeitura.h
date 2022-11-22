#ifndef LOGLEITURA_H
#define LOGLEITURA_H

#include "../include/Log.h"
#include <string>

class LogLeitura: public Log{
    private:
        std::string entidade_acessada;
        std::string informacao_acessada;
    public:
        LogLeitura();
        LogLeitura(std::string, Data*, std::string, std::string);
        ~LogLeitura();
        // true se log foi salvo, false se houve erro.
        bool salvarLog();
        std::string getUser();
};

#endif