#include "../include/LogEscrita.h"
#include "../include/Data.h"

#include <string>

using namespace std;


LogEscrita::LogEscrita(){}

LogEscrita::LogEscrita(
  std::string _user, 
  Data* data, 
  std::string entidade,
  std::string atributo, 
  std::string atributo_anterior, 
  std::string atributo_alterado):
    Log(_user, data)
{
    this->entidade_alterada = entidade;
    this->nome_atributo = atributo;
    this->atributo_antigo = atributo_anterior;
    this->atributo_novo = atributo_alterado;
}

std::string LogEscrita::getUser()
{
  return this->user_usuario;
}

bool LogEscrita::salvarLog()
{
  ofstream arquivo;
  arquivo.open("../src/log_escrita.txt", ios::app);

  arquivo << getUser() << ",";
  arquivo << this->data->getDia() <<"/"<< this->data->getMes() <<"/"<< this->data->getAno() <<" ";
  arquivo << data->getHora()<<":"<<data->getMin()<<":"<<data->getSeg()<<",";
  arquivo << this->entidade_alterada <<",";
  arquivo << this->nome_atributo << ":" << this->atributo_antigo << ";";
  arquivo << this->nome_atributo << ":" << this->atributo_novo << endl;

  arquivo.close();

  return true;
}

LogEscrita::~LogEscrita(){}