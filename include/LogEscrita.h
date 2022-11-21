#ifndef LOGESCRITA_H
#define LOGESCRITA_H

#include "../include/Log.h"

class LogEscrita: public Log{
    private:
        string entidade_alterada;
        string nome_atributo, atributo_antigo, atributo_novo;
    public:
        LogEscrita();
        LogEscrita(std::string, Data*, string, string, string, string);
        ~LogEscrita();
        // true se log foi salvo, false se houve erro.
        bool salvarLog();
        std::string getUser();
};

#endif