#include <iostream>
#include "../include/Empresa.h"

#include "../include/Usuario.h"
#include "../include/Pessoa.h"
#include "../include/Funcionario.h"
#include "../include/Cliente.h"
#include "../include/Cargo.h"  
#include "../include/Departamento.h"
#include "../include/Categoria.h"
#include <vector>
#include <string>



Empresa *Empresa::ptr = 0; 

Empresa::Empresa(){
  std::cout << "Singleton Carregado." << std::endl;
}

void Empresa::addUsuario(Usuario usuario){
  _usuarios.push_back(usuario);
}

void Empresa::addCategoria(Categoria categoria){
  _categorias.push_back(categoria);
}

void Empresa::addCargo(Cargo cargo){
  _cargos.push_back(cargo);
}

void Empresa::addDepartamento(Departamento departamento){
  _departamentos.push_back(departamento);
}

void Empresa::addCliente(Cliente cliente){
  _clientes.push_back(cliente);
}

void Empresa::addFuncionario(Funcionario funcionario){
  _funcionarios.push_back(funcionario);
}

int Empresa::verificaLogin(std::string user, std::string senha){
  int tamanho;
  tamanho=_usuarios.size();
  for(int x=0;x<tamanho;x++){
  std::string userx;
  std::string senhax;
  userx=_usuarios[x].getUser();
  senhax=_usuarios[x].getSenha();
  if(user==userx){
    if(senha==senhax){
    return 1;
    }
    }
  }
  return 0;
}

void Empresa::getDepartamentos(){
  int tamanho = this->_departamentos.size();
  int num=0;
  for(int x=0;x<tamanho;x++){
  num++;
  cout<<num;
  cout<<"- ";
  cout<<_departamentos[x].getNome()<<endl;
  }
}

void Empresa::getCargos(){
  int tamanho = this->_cargos.size();
  int num=0;
  for(int x=0;x<tamanho;x++){
  num++;
  cout<<num;
  cout<<"- ";
  cout<<_cargos[x].getNome()<<endl;
  }
}

void Empresa::getFuncionarios(){
  int tamanho = this->_funcionarios.size();
  int num=0;
  for(int x=0;x<tamanho;x++){
  num++;
  cout<<num;
  cout<<"- ";
  std::string nome;
  nome=_funcionarios[x].getNome();
  cout<<nome<<endl;
  }
}

Departamento Empresa::getDepartamento(int posicao){
    return this->_departamentos[posicao];
}

Cargo Empresa::getCargo(int posicao){
    return this->_cargos[posicao];
}

void Empresa::alterarSalario(int funcionario, double salario, Data data){
  this->_funcionarios[funcionario].setSalario(salario);
  this->_funcionarios[funcionario].setSalarios(data,salario);
}

bool Empresa::getTamDepartamentos(){
  int x=0;
  x=this->_departamentos.size();
  if(x==0){
  return false;  
  }
  else{
  return true;  
  }
}

bool Empresa::getTamCargos(){
  int x=0;
   x=this->_cargos.size();
  if(x==0){
  return false;  
  }
  else{
  return true;  
  }
}