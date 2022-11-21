#include "../include/LogLeitura.h"
#include "../include/Data.h"

using namespace std;

LogLeitura::LogLeitura(){}

LogLeitura::LogLeitura(std::string _user, Data* data, string entidade, string atributo) :
    Log(_user, data){
    this->entidade_acessada = entidade;
    this->informacao_acessada = atributo;
}

std::string LogLeitura::getUser(){
    return this->user_usuario;
}

bool LogLeitura::salvarLog(){
    ofstream arquivo;
    arquivo.open("../src/log_leitura.txt", ios::app);

    arquivo << getUser() << ",";
    arquivo << this->data->getDia() <<"/"<< this->data->getMes() <<"/"<< this->data->getAno() <<" ";
    arquivo << data->getHora()<<":"<<data->getMinuto()<<":"<<data->getSegundo()<<",";
    arquivo << this->entidade_acessada <<",";
    arquivo << this->informacao_acessada << endl;

    arquivo.close();

    return true;
}

LogLeitura::~LogLeitura(){}