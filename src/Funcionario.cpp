#include "../include/Funcionario.h"
#include "../include/Pessoa.h"
#include "../include/Departamento.h"
#include "../include/Cargo.h"
#include "../include/Data.h"

#include <string>
#include <map>


Funcionario::Funcionario(
  std::string nome,
  std::string documento,
  std::string email,
  std::string endereco,
  Data data,
  std::string telefone,
  int matricula,
  Data dataAdmissao,
  Departamento departamento,
  Cargo cargo,
  double salario,
  std::string status,
  float xfuncionario,
  float yfuncionario
  ):
    Pessoa(nome,documento,email,endereco,data,telefone),
    _matricula(matricula),
    _dataAdmissao(dataAdmissao),
    _departamento(departamento),
    _cargo(cargo),
    _salario(salario),
    _status(status),
    _xfuncionario(xfuncionario),
    _yfuncionario(yfuncionario) {}


void Funcionario::setSalario(double salario)
{
  this->_salario=salario;
}

void Funcionario::demiteFuncionario(Data dataDemissao)
{
  this->_dataDemissao=dataDemissao;   
}

std::string Funcionario::getStatus()
{
  return this->_status;
}

void Funcionario::setSalarios(double salario,Data data)
{
  _salarios.push_back(salario);
  _datas.push_back(salario);
}

void Funcionario::getSalarios(){
  int tam=_salarios.size();
  int x=0;
  cout<<"Histórico de salários"<<endl;
  for(x=0;x<tam;x++){
  cout<<"Salário: ";
  cout<<_salarios[x];  
  cout<<"  Data: ";
  cout<<_datas[x].getDia();
    cout<<"/";
  cout<<_datas[x].getMes();
  cout<<"/";
  cout<<_datas[x].getAno()<<endl;
  }
}
    
float Funcionario::getXfuncionario(){
  return this->_xfuncionario;
}

float Funcionario::getYfuncionario(){
  return this->_yfuncionario;
}
