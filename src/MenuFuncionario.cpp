#include "../include/MenuFuncionario.h"
#include "../include/Data.h"
#include "../include/Empresa.h"

#include <iostream>
#include <string>

using namespace std;

MenuFuncionario::MenuFuncionario(){}

bool MenuFuncionario::validaCPF(string documento)
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


void MenuFuncionario::cadastrarFuncionario()
{
  string nome;
  string documento;
  string email;
  string endereco;
  Data dataNasc;
  int  diaNasc;
  int  mesNasc;
  int  anoNasc;
  string telefone;
  int matricula;
  Data dataAdmissao;
  int diaAdmiss;
  int mesAdmiss;
  int anoAdmiss;
  int escolheDepartamento;
  int escolheCargo;
  double salario;
  string status;
  float xfuncionario;
  float yfuncionario;
  
  system("clear");
  cout << "Digite o nome do funcionário:" << endl;
  cin.ignore();
  getline(cin,nome);
  
  int z=0; 
  while(z==0)
  {
    cout << "Digite o documento do funcionário:" << endl;
    cin.ignore();
    getline(cin,documento);
    
    if(validaCPF(documento)==true)
      z=1; 
  
    else
    {
      cout << "Digite um CPF válido" << endl;  
      z=0;
    }  
  }
    
  cout << "Digite o email do funcionário:" << endl;
  cin.ignore();
  getline(cin,email);
  cout << "Digite o endereço do funcionário:" << endl;
  cin.ignore();
  getline(cin,endereco);
  
  int d=0;
  while(d==0)
  {
    cout << "Digite o dia de nascimento do funcionário:" << endl;
    cin>>diaNasc;
    
    if(diaNasc>31)
    {
      cout << "Digite um dia válido:" << endl;  
      d=0;
    }
      
    else
      d=1;  
      
  }
    
  int e=0;
  while(e==0)
  {
    cout << "Digite o mês de nascimento do funcionário:" << endl;
    cin>>mesNasc;
    
    if(mesNasc>12)
    {
      cout << "Digite um mês válido:" << endl;
      e=0;
    }
    
    else
      e=1;  
  }
  
  int f=0;
  while(f==0)
  {
    cout << "Digite o ano de nascimento do funcionário:" << endl;
    cin>>anoNasc;
    
    if(anoNasc<1900)
    {
      cout << "Digite um ano válido" << endl;  
      f=0;
    }
      
    else
      f=1;
  }
    
  cout << "Digite a matrícula do funcionário:" << endl;
  cin>>matricula;
    
  int g=0;
  while(g==0)
  {
    cout << "Digite o dia de admissão do funcionário:" << endl;
    cin>>diaAdmiss;
    
    if(diaAdmiss>31)
    {
      cout << "Digite um dia válido" << endl;
      g=0;
    }
      
    else
      g=1; 
  }
    
  int h=0;
  while(h==0)
  {
    cout << "Digite o mês de admissão do funcionário:" << endl;
    cin>>mesAdmiss;
    
    if(mesAdmiss>12)
    {
      cout << "Digite um mês válido:" << endl;
      h=0;
    }
    
    else
      h=1; 
  }
  
  int i=0;
  while(i==0)
  {
    cout << "Digite o ano de admissão do funcionário:" << endl;
    cin>>anoAdmiss;
    
    if(anoAdmiss>1900)
      i=1;  
      
    else
    {
      cout << "Digite um ano válido" << endl;  
      i=0;
    }
  }
  
  cout << "Escolha um departamento:" << endl;
  empresa->getDepartamentos();
  cin>>escolheDepartamento;
  escolheDepartamento--;
  cout << "Escolha um cargo" << endl;
  empresa->getCargos();
  cin>>escolheCargo;
  escolheCargo--;
  cout << "Digite o salário do funcionário:" << endl;
  cin>>salario;
  cout << "Digite o status do funcionário:" << endl;
  cin.ignore();
  getline(cin,status);
  
  cout << "Digite o Latitude do funcionário:" << endl;
  cin>>xfuncionario;
  cout << "Digite o Longitude do funcionário:" << endl;
  cin>>yfuncionario;
  
  dataNasc.setDia(diaNasc);
  dataNasc.setMes(mesNasc);
  dataNasc.setAno(anoNasc);
  dataAdmissao.setDia(diaAdmiss);
  dataAdmissao.setMes(mesAdmiss);
  dataAdmissao.setAno(anoAdmiss);
  Funcionario funcionario(
    nome,documento,email,endereco,dataNasc,telefone,
    matricula,dataAdmissao,
    empresa->getDepartamento(escolheDepartamento),
    empresa->getCargo(escolheCargo),
    salario,status);
  empresa->addFuncionario(funcionario);
  funcionario.setSalarios(dataAdmissao,salario);
  system("clear");
  cout << "Funcionário cadastrado com sucesso!" << endl;
}

void MenuFuncionario::alterarSalario()
{
  empresa->getFuncionarios();
  double salario;
  int funcionario;
  Data data;
  int dia,mes,ano;
  cout <<"Escolha o funcionário<< endl";
  cin>>funcionario;
  funcionario--;
  cout <<"Digite um novo salário<< endl";
  cin>>salario;
  
  int d=0;
  while(d==0)
  {
    cout << "Digite o dia de alteração de salário:" << endl;
    cin>>dia;
    
    if(dia>31)
    {
      cout << "Digite um dia válido:" << endl;  
      d=0;
    }
      
    else
      d=1;  
  }  
    
  int e=0;
  while(e==0)
  {
    cout << "Digite o mês de alteração de salário:" << endl;
    cin>>mes;
    
    if(mes>12)
    {
      cout << "Digite um mês válido:" << endl;
      e=0;
    }
      
    else
      e=1;  
  }
    
  int f=0;
  while(f==0)
  {
    cout << "Digite o ano de alteração de salário:" << endl;
    cin>>ano;
    
    if(ano<1900)
    {
      cout << "Digite um ano válido" << endl;  
      f=0;
    }
      
    else
      f=1;
  }
  
  empresa->alterarSalario(funcionario,salario,data);
  system("clear");
  cout << "Salário alterado com sucesso!" << endl;
}

void MenuFuncionario::historicoSalarios()
{
  
}

void MenuFuncionario::aplicarDissidio()
{
  
}

void MenuFuncionario::demitirFuncionario()
{
  empresa->getFuncionarios();

  int funcionario;
  Data data;
  int dia,mes,ano;

  cout <<"Escolha o funcionário<< endl";
  cin>>funcionario;
  funcionario--;
  
  int d=0;
  while(d==0)
  {
    cout << "Digite o dia de demissão do funcionário:" << endl;
    cin>>dia;
    
    if(dia>31)
    {
      cout << "Digite um dia válido:" << endl;  
      d=0;
    }
    
    else
      d=1;  
  }  
    
  int e=0;
  while(e==0)
  {
    cout << "Digite o mês de demissão do funcionário:" << endl;
    cin>>mes;
    
    if(mes>12)
    {
      cout << "Digite um mês válido:" << endl;
      e=0;
    }
      
    else
      e=1;  
  }
    
  int f=0;
  while(f==0)
  {
    cout << "Digite o ano de demissão do funcionário:" << endl;
    cin>>ano;
    
    if(ano<1900)
    {
      cout << "Digite um ano válido" << endl;  
      f=0;
    }
      
    else
    f=1;
  }
  
  system("clear");
  cout << "Funcionário demitido com sucesso!" << endl;
}