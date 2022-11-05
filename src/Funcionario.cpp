#include "../include/Funcionario.h"
#include "../include/Pessoa.h"
#include "../include/Departamento.h"
#include "../include/Cargo.h"
#include <string>
#include <map>



Funcionario::Funcionario(
      std::string nome,
      std::string documento,
      std::string email,
      std::string endereco,
      std::string telefone,
      int                     matricula,
      Departamento            departamento,
      Cargo                   cargo,
      double                  salarioAtual,
      std::map<double,double> salario,
      std::string             status,
      double                  dissidio):
      Pessoa(nome,documento,email,endereco,telefone),
      _matricula(matricula),
      _departamento(departamento),
      _cargo(cargo),
      _salarioAtual(salarioAtual),
      _salario(salario),
      _status(status),
      _dissidio(dissidio){};


    void Funcionario::alteraSalario(double Data,double salarioNovo){
      
    }

    void Funcionario::demiteFuncionario(){

    }

    std::string Funcionario::getStatus(){
      return this->_status;
    }

    