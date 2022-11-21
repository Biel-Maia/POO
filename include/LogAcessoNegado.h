#ifndef LOGACESSONEGADO_H
#define LOGACESSONEGADO_H

#include "../include/Log.h"

class LogAcessoNegado: public Log{
    private:
        string entidade_acessada;
        string funcionalidade_acessada;
    public:
        LogAcessoNegado();
        LogAcessoNegado(std::string, Data*, string, string);
        ~LogAcessoNegado();
        // true se log foi salvo, false se houve erro.
        bool salvarLog();
        int getUser();
};

#endif