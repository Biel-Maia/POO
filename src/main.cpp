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
#include "../include/Data.h"


using namespace std;
Empresa empresa;

Departamento consultarDepartamentos(){
  Departamento departamento("abc");
  return departamento;
}

void cadastrarUsuario(){
    system("clear");
    std::string tipo;
    std::string user;
    std::string senha;

    cout<<"Digite o tipo de Usuário:"<<endl;
    cin>>tipo;
    cout<<"Digite seu login:"<<endl;
    cin>>user;
    cout<<"Digite sua senha:"<<endl;
    cin>>senha;
    Usuario cadUser(tipo,user,senha);
    empresa.addUsuario(cadUser);
    system("clear");
    cout << "Usuário cadastrado com sucesso!" << endl; 
}

void cadastrarCargo(){
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

void cadastrarDepartamento(){
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

void cadastrarFornecedor(){
  
}

void cadastrarFuncionario(){
    std::string             nome;
    std::string             documento;
    std::string             email;
    std::string             endereco;
    Data                    dataNasc;
    int                     diaNasc;
    int                     mesNasc;
    int                     anoNasc;
    std::string             telefone;
    int                     matricula;
    Data                    dataAdmissao;
    int                     diaAdmiss;
    int                     mesAdmiss;
    int                     anoAdmiss;
    int                     escolheDepartamento;
    int                     escolheCargo;
    double                  salario;
    std::string             status;

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
    cout << "Digite o dia de nascimento do funcionário:" << endl;
    cin>>diaNasc;
    cout << "Digite o mês de nascimento do funcionário:" << endl;
    cin>>mesNasc;
    cout << "Digite o ano de nascimento do funcionário:" << endl;
    cin>>anoNasc;
    cout << "Digite a matrícula do funcionário:" << endl;
    cin>>matricula;
    cout << "Digite o dia de admissão do funcionário:" << endl;
    cin>>diaAdmiss;
    cout << "Digite o mês de admissão do funcionário:" << endl;
    cin>>mesAdmiss;
    cout << "Digite o ano de admissão do funcionário:" << endl;
    cin>>anoAdmiss;
    cout << "Escolha um departamento:" << endl;
    empresa.getDepartamentos();
    cin>>escolheDepartamento;
    escolheDepartamento--;
    cout << "Escolha um cargo" << endl;
    empresa.getCargos();
    cin>>escolheCargo;
    escolheCargo--;
    cout << "Digite o salário do funcionário:" << endl;
    cin>>salario;
    cout << "Digite o status do funcionário:" << endl;
    cin.ignore();
    getline(cin,status);
    dataNasc.setDia(diaNasc);
    dataNasc.setMes(mesNasc);
    dataNasc.setAno(anoNasc);
    dataAdmissao.setDia(diaAdmiss);
    dataAdmissao.setMes(mesAdmiss);
    dataAdmissao.setAno(anoAdmiss);
    Funcionario funcionario(
    nome,documento,email,endereco,dataNasc,telefone,
    matricula,dataAdmissao,
    empresa.getDepartamento(escolheDepartamento),
    empresa.getCargo(escolheCargo),
    salario,status);
    empresa.addFuncionario(funcionario);
    //empresa.setSalarios(dataAdmissao,salario);
    system("clear");
    cout << "Funcionário cadastrado com sucesso!" << endl;
}

void cadastrarCliente(){
    std::string nome;
    std::string documento;
    std::string email;
    std::string endereco;
    Data        data;
    int         dia;
    int         mes;
    int         ano;
    std::string telefone;

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
    cout << "Digite o dia de nascimento do cliente:" << endl;
    cin>>dia;
    cout << "Digite o mês de nascimento do cliente:" << endl;
    cin>>mes;
    cout << "Digite o ano de nascimento do cliente:" << endl;
    cin>>ano;
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
    data.setDia(dia);
    data.setMes(mes);
    data.setAno(ano);
    Cliente cliente(nome,documento,email,endereco,data,telefone,tipo);
    empresa.addCliente(cliente);
    system("clear");
    cout << "Cliente cadastrado com sucesso!" << endl;
}

void alterarSalario(){
  consultarFuncionarios();
  double salario;
  int    funcionario;
  cout <<"Escolha o funcionário<< endl";
  cin>>funcionario;
  cout <<"Digite um novo salario<< endl";
  cin>>salario;
  empresa.alterarSalario(funcionario,salario);
}

void historicoSalarios(){
  
}

void consultarFuncionarios(){
  empresa.getFuncionarios();
}

void aplicarDissidio(){
  
}

void demitirFuncionario(){
  empresa.getFuncionarios();
  cout <<"Digite a data de demissão"<< endl;
}

void menuFuncionario(){
  system("clear");
  int a=0;
    while(a==0){
    cout <<"FUNCIONÁRIO:"<< endl;
    cout <<"1- Cadastrar"<< endl;
    cout <<"2- Demitir"<< endl;
    cout <<"3- Alterar salário"<< endl;
    cout <<"4- Aplicar dissídio"<<endl;
    cout <<"5- Consultar histórico de salários"<<endl;
    cout <<"6- Consultar funcionários"<<endl;
    cout <<"7- Voltar ao menu"<<endl;
    cout <<"Digite uma das opcoes:" << endl;
  
    int numx=0;
    cin >> numx;

    if(numx==1){
      cadastrarFuncionario();
      a=1;
      break;
    }
      
    if(numx==2){
      demitirFuncionario();
      a=1;
      break;
    }

    if(numx==3){
      alterarSalario();
      a=1;
      break;
    }

    if(numx==4){
      aplicarDissidio();
      a=1;
      break;
    }

    if(numx==5){
      historicoSalarios();
      a=1;
      break;
    }
    
    if(numx==6){
      consultarFuncionarios();
      a=1;
      break;
    }

    if(numx==7){
      system("clear");
      a=1;
      break;
    }

    else{
    cout << "Digite um valor valido!" << endl;
    }
    }
}

void case_1(){
  
    int a=0;
    while(a==0){
    cout <<"." << endl;
    cout <<"1- Usuário" << endl;
    cout <<"2- Funcionário" << endl;
    cout <<"3- Fornecedor" << endl;
    cout <<"4- Cliente"<<endl;
    cout <<"5- Cargo"<<endl;
    cout <<"6- Departamento"<<endl;
    cout <<"7- Voltar ao menu principal"<<endl;
    cout <<"Digite uma das opcoes:" << endl;
  
    int numx=0;
    cin >> numx;

    if(numx==1){
      cadastrarUsuario();
      a=1;
      break;
    }
      
    if(numx==2){
      menuFuncionario();
      a=1;
      break;
    }

    if(numx==3){
      cadastrarFornecedor();
      a=1;
      break;
    }

    if(numx==4){
      cadastrarCliente();
      a=1;
      break;
    }

    if(numx==5){
      cadastrarCargo();
      a=1;
      break;
    }
    
    if(numx==6){
      cadastrarDepartamento();
      a=1;
      break;
    }

    if(numx==7){
      a=1;
      break;
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
    system("clear");
    Usuario usermain("Main","admin","admin");
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
