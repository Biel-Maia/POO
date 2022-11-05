#include <string>
#include <map>

#include "../include/Data.h"
#include "../include/Funcionario.h"


Funcionario::Funcionario(int _matricula,
                        Data _admissao,
                        Data _demissao,
                        std::string _departamento,
                        std::string _cargo,
                        std::string _status
                        ):
                        
{
  matricula = _matricula;
  admissao = _admissao;
  demissao = _demissao;
  departamento = _departamento;
  cargo = _cargo;
  status = _status;
  salario = _salario;
}

std::string nome,
          std::string documento,
          std::string email,
          std::string endereco,
          Data dataNascimento,
          std::string telefone
          ):        
          _nome(nome),
          _documento(documento),
          _email(email),
          _endereco(endereco),
          _dataNascimento(dataNascimento),
          _telefone(telefone)
          {}

void Funcionario::demiteFuncionario()
{
  
}

void Funcionario::alteraSalario()
{
  
}

std::string Funcionario::statusFuncionario()
{
  
}

bool Funcionario::cadastraCargo()
{
  
}