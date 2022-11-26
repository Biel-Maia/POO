#ifndef EMPRESA_H
#define EMPRESA_H

#include "../include/Usuario.h"
#include "../include/Pessoa.h"
#include "../include/Funcionario.h"
#include "../include/Cliente.h"
#include "../include/Cargo.h"  
#include "../include/Departamento.h"
#include "../include/Categoria.h"
#include "../include/Veiculo.h"
#include "../include/MateriaPrima.h"
#include "../include/Fornecedor.h"
#include "../include/Rota.h"

#include <vector>
#include <string>

class Empresa
{
  private:
    Empresa();
    static Empresa *ptr; 
    std::vector<Usuario> _usuarios;
    std::vector<Pessoa> _pessoas;
    std::vector<Funcionario> _funcionarios;
    std::vector<Cliente> _clientes;
    std::vector<Cargo> _cargos;
    std::vector<Veiculo> _veiculos;
    std::vector<Departamento> _departamentos;
    std::vector<Categoria> _categorias;
    std::vector<MateriaPrima> _materias;
    std::vector<Fornecedor>  _fornecedores;
    std::vector<Rota> _rotas;
  
  public:
    static Empresa *Instance(void)
    {
      if(!ptr)
        ptr = new Empresa();

      return ptr;
    } 
    
    void addUsuario(Usuario usuario);
    void addCategoria(Categoria categoria);
    void addCargo(Cargo cargo);
    void addCliente(Cliente cliente);
    void addFuncionario(Funcionario funcionario);
    void addVeiculo(Veiculo veiculo);
    void addDepartamento(Departamento departamento);
    void addMateriaPrima(MateriaPrima materiaprima);
    void addFornecedor(Fornecedor fornecedor);
    void addRota(Rota rota);
    int verificaLogin(std::string user, std::string senha);
    void getDepartamentos();
    void getCargos();
    void getFuncionarios();
    void getMateriasPrimas();
    void getFornecedores();
    void getVeiculos();
    Departamento getDepartamento(int posicao);
    Cargo getCargo(int posicao);
    MateriaPrima getMateriaPrima(int posicao);
    Fornecedor getFornecedor(int posicao);
    Veiculo getVeiculo(int posicao);
    Funcionario getFuncionario(int posicao);
    void alterarSalario(int funcionario, double salario, Data data);
    bool getTamDepartamentos();
    bool getTamCargos();
    void demiteFuncionario(int funcionario, Data data);
};

#endif
