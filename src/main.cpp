#include "../include/Empresa.h"
#include "../include/Pessoa.h"
#include "../include/Funcionario.h"
#include "../include/Cliente.h"
#include "../include/Cargo.h"  
#include "../include/Departamento.h"
#include "../include/Usuario.h"
#include "../include/MenuFuncionario.h"
#include "../include/MenuCliente.h"
#include "../include/Data.h"
#include "../include/Categoria.h"
#include "../include/Usuario.h"
#include "../include/LogAcessoNegado.h"
#include "../include/LogLeitura.h"
#include "../include/LogEscrita.h"
#include "../include/ExcecaoAcessoNegado.h"


#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stdio.h>
#include <cmath>


using namespace std;

Empresa * empresa = Empresa::Instance();


void realizarOperacaoEscolhida(
  Usuario *usuario, 
  Data *data, 
  string tipo_operacao,
  string classe, 
  string metodo, 
  string atributo = "")
{
  try 
  {
    if(usuario->getPermissao(classe, metodo) == false)
      throw ExcecaoAcessoNegado(); // lança exceção se usuário tenta acessar método sem permissão
    else
    {
      *data = *data->getData(); // atualiza hora

      if(tipo_operacao == "acessar")  // Realiza operação necessária e salva o log
      {
        LogLeitura log_leitura(usuario->getUser(), data, classe, atributo);
        bool salvou = log_leitura.salvarLog();
        log_leitura.~LogLeitura();
      }
      
      else
      { // alterar
                    // Realiza operação necessária e salva o log
                    // ...
                    // TODO: Definir maneira de invocar o método correto que fará a atualização do atributo

        LogEscrita log_escrita(usuario->getUser(), data, classe, atributo, "Mariana", "Marianna");
        bool salvou = log_escrita.salvarLog();
        log_escrita.~LogEscrita();
      }
    }
  } 
  
  catch (ExcecaoAcessoNegado& e) 
  {
    // Exemplo:
    // Se usuário quer alterar nome de cliente, e não é permitido,
    // Ou seja: permissoes_de_acesso[Cliente][setNome] = false;
    // i.e, usuario.getPermissao("Cliente", "setNome") retorna false
    // Então, a exceção será lançada e o log de acesso negado será chamado
    cout<<endl<<"Usuário não pode acessar essa funcionalidade"<<endl;
    LogAcessoNegado log_acesso_negado(usuario->getUser(), data, classe, metodo);
    bool salvou = log_acesso_negado.salvarLog();
    if(salvou != true)
      cout << "Erro ao salvar o arquivo" << endl; // mensagem genérica e arbitrária
    log_acesso_negado.~LogAcessoNegado();
  }
}

bool validaCPF(std::string documento)
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

Departamento consultarDepartamentos()
{
  Departamento departamento("abc");
  return departamento;
}

void cadastrarUsuario()
{
  system("clear");
  string tipo;
  string user;
  string senha;

  cout<<"Digite o tipo de Usuário:"<<endl;
  cin>>tipo;
  cout<<"Digite seu login:"<<endl;
  cin>>user;
  cout<<"Digite sua senha:"<<endl;
  cin>>senha;
  Usuario cadUser(tipo,user,senha);
  empresa->addUsuario(cadUser);
  system("clear");
  cout << "Usuário cadastrado com sucesso!" << endl; 
}

void cadastrarCategoria()
{
  system("clear");
  string nome_categoria;
  cout << "Digite o nome da categoria:" << endl;
  cin.ignore();
  getline(cin,nome_categoria);
  Categoria categoria(nome_categoria);
  empresa->addCategoria(categoria);
  system("clear");
  cout << "Categoria cadastrada com sucesso!" << endl; 
}

void cadastrarCargo()
{
  system("clear");
  string nome_cargo;
  cout << "Digite o nome do cargo:" << endl;
  cin.ignore();
  getline(cin,nome_cargo);
  Cargo cargo(nome_cargo);
  empresa->addCargo(cargo);
  system("clear");
  cout << "Cargo cadastrado com sucesso!" << endl; 
}

void cadastrarDepartamento()
{
  system("clear");
  string nome_depart;
  cout << "Digite o nome do departamento:" << endl;
  cin.ignore();
  getline(cin,nome_depart);
  Departamento departamento(nome_depart);
  empresa->addDepartamento(departamento);
  system("clear");
  cout << "Departamento cadastrado com sucesso!" << endl;
}

void cadastrarFornecedor()
{

}

void menuUsuario()
{
  system("clear");
  int a=0;
  while(a==0)
  {
    cout <<"Usuario:"<< endl;
    cout <<"1- Cadastrar"<< endl;
    cout <<"2- "<< endl;
    cout <<"3- Definir permissões de acesso para um Usuário"<< endl;
    cout <<"4- Aplicar dissídio"<<endl;
    cout <<"5- Consultar histórico de salários"<<endl;
    cout <<"6- Consultar funcionários"<<endl;
    cout <<"7- Voltar ao menu"<<endl;
    cout <<"Digite uma das opcoes:" << endl;
  
    int numx=0;
    cin >> numx;

    if(numx==1)
    {
      MenuFuncionario::cadastrarFuncionario();
      a=1;
      break;
    }
      
    if(numx==2)
    {
      MenuFuncionario::demitirFuncionario();
      a=1;
      break;
    }

    if(numx==3)
    {
      MenuFuncionario::alterarSalario();
      a=1;
      break;
    }

    if(numx==4)
    {
      MenuFuncionario::aplicarDissidio();
      a=1;
      break;
    }

    if(numx==5)
    {
      MenuFuncionario::historicoSalarios();
      a=1;
      break;
    }
    
    if(numx==6)
    {
      empresa->getFuncionarios();
      a=1;
      break;
    }

    if(numx==7)
    {
      system("clear");
      a=1;
      break;
    }

    else
      cout << "Digite um valor valido!" << endl;
  }
}



void menuFuncionario()
{
  system("clear");
  int a=0;
  while(a==0)
  {
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

    if(numx==1)
    {
      MenuFuncionario::cadastrarFuncionario();
      a=1;
      break;
    }
      
    if(numx==2)
    {
      MenuFuncionario::demitirFuncionario();
      a=1;
      break;
    }

    if(numx==3)
    {
      MenuFuncionario::alterarSalario();
      a=1;
      break;
    }

    if(numx==4)
    {
      MenuFuncionario::aplicarDissidio();
      a=1;
      break;
    }

    if(numx==5)
    {
      MenuFuncionario::historicoSalarios();
      a=1;
      break;
    }
    
    if(numx==6)
    {
      empresa->getFuncionarios();
      a=1;
      break;
    }

    if(numx==7)
    {
      system("clear");
      a=1;
      break;
    }

    else
      cout << "Digite um valor valido!" << endl;
  }
}

void case_1()
{
  int a=0;
  while(a==0)
  {
    cout <<"." << endl;
    cout <<"1- Usuário" << endl;
    cout <<"2- Funcionário" << endl;
    cout <<"3- Fornecedor" << endl;
    cout <<"4- Cadastrar cliente"<<endl;
    cout <<"5- Cargo"<<endl;
    cout <<"6- Departamento"<<endl;
    cout <<"7- Categoria" <<endl;
    cout <<"8- Voltar ao menu principal"<<endl;
    cout <<"Digite uma das opcoes:" << endl;
  
    int numx=0;
    cin >> numx;

    if(numx==1)
    {
      cadastrarUsuario();
      a=1;
      break;
    }
      
    if(numx==2)
    {
      menuFuncionario();
      a=1;
      break;
    }

    if(numx==3)
    {
      cadastrarFornecedor();
      a=1;
      break;
    }

    if(numx==4)
    {
      MenuCliente::cadastrarCliente();
      a=1;
      break;
    }

    if(numx==5)
    {
      cadastrarCargo();
      a=1;
      break;
    }
    
    if(numx==6)
    {
      cadastrarDepartamento();
      a=1;
      break;
    }
      
    if(numx==7)
    {
      cadastrarCategoria();
      a=1;
      break;
    }

    if(numx==8)
    {
      a=1;
      break;
    }

    else
      cout << "Digite um valor valido!" << endl;
  }
}

void menuPrincipal()
{
  int x=0;
  int y=0;
  
  while(x==0)
  {
    y=0;
    while(y==0)
    {
      cout<<"MENU:"<<endl;
      cout<<"1- Aba com informações de usuários, funcionários, clientes, produtos, lotes e fornecedores."<<endl;
      cout<<"Digite uma das opcoes:"<<endl;

      int num = 0;
      cin >> num;
      if(num==1)
      {
        system("clear");
        case_1();
        y=1;
        break;
      }

      if(num==5)
      {
    
      }
        
      else
        cout << "Digite um valor valido!" << endl; 
    }    
  } 
}

int main()
{
  //std::cout << "p: " << empresa << std::endl; // teste singleton
  
  system("clear");
  Usuario usermain("Main","admin","admin");
  empresa->addUsuario(usermain);
  Usuario usermain2("Main2","main2","main2");
  empresa->addUsuario(usermain2);

  string user;
  string senha;
  int x=0;
  int y=0;
  
  while(x==0)
  {
    y=0;
    while(y==0)
    {
      cout<<"Bem vindo ao sistema!"<<endl;
      cout<<"Digite seu login:"<<endl;
      cin>>user;
      cout<<"Digite sua senha:"<<endl;
      cin>>senha;
      empresa->verificaLogin(user,senha);
      if(empresa->verificaLogin(user,senha)==1)
      {
        system("clear");
        cout<<"Login efetuado com sucesso!"<<endl;
        menuPrincipal();
      }
        
      else
      {
        system("clear");
        cout<<"Usuário e/ou senha não existem!"<<endl;
      y=1;
      }
    }
  }
  
  return 0;
}
