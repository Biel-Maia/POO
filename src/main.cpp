#include <iostream>
#include <vector>
#include <string>


using namespace std;





int main(){
    int x=0;
    int y=0;

    while(x==0){
    y=0;
    while(y==0){
    cout<<"Bem vindo ao sistema!"<<endl;
    cout<<"MENU:"<<endl;
    cout<<"1- Acesso de informações de usuários, funcionários, clientes e fornecedores."<<endl;
    cout<<"5) Sair"<<endl;
    

    cout<<"Digite uma das opcoes:"<<endl;

    int num = 0;
    cin >> num;

    if(num==1){
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
