#include <iostream>
#include <vector>
#include <string>

#include "../include/Pessoa.h"
#include "../include/Funcionario.h"
#include "../include/Cliente.h"
#include "../include/"
#include "../include/Cargo.h"  
#include "../include/Departamento.h"



using namespace std;


void case_1(){
   int a=0;
    while(a==0){
    cout <<"CADASTRAR:" << endl;
    cout <<"1- Usuário" << endl;
    cout <<"2- Funcionário" << endl;
    cout <<"3- Fornecedor" << endl;
    cout <<"4- Cliente"<<endl;
    cout <<"Digite uma das opcoes:" << endl;
  
    int numx=0;
    cin >> numx;

    if(numx==1){
        cout <<"Digite o nome:" << endl;
        cin>>nome;
        cout <<"Digite o cpf:" << endl;
        cout <<"Cliente cadastrado com sucesso:" << endl;
        a=1;
        break;
    }

    else{
        cout << "Digite um valor valido!" << endl;
    }
    }
}


int main(){
    int x=0;
    int y=0;

    while(x==0){
    y=0;
    while(y==0){
    cout<<"Bem vindo ao sistema!"<<endl;
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

    
    else{
    cout << "Digite um valor valido!" << endl; 
    }

    }    
}
    return 0;
}
