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
      Data        data,
      std::string telefone,
      int                     matricula,
      Data                    dataAdmissao,
      Departamento            departamento,
      Cargo                   cargo,
      double                  salario,
      std::map<Data,double>   salarios,
      std::string             status):
      Pessoa(nome,documento,email,endereco,data,telefone),
      _matricula(matricula),
      _dataAdmissao(dataAdmissao),
      _departamento(departamento),
      _cargo(cargo),
      _salario(salario),
      _salarios(salarios),
      _status(status){};


    void Funcionario::alteraSalario(){
      
    }

    void Funcionario::demiteFuncionario(){

    }

    std::string Funcionario::getStatus(){
      return this->_status;
    }

    