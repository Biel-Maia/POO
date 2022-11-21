#ifndef LOGLEITURA_H
#define LOGLEITURA_H

#include "../include/Log.h"

class LogLeitura: public Log{
    private:
        string entidade_acessada;
        string informacao_acessada;
    public:
        LogLeitura();
        LogLeitura(std::string, Data*, string, string);
        ~LogLeitura();
        // true se log foi salvo, false se houve erro.
        bool salvarLog();
        std::string getUser();
};

#endif