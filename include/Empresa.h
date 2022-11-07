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
    void addDepartamento(Departamento departamento);
    int  verificaLogin(std::string user, std::string senha);
};
#endif