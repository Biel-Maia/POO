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
}