#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>
#include <map>

#include "Pessoa.h"
#include "Data.h"


class Funcionario : public Pessoa
{
  private:
    int matricula;
    Data admissao;
    Data demissao;
    std::string departamento;
    std::string cargo;
    std::string status;
    std::map<double, Data> salario;

  public:
    Funcionario(int _matricula,
                Data _admissao,
                Data _demissao,
                std::string _departamento,
                std::string _cargo,
                std::string _status,
                std::map<double, Data> _salario);
    void demiteFuncionario();
    void alteraSalario();
    std::string statusFuncionario();
    bool cadastraDepartamento();
    bool cadastraCargo();
};


#endif