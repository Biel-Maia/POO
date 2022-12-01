#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H


#include "../include/Pessoa.h"
#include "../include/Departamento.h"
#include "../include/Cargo.h"
#include "../include/Data.h"

#include <iostream>
#include <string>
#include <vector>


class Funcionario : public Pessoa
{
  private:
    int _matricula;
    Data _dataAdmissao;
    Data _dataDemissao;
    Departamento _departamento;
    Cargo _cargo;
    double _salario;
    std::vector<double> _salarios;
    std::vector<Data> _datas;
    std::string _status;
    double _dissidio;
    float _xfuncionario;
    float _yfuncionario;

  public:
    Funcionario
    (
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
    );

    void setSalario(double salario);
    void demiteFuncionario(Data dataDemissao);
    std::string getStatus();
    void setSalarios(double salario, Data data);
    void getSalarios();
    float getXfuncionario();
    float getYfuncionario();   
};

#endif