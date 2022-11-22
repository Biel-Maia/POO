 #include <iostream>
#include <vector>
#include <string>
#include <map>
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
#include "../include/Categoria.h"
#include "../include/Usuario.h"
#include "../include/LogAcessoNegado.h"
#include "../include/LogLeitura.h"
#include "../include/LogEscrita.h"
#include "../include/ExcecaoAcessoNegado.h"


using namespace std;
Empresa * empresa = Empresa::Instance();

void realizarOperacaoEscolhida(Usuario *usuario, Data *data, string tipo_operacao,
    string classe, string metodo, string atributo = ""){
    try {
            if(usuario->getPermissao(classe, metodo) == false)
                throw ExcecaoAcessoNegado(); // lança exceção se usuário tenta acessar método sem permissão
            else{
                *data = data->getDataAtual(); // atualiza hora

                if(tipo_operacao == "acessar"){
                    // Realiza operação necessária e salva o log
                    // ...

                    LogLeitura log_leitura(usuario->getUser(), data, classe, atributo);
                    bool salvou = log_leitura.salvarLog();
                    log_leitura.~LogLeitura();
                }else{ // alterar
                    // Realiza operação necessária e salva o log
                    // ...
                    // TODO: Definir maneira de invocar o método correto que fará a atualização do atributo

                    LogEscrita log_escrita(usuario->getUser(), data, classe, atributo, "Mariana", "Marianna");
                    bool salvou = log_escrita.salvarLog();
                    log_escrita.~LogEscrita();
                }
            }

        } catch (ExcecaoAcessoNegado& e) {
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

bool validaCPF(std::string documento){
int multiplicador = 10;
    int soma = 0, aux, resto, cod_1, cod_2;
    for(int i = 0; i<9; i++){
        aux = documento[i]-'0';
        soma+= aux*(multiplicador-i);
    }
    resto = soma%11;
    if(resto < 2){
        cod_1 = 0;
    } else {
        cod_1 = 11 - resto;
    }
    if(cod_1 != (documento[9]-'0')){
        return false;
    } else {
        soma = 0;
        multiplicador = 11;
        for(int i = 0; i<10; i++){
            aux = documento[i]-'0';
            soma+= aux*(multiplicador-i);
        }
        resto = soma%11;
        if(resto < 2){
            cod_2 = 0;
        } else {
            cod_2 = 11 - resto;
        }
        if(cod_2 != (cpf[10]-'0')){
            return false;
        } else {
            return true;
        }
    }
}

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
    empresa->addUsuario(cadUser);
    system("clear");
    cout << "Usuário cadastrado com sucesso!" << endl; 
}

void cadastrarCategoria(){
    system("clear");
    std::string nome_categoria;
    cout << "Digite o nome da categoria:" << endl;
    cin.ignore();
    getline(cin,nome_categoria);
    Categoria categoria(nome_categoria);
    empresa->addCategoria(categoria);
    system("clear");
    cout << "Categoria cadastrada com sucesso!" << endl; 
}

void cadastrarCargo(){
    system("clear");
    std::string nome_cargo;
    cout << "Digite o nome do cargo:" << endl;
    cin.ignore();
    getline(cin,nome_cargo);
    Cargo cargo(nome_cargo);
    empresa->addCargo(cargo);
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
    empresa->addDepartamento(departamento);
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
    int z=0;
    while(z=0){
    cout << "Digite o documento do funcionário:" << endl;
    cin.ignore();
    getline(cin,documento);
    if(validaCPF(documento)=true){
    z=1; 
    }
    else{
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
    while(d==0){
    cout << "Digite o dia de nascimento do funcionário:" << endl;
    cin>>diaNasc;
    if(diaNasc>31){
    cout << "Digite um dia válido:" << endl;  
    d=0;
    }
    else{
    d=1;  
    }  
    }
    int e=0;
    while(e=0){
    cout << "Digite o mês de nascimento do funcionário:" << endl;
    cin>>mesNasc;
    if(mesNasc>12){
    cout << "Digite um mês válido:" << endl;
    e=0;
    }
    else{
    e=1;  
    }
    }
    int f=0;
    while(f=0){
    cout << "Digite o ano de nascimento do funcionário:" << endl;
    cin>>anoNasc;
    if(anoNasc<1900){
    cout << "Digite um ano válido" << endl;  
    f=0;
    }
    else{
    f=1;
    }
    }
    cout << "Digite a matrícula do funcionário:" << endl;
    cin>>matricula;
    int g=0;
    while(g=0){
    cout << "Digite o dia de admissão do funcionário:" << endl;
    cin>>diaAdmiss;
    if(diaAdmiss>31){
    cout << "Digite um dia válido" << endl;
    g=0;
    }
    else{
    g=1; 
    }
    }
    int h=0;
    while(h=0){
    cout << "Digite o mês de admissão do funcionário:" << endl;
    cin>>mesAdmiss;
    if(mesAdmiss>12){
    cout << "Digite um mês válido:" << endl;
    h=0;
    }
    else{
    h=1; 
    }
    }
    int i=0;
    while(i=0){
    cout << "Digite o ano de admissão do funcionário:" << endl;
    cin>>anoAdmiss;
    if(anoAdmiss>1900){
    i=1;  
    }
    else{
    cout << "Digite um ano válido" << endl;  
    i=0;
    }
    }
    if(empresa->getTamDepartamentos()=false){
    break;
    cout << "Não existe nenhum departamento cadastrado" << endl;  
    } 
    cout << "Escolha um departamento:" << endl;
    empresa->getDepartamentos();
    cin>>escolheDepartamento;
    escolheDepartamento--;
    if(empresa->getTamCargos()=false){
    break;
    cout << "Não existe nenhum cargo cadastrado" << endl;  
    } 
    cout << "Escolha um cargo" << endl;
    empresa->getCargos();
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
    empresa->getDepartamento(escolheDepartamento),
    empresa->getCargo(escolheCargo),
    salario,status);
    empresa->addFuncionario(funcionario);
    funcionario.setSalarios(dataAdmissao,salario);
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
    empresa->addCliente(cliente);
    system("clear");
    cout << "Cliente cadastrado com sucesso!" << endl;
}

void alterarSalario(){
  empresa->getFuncionarios();
  double salario;
  int    funcionario;
  Data   data;
  int    dia,mes,ano;
  cout <<"Escolha o funcionário<< endl";
  cin>>funcionario;
  funcionario--;
  cout <<"Digite um novo salário<< endl";
  cin>>salario;
  int d=0;
    while(d==0){
    cout << "Digite o dia de alteração de salário:" << endl;
    cin>>dia;
    if(dia>31){
    cout << "Digite um dia válido:" << endl;  
    d=0;
    }
    else{
    d=1;  
    }  
    }
    int e=0;
    while(e=0){
    cout << "Digite o mês de alteração de salário:" << endl;
    cin>>mes;
    if(mes>12){
    cout << "Digite um mês válido:" << endl;
    e=0;
    }
    else{
    e=1;  
    }
    }
    int f=0;
    while(f=0){
    cout << "Digite o ano de alteração de salário:" << endl;
    cin>>ano;
    if(ano<1900){
    cout << "Digite um ano válido" << endl;  
    f=0;
    }
    else{
    f=1;
    }
    }
  empresa->alterarSalario(funcionario,salario,data);
  system("clear");
  cout << "Salário alterado com sucesso!" << endl;
}

void historicoSalarios(){
  
}



void aplicarDissidio(){
  
}

void demitirFuncionario(){
    empresa->getFuncionarios();

    int    funcionario;
    Data   data;
    int    dia,mes,ano;

    out <<"Escolha o funcionário<< endl";
    cin>>funcionario;
    funcionario--;
  
    int d=0;
    while(d==0){
    cout << "Digite o dia de demissão do funcionário:" << endl;
    cin>>dia;
    if(dia>31){
    cout << "Digite um dia válido:" << endl;  
    d=0;
    }
    else{
    d=1;  
    }  
    }
    int e=0;
    while(e=0){
    cout << "Digite o mês de demissão do funcionário:" << endl;
    cin>>mes;
    if(mes>12){
    cout << "Digite um mês válido:" << endl;
    e=0;
    }
    else{
    e=1;  
    }
    }
    int f=0;
    while(f=0){
    cout << "Digite o ano de demissão do funcionário:" << endl;
    cin>>ano;
    if(ano<1900){
    cout << "Digite um ano válido" << endl;  
    f=0;
    }
    else{
    f=1;
    }
    }
  
  system("clear");
  cout << "Funcionário demitido com sucesso!" << endl;
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
      empresa->getFuncionarios();
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
    cout <<"7- Categoria" <<endl;
    cout <<"8- Voltar ao menu principal"<<endl;
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
      cadastrarCategoria();
      a=1;
      break;
    }

    if(numx==8){
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
    
   
   //std::cout << "p: " << empresa << std::endl; // teste singleton
  
    system("clear");
    Usuario usermain("Main","admin","admin");
    empresa->addUsuario(usermain);
    Usuario usermain2("Main2","main2","main2");
    empresa->addUsuario(usermain2);

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
    empresa->verificaLogin(user,senha);
    if(empresa->verificaLogin(user,senha)==1){
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
