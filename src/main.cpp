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
Empresa empresa;

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
    cout << "Digite o nome do funcionário:" << endl;
    cin.ignore();
    getline(cin,nome);
    cout << "Digite o documento do funcionário:" << endl;
    cin.ignore();
    getline(cin,documento);
    cout << "Digite o email do funcionário:" << endl;
    cin.ignore();
    getline(cin,email);
    cout << "Digite o endereço do funcionário:" << endl;
    cin.ignore();
    getline(cin,endereco);
    cout << "Digite o telefone do funcionário:" << endl;
    cin.ignore();
    getline(cin,telefone); 
    system("clear");
    cout << "Funcionário cadastrado com sucesso!" << endl;
    a=1;
    break;
    }

    if(numx==4){
    bool tipo;
    system("clear");
    cout << "Digite o nome do cliente:" << endl;
    cin.ignore();
    getline(cin,nome);
    cout << "Digite o documento do cliente:" << endl;
    cin.ignore();
    getline(cin,documento);
    cout << "Digite o email do cliente:" << endl;
    cin.ignore();
    getline(cin,email);
    cout << "Digite o endereço do cliente:" << endl;
    cin.ignore();
    getline(cin,endereco);
    cout << "Digite o telefone do cliente:" << endl;
    cin.ignore();
    getline(cin,telefone); 
    cout << "Digite o tipo do cliente:" << endl;
    int t=0;
    while(t==0){
    int valor;
    valor=0;
    cout << "1 - Pessoa jurídica" << endl;  
    cout << "2 - Pessoa física" << endl;  
    cin>>valor;
    if(valor==1){
    tipo=false;
    t=1;
    }
    else if(valor==2){
    tipo=true;
    t=1;
    }
    else{
    cout << "Digite um valor válido:" << endl;
    t=0;
    }
    }
    Cliente cliente(nome,documento,email,endereco,telefone,tipo);
    empresa.addCliente(cliente);
    system("clear");
    cout << "Cliente cadastrado com sucesso!" << endl;
    a=1;
    break;
    }

    if(numx==5){
    system("clear");
    std::string nome_cargo;
    cout << "Digite o nome do cargo:" << endl;
    cin.ignore();
    getline(cin,nome_cargo);
    Cargo cargo(nome_cargo);
    empresa.addCargo(cargo);
    system("clear");
    cout << "Cargo cadastrado com sucesso!" << endl;
    }
    
    if(numx==6){
    system("clear");
    std::string nome_depart;
    cout << "Digite o nome do departamento:" << endl;
    cin.ignore();
    getline(cin,nome_depart);
    Departamento departamento(nome_depart);
    empresa.addDepartamento(departamento);
    system("clear");
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
    cout<<"1- Aba com informações de usuários, funcionários, clientes, produtos, lotes e fornecedores."<<endl;
    

    cout<<"Digite uma das opcoes:"<<endl;

    int num = 0;
    cin >> num;

    if(num==1){
    system("clear");
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
    Usuario usermain("Main","main","main");
    empresa.addUsuario(usermain);
    Usuario usermain2("Main2","main2","main2");
    empresa.addUsuario(usermain2);

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
    std::cout<<"Login efetuado com sucesso!"<<std::endl;
    menuPrincipal();
    }
    else{
    system("clear");
    std::cout<<"Usuário e/ou senha não existem!"<<std::endl;
    y=1;
    }
    }
    }
    return 0;
}
