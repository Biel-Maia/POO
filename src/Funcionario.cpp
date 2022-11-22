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
      std::string             status):
      Pessoa(nome,documento,email,endereco,data,telefone),
      _matricula(matricula),
      _dataAdmissao(dataAdmissao),
      _departamento(departamento),
      _cargo(cargo),
      _salario(salario),
      _status(status){};


    void Funcionario::setSalario(double salario){
      this->_salario=salario;
    }

    void Funcionario::demiteFuncionario(Data dataDemissao){
       this->_dataDemissao=dataDemissao;   
    }

    std::string Funcionario::getStatus(){
      return this->_status;
    }

      
    
    void Funcionario::setSalarios(Data data,double salario){
      //this->_salarios.insert({data,salario});
    }
    
    