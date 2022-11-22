#ifndef EMRPESA_H
#define EMPRESA_H

#include "../include/Usuario.h"
#include "../include/Pessoa.h"
#include "../include/Funcionario.h"
#include "../include/Cliente.h"
#include "../include/Cargo.h"  
#include "../include/Departamento.h"
#include "../include/Categoria.h"
#include <vector>
#include <string>

class Empresa{

  private:
    Empresa();
    static Empresa *ptr; 

    std::vector<Usuario> _usuarios;
    std::vector<Pessoa> _pessoas;
    std::vector<Funcionario> _funcionarios;
    std::vector<Cliente> _clientes;
    std::vector<Cargo>    _cargos;
    std::vector<Departamento> _departamentos;
    std::vector<Categoria>    _categorias;
  
  public:
     
    static Empresa *Instance( void ){
      if( !ptr){
          ptr = new Empresa();
        }
      return ptr;
    } 
    
    void addUsuario(Usuario usuario);
    void addCategoria(Categoria categoria);
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
    void alterarSalario(int funcionario,double salario, Data data);
    bool getTamDepartamentos();
    bool getTamCargos();
    void demiteFuncionario(int funcionario,Data data);
};
#endif
