#include "../include/LogAcessoNegado.h"
#include "../include/Data.h"
#include <string>


LogAcessoNegado::LogAcessoNegado(){}

LogAcessoNegado::LogAcessoNegado(
  std::string _user, 
  Data* data, 
  std::string entidade, 
  std::string funcionalidade):
    Log(_user, data)
{
    this->entidade_acessada = entidade;
    this->funcionalidade_acessada = funcionalidade;
}

std::string LogAcessoNegado::getUser()
{
  return this->user_usuario;
}

bool LogAcessoNegado::salvarLog()
{
  ofstream arquivo;
  arquivo.open("../src/log_acesso_negado.txt", ios::app);

  arquivo << getUser() << ",";
  arquivo << this->data->getDia() <<"/"<< this->data->getMes() <<"/"<< this->data->getAno() <<" ";
  arquivo << data->getHora()<<":"<<data->getMin()<<":"<<data->getSeg()<<",";
  arquivo << this->entidade_acessada <<",";
  arquivo << this->funcionalidade_acessada << endl;

  arquivo.close();

  return true;
}

LogAcessoNegado::~LogAcessoNegado(){}