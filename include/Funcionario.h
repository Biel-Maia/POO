#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H


#include "../include/Pessoa.h"
#include "../include/Departamento.h"
#include "../include/Cargo.h"
#include "../include/Data.h"
#include <string>
#include <map>


class Funcionario : public Pessoa{
      
  private:
      int                     _matricula;
      Data                    _dataAdmissao;
      Data                    _dataDemissao;
      Departamento            _departamento;
      Cargo                   _cargo;
      double                  _salario;
      std::map<Data,double>   _salarios;
      std::string             _status;
      double                  _dissidio;

  public:
      Funcionario(
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
      std::string             status           
      );

    void alteraSalario();
    void demiteFuncionario();
    std::string getStatus();


};















#endif