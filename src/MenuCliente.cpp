#include "../include/MenuCliente.h"
#include "../include/Data.h"
#include "../include/Empresa.h"

#include <iostream>
#include <string>

using namespace std;

MenuCliente::MenuCliente():{};


bool MenuCliente::validaCPF(string documento)
{
  int multiplicador = 10;
  int soma = 0, aux, resto, cod_1, cod_2;
  for(int i = 0; i<9; i++)
  {
    aux = documento[i]-'0';
    soma+= aux*(multiplicador-i);
  }
  
  resto = soma%11;
  if(resto < 2)
    cod_1 = 0;
  
  else
    cod_1 = 11 - resto;
  
  if(cod_1 != (documento[9]-'0'))
        return false;
  
  else 
  {
    soma = 0;
    multiplicador = 11;
    for(int i = 0; i<10; i++)
    {
        aux = documento[i]-'0';
        soma+= aux*(multiplicador-i);
    }
    
    resto = soma%11;
    if(resto < 2)
      cod_2 = 0;
    
    else 
      cod_2 = 11 - resto;
        
    if(cod_2 != (documento[10]-'0'))
      return false;
    
    else
      return true;
  }
}




void MenuCliente::cadastrarCliente()
{
  string nome;
  string documento;
  string email;
  string endereco;
  Data data;
  int dia;
  int mes;
  int ano;
  string telefone;

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
  while(t==0)
  {
    int valor;
    valor=0;
    cout << "1 - Pessoa jurídica" << endl;  
    cout << "2 - Pessoa física" << endl;  
    cin>>valor;
    
    if(valor==1)
    {
      tipo=false;
      t=1;
    }
      
    else if(valor==2)
    {
      tipo=true;
      t=1;
    }
      
    else
    {
      cout << "Digite um valor válido:" << endl;
      t=0;
    }
  }
    
  data.setDia(dia);
  data.setMes(mes);
  data.setAno(ano);
  Cliente cliente(nome,documento,email,endereco,data,telefone,tipo);
  empresa->addCliente(cliente);
  system("clear");
  cout << "Cliente cadastrado com sucesso!" << endl;
}