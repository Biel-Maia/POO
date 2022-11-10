#ifndef EMRPESA_H
#define EMPRESA_H

#include "../include/Usuario.h"
#include "../include/Pessoa.h"
#include "../include/Funcionario.h"
#include "../include/Cliente.h"
#include "../include/Cargo.h"  
#include "../include/Departamento.h"
#include <vector>
#include <string>

class Empresa{

  private:
    std::vector<Usuario> _usuarios;
    std::vector<Pessoa> _pessoas;
    std::vector<Funcionario> _funcionarios;
    std::vector<Cliente> _clientes;
    std::vector<Cargo>    _cargos;
    std::vector<Departamento> _departamentos;
    
  public:
    Empresa();

    void addUsuario(Usuario usuario);
    void addCargo(Cargo cargo);
    void addCliente(Cliente cliente);
    void addFuncionario(Funcionario funcionario);
    void addDepartamento(Departamento departamento);
    int  verificaLogin(std::string user, std::string senha);
    void getDepartamentos();
    void getCargos();
    void getFuncionarios();
    Departamento getDepartamento(int posicao);
    Cargo getCargo(int posicao);
    void alterarSalario(int funcionario,double salario);
};
#endif