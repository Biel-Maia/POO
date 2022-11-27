#include <iostream>
#include "../include/Empresa.h"
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
#include "../include/Produto.h"
#include "../include/Lote.h"

#include <vector>
#include <string>


Empresa *Empresa::ptr = 0; 

Empresa::Empresa()
{
}

void Empresa::addUsuario(Usuario usuario)
{
  _usuarios.push_back(usuario);
}

void Empresa::addCategoria(Categoria categoria)
{
  _categorias.push_back(categoria);
}

void Empresa::addCargo(Cargo cargo)
{
  _cargos.push_back(cargo);
}

void Empresa::addDepartamento(Departamento departamento)
{
  _departamentos.push_back(departamento);
}

void Empresa::addCliente(Cliente cliente)
{
  _clientes.push_back(cliente);
}

void Empresa::addFuncionario(Funcionario funcionario)
{
  _funcionarios.push_back(funcionario);
}

void Empresa::addVeiculo(Veiculo veiculo){
  _veiculos.push_back(veiculo);
}

void Empresa::addMateriaPrima(MateriaPrima materiaprima){
  _materias.push_back(materiaprima);
}

void Empresa::addFornecedor(Fornecedor fornecedor){
  _fornecedores.push_back(fornecedor);
}

void Empresa::addRota(Rota rota){
  _rotas.push_back(rota);
}

void Empresa::addProduto(Produto produto){
  _produtos.push_back(produto);
}

void Empresa::addLote(Lote lote){
  _lotes.push_back(lote);
}

int Empresa::verificaLogin(std::string user, std::string senha)
{
  int tamanho;
  tamanho=_usuarios.size();
  for(int x=0;x<tamanho;x++)
  {
    std::string userx;
    std::string senhax;
    userx=_usuarios[x].getUser();
    senhax=_usuarios[x].getSenha();
    if(user==userx)
    {
      if(senha==senhax)
        return 1;
    }
  }
  
  return 0;
}

void Empresa::getDepartamentos()
{
  int tamanho = this->_departamentos.size();
  int num=0;
  for(int x=0;x<tamanho;x++)
  {
    num++;
    cout<<num;
    cout<<"- ";
    cout<<_departamentos[x].getNome()<<endl;
  }
}

void Empresa::getCargos()
{
  int tamanho = this->_cargos.size();
  int num=0;
  for(int x=0;x<tamanho;x++)
  {
    num++;
    cout<<num;
    cout<<"- ";
    cout<<_cargos[x].getNome()<<endl;
  }
}

void Empresa::getFuncionarios()
{
  int tamanho = this->_funcionarios.size();
  int num=0;
  for(int x=0;x<tamanho;x++)
  {
    num++;
    cout<<num;
    cout<<"- ";
    std::string nome;
    nome=_funcionarios[x].getNome();
    cout<<nome<<endl;
  }
}

void Empresa::getMateriasPrimas()
{
  int tamanho = this->_materias.size();
  int num=0;
  for(int x=0;x<tamanho;x++)
  {
    num++;
    cout<<num;
    cout<<"- ";
    cout<<_materias[x].getNome()<<endl;
  }
}

void Empresa::getFornecedores()
{
  int tamanho = this->_fornecedores.size();
  int num=0;
  for(int x=0;x<tamanho;x++)
  {
    num++;
    cout<<num;
    cout<<"- ";
    cout<<_fornecedores[x].getNome()<<endl;
  }
}

void Empresa::getVeiculos()
{
  int tamanho = this->_veiculos.size();
  int num=0;
  for(int x=0;x<tamanho;x++)
  {
    num++;
    cout<<num;
    cout<<"- ";
    cout<<"Placa::"<<_veiculos[x].getPlaca()<<" Tipo:"<<_veiculos[x].getTipo()<<endl;
  }
}

void Empresa::getProdutos()
{
  int tamanho = this->_produtos.size();
  int num=0;
  for(int x=0;x<tamanho;x++)
  {
    num++;
    cout<<num;
    cout<<"- ";
    cout<<_produtos[x].getNome()<<endl;
  }
}

void Empresa::getCategorias()
{
  int tamanho = this->_categorias.size();
  int num=0;
  for(int x=0;x<tamanho;x++)
  {
    num++;
    cout<<num;
    cout<<"- ";
    cout<<_categorias[x].getNome()<<endl;
  }
}

void Empresa::getLotes()
{
  int tamanho = this->_lotes.size();
  int num=0;
  for(int x=0;x<tamanho;x++)
  {
    num++;
    cout<<num;
    cout<<"- ";
    cout<<_lotes[x].getNumeroLote()<<endl;
  }
}


Departamento Empresa::getDepartamento(int posicao)
{
  return this->_departamentos[posicao];
}

Cargo Empresa::getCargo(int posicao)
{
  return this->_cargos[posicao];
}

Veiculo Empresa::getVeiculo(int posicao)
{
  return this->_veiculos[posicao];
}

MateriaPrima Empresa::getMateriaPrima(int posicao)
{
  return this->_materias[posicao];
}

Fornecedor Empresa::getFornecedor(int posicao)
{
  return this->_fornecedores[posicao];
}

Funcionario Empresa::getFuncionario(int posicao)
{
  return this->_funcionarios[posicao];
}

Produto Empresa::getProduto(int posicao)
{
  return this->_produtos[posicao];
}

Categoria Empresa::getCategoria(int posicao)
{
  return this->_categorias[posicao];
}

Lote Empresa::getLote(int posicao){
  return this->_lotes[posicao];
}

void Empresa::alterarSalario(int funcionario, double salario, Data data)
{
  this->_funcionarios[funcionario].setSalario(salario);
  this->_funcionarios[funcionario].setSalarios(data,salario);
}

bool Empresa::getTamDepartamentos()
{
  int x=0;
  x=this->_departamentos.size();
  if(x==0)
    return false;  
  
  else
    return true;  
}

bool Empresa::getTamCargos()
{
  int x=0;
   x=this->_cargos.size();
  if(x==0)
    return false;  
  
  else
    return true;  
}

void Empresa::demiteFuncionario(int funcionario,Data data)
{
  this->_funcionarios[funcionario].demiteFuncionario(data);
}