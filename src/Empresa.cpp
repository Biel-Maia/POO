#include <iostream>
#include "../include/Empresa.h"

#include "../include/Usuario.h"
#include "../include/Pessoa.h"
#include "../include/Funcionario.h"
#include "../include/Cliente.h"
#include "../include/Cargo.h"  
#include "../include/Departamento.h"
#include <vector>

Empresa::Empresa(){
}

void Empresa::addUsuario(Usuario usuario){
  _usuarios.push_back(usuario);
}

void Empresa::addCargo(Cargo cargo){
  _cargos.push_back(cargo);
}

void Empresa::addDepartamento(Departamento departamento){
  _departamentos.push_back(departamento);
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
    else{
    return 0;
    }
  }
  else{
  return 0;  
  }
  }
  return 0;
}