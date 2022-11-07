#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <cmath>
#include "../include/Pessoa.h"
#include "../include/Funcionario.h"
#include "../include/Cliente.h"
#include "../include/Cargo.h"  
#include "../include/Departamento.h"
#include "../include/Usuario.h"
#include "../include/Empresa.h"


using namespace std;

void case_1(){
    std::string nome;
    std::string documento;
    std::string email;
    std::string endereco;
    std::string telefone;

  
    int a=0;
    while(a==0){
    cout <<"CADASTRAR:" << endl;
    cout <<"1- Usuário" << endl;
    cout <<"2- Funcionário" << endl;
    cout <<"3- Fornecedor" << endl;
    cout <<"4- Cliente"<<endl;
    cout <<"5- Cargo"<<endl;
    cout <<"6- Departamento"<<endl;
    cout <<"Digite uma das opcoes:" << endl;
  
    int numx=0;
    cin >> numx;

    if(numx==1){
    a=1;
    break;
    }
      
    if(numx==2){
    system("clear");
    cout << "Digite o nome do funcionário!" << endl;
    cin.ignore();
    getline(cin,nome);
    cout << "Digite o documento do funcionário!" << endl;
    cin.ignore();
    getline(cin,documento);
    cout << "Digite o email do funcionário!" << endl;
    cin.ignore();
    getline(cin,email);
    cout << "Digite o nome do endereço!" << endl;
    cin.ignore();
    getline(cin,endereco);
    cout << "Digite o telefone do funcionário!" << endl;
    cin.ignore();
    getline(cin,telefone); 
    cout << "Escolha o departamento do funcionário!" << endl;
    system("clear");
    cout << "Funcionário cadastrado com sucesso!" << endl;
    a=1;
    break;
    }
      
    if(numx==6){
    std::string nome_depart;
    cout << "Digite o nome do departamento!" << endl;
    cin.ignore();
    getline(cin,nome_depart);
    Departamento departamento(nome_depart);
    cout << "Departamento cadastrado com sucesso!" << endl;
    }

    else{
    cout << "Digite um valor valido!" << endl;
    }
    }
}
void menuPrincipal(){
      int x=0;
      int y=0;
  
      while(x==0){
      y=0;
      while(y==0){
    cout<<"MENU:"<<endl;
    cout<<"1- Aba com informações de usuários, funcionários, clientes e fornecedores."<<endl;
    cout<<"5) Sair"<<endl;
    

    cout<<"Digite uma das opcoes:"<<endl;

    int num = 0;
    cin >> num;

    if(num==1){
    case_1();
    y=1;
    break;
    }

    if(num==5){
    
    }
    else{
    cout << "Digite um valor valido!" << endl; 
    }

    }    
} 
}

int main(){
    Empresa empresa;
    Usuario usermain("Main","main","main");
    empresa.addUsuario(usermain);

    std::string user;
    std::string senha;
    int x=0;
    int y=0;
  
    while(x==0){
    y=0;
    while(y==0){
    cout<<"Bem vindo ao sistema!"<<endl;
    cout<<"Digite seu login:"<<endl;
    cin>>user;
    cout<<"Digite sua senha:"<<endl;
    cin>>senha;
    empresa.verificaLogin(user,senha);
    if(empresa.verificaLogin(user,senha)==1){
    system("clear");
    std::cout<<"Login efetuado com sucesso"<<std::endl;
    menuPrincipal();
    }
    else{
    y=1;
    }
    }
    }
    return 0;
}
