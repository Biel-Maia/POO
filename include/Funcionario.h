#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H


#include "../include/Pessoa.h"
#include "../include/Departamento.h"
#include <string>
#include <map>


class Funcionario : public Pessoa{
      
  private:
      int                _matricula;
      Departamento       _departamento;
      Cargo              _cargo;
      double             _salarioAtual;
      map<double,double> _salario;
      std::string        _status;
      double             _dissidio;

  public:
      Funcionario(
      std::string nome,
      std::string documento,
      std::string email,
      std::string endereco,
      std::string telefone,
      int                matricula,
      Departamento       departamento,
      Cargo              cargo,
      double             salarioAtual,
      map<double,double> salario,
      std::string        status,
      double             dissidio            
      );

    void alteraSalario(double Data,double salarioNovo);
    void demiteFuncionario();
    std::string getStatus();


};















#endif