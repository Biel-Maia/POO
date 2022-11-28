#include "../include/Empresa.h"
#include "../include/Pessoa.h"
#include "../include/Funcionario.h"
#include "../include/Cliente.h"
#include "../include/Cargo.h"  
#include "../include/Departamento.h"
#include "../include/Usuario.h"
#include "../include/Data.h"
#include "../include/Categoria.h"
#include "../include/Fornecedor.h"
#include "../include/Usuario.h"
#include "../include/LogAcessoNegado.h"
#include "../include/LogLeitura.h"
#include "../include/LogEscrita.h"
#include "../include/ExcecaoAcessoNegado.h"
#include "../include/Estoque.h"
#include "../include/Lote.h"
#include "../include/Produto.h"
#include "../include/Venda.h"
#include "../include/Pagamento.h"
#include "../include/OrdemProducao.h"
#include "../include/OrdemCompra.h"


#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stdio.h>
#include <cmath>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;
using namespace std;


Empresa * empresa = Empresa::Instance();

Usuario usermain("admin","admin","admin");

Pagamento pagamento1("Cartão");
Pagamento pagamento2("Boleto");


bool validaCPF(std::string cpf)
{
  int l, r, _l, _r;
	bool b1, b2, b3, b4;

  b1 = b2 = b3 = b4 = false;
		l = 1;
		r = 9;
		_l = _r = 0;
  
		for (int i = 0; i < 11; ++i)
		{
			if(i != 3 && i != 7){
				_l += (l * (cpf[i] - '0'));
				_r += (r * (cpf[i] - '0'));
				l++; r--;
			}
		}
  
		if(((cpf[12] - '0') == (_l % 11)) && ((cpf[13] - '0') == (_r % 11))) 
			b1 = true;

		if(((cpf[12] - '0') == (_l % 11)) && ((cpf[13] - '0' == 0 && _r % 11 == 10))) 
			b2 = true;

		if(((cpf[13] - '0') == (_r % 11)) && ((cpf[12] - '0' == 0 && _l % 11 == 10))) 
			b3 = true;

		if(((cpf[12] - '0' == 0 && _l % 11 == 10)) && ((cpf[13] - '0' == 0 && _r % 11 == 10))) 
			b4 = true;
 
		if(b1 || b2 || b3 || b4)
			return true;
		else
			return false;
	
}

bool validaCNPJ(std::string vrCNPJ)
{
  vector<int> multiplicador = {6,5,4,3,2,9,8,7,6,5,4,3,2};
    int soma = 0;
    int aux, resto, cod_1, cod_2;
    for(int i=0; i<12; i++){
        aux = vrCNPJ[i] - '0';
        soma += aux*multiplicador[i+1];
    }
    resto = soma%11;
    if(resto < 2){
        cod_1 = 0;
    } else {
        cod_1 = 11 - resto;
    }
    if(cod_1 != (vrCNPJ[12] - '0')){
        return false;
    } else {
        soma = 0;
        for(int i=0; i<13; i++){
            aux = vrCNPJ[i] - '0';
            soma += aux*multiplicador[i];
        }
        resto = soma%11;
        if(resto < 2){
            cod_2 = 0;
        } else {
            cod_2 = 11 - resto;
        }
        if(cod_2 != (vrCNPJ[13] - '0')){
            return false;
        } else {
            return true;
        }
    }
}

void mostrarLogs(){
  system("clear");
  cout<<"LOGS DE ACESSO NEGADO:";
  empresa->getLogsAcessoNegado();
  cout<<endl;
  cout<<"LOGS DE ESCRITA:";
  empresa->getLogsEscrita();
  cout<<endl;
  cout<<"LOGS DE LEITURA:";
  empresa->getLogsLeitura();
  cout<<endl;
}

void cadastraFormaPagamento(){
  system("clear");
  string nomeFormaPagamento;
  cout << "Digite o nome da forma de pagamento:" << endl;
  cin.ignore();
  getline(cin,nomeFormaPagamento);
  Pagamento pagamento(nomeFormaPagamento);
  empresa->addFormasPagamento(pagamento);
  system("clear");
  cout << "Forma de pagamento criada com sucesso!" << endl;
  std::this_thread::sleep_for(2s);
  system("clear");
  
}

void realizarVenda(){
  system("clear");
  Data dataVenda;
  int  diaVenda;
  int  mesVenda;
  int  anoVenda;

  int d=0;
  while(d==0)
  {
    cout << "Digite o dia que a venda foi feita:" << endl;
    cin>>diaVenda;

    if(diaVenda>31)
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
    cout << "Digite o mês que a venda foi feita:" << endl;
    cin>>mesVenda;

    if(mesVenda>12)
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
    cout << "Digite o ano que a venda foi feita:" << endl;
    cin>>anoVenda;

    if(anoVenda<1900)
    {
      cout << "Digite um ano válido" << endl;  
      f=0;
    }

    else
      f=1;
  }

  dataVenda.setDia(diaVenda);
  dataVenda.setMes(mesVenda);
  dataVenda.setAno(anoVenda);
    

  Data dataLogLeitura;
  dataLogLeitura.dateNow();
  
  
  int escolheCliente=0;
  int escolheOrcamento=0;
  int quantidadeParcelas=0;
  double valorTotal=0;
  double valorParcela=0;
  
  empresa->getClientes();
  LogLeitura logleitura(usermain,dataLogLeitura,"Venda","Realizar Venda","Vector de Clientes da classe Empresa");
 empresa->addLogLeitura(logleitura);
  cout << "Escolha o cliente que vai realizar a compra:" << endl;
  cin>>escolheCliente;
  escolheCliente--;
  cout << "Escolha o orçamento que vai ser feita a venda:" << endl;
  empresa->getOrcamentos(empresa->getCliente(escolheCliente));
  LogLeitura logleitura2(usermain,dataLogLeitura,"Venda","Realizar Venda","Vector de orçamentos de um cliente da classe Empresa");
 empresa->addLogLeitura(logleitura2);
  cin>>escolheOrcamento;
  escolheOrcamento--;
  cout << "Escolha a quantidade de parcelas que deseja:" << endl;
  cin>>quantidadeParcelas;
  valorTotal=(empresa->getOrcamento(empresa->getCliente(escolheCliente),escolheOrcamento).getValorTotal());
  valorParcela=(valorTotal/quantidadeParcelas);

  int escolheFormaPagamento=0;
  empresa->getFormasPagamento();
  LogLeitura logleitura3(usermain,dataLogLeitura,"Venda","Realizar Venda","Vector de formas de pagamento da empresa");
 empresa->addLogLeitura(logleitura3);
  cin>>escolheFormaPagamento;
  escolheFormaPagamento--;
  
  
  Venda venda(dataVenda,empresa->getCliente(escolheCliente),empresa->getOrcamento(empresa->getCliente(escolheCliente),escolheOrcamento),valorTotal,empresa->getFormaPagamento(escolheFormaPagamento),quantidadeParcelas);
  system("clear");
  cout << "Venda realizada com sucesso:" << endl;
  cout << "O valor total é: "<<valorTotal<< endl;
  cout << "O valor de cada parcela é: "<<valorParcela<< endl;
  std::this_thread::sleep_for(2s);
  system("clear");
}

void cadastraOrcamento(){
    Data dataOrcamento;
    int  diaOrcamento;
    int  mesOrcamento;
    int  anoOrcamento;

    
     int d=0;
  while(d==0)
  {
    cout << "Digite o dia que o orçamento foi feito:" << endl;
    cin>>diaOrcamento;

    if(diaOrcamento>31)
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
    cout << "Digite o mês que o orçamento foi feito:" << endl;
    cin>>mesOrcamento;

    if(mesOrcamento>12)
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
    cout << "Digite o ano que o orçamento foi feito:" << endl;
    cin>>anoOrcamento;

    if(anoOrcamento<1900)
    {
      cout << "Digite um ano válido" << endl;  
      f=0;
    }

    else
      f=1;
  }

  dataOrcamento.setDia(diaOrcamento);
  dataOrcamento.setMes(mesOrcamento);
  dataOrcamento.setAno(anoOrcamento);

  Data dataLogLeitura;
  dataLogLeitura.dateNow();
  
  int escolheCliente=0;
  empresa->getClientes();
  LogLeitura logleitura(usermain,dataLogLeitura,"Orcamento","Cadastrar Orcamento","Vector de clientes da classe Empresa");
 empresa->addLogLeitura(logleitura);
  cout << "Escolha o cliente que vai fazer o orçamento:" << endl;
  cin>>escolheCliente;
  escolheCliente--;
  Orcamento orcamento(dataOrcamento,empresa->getCliente(escolheCliente));
  empresa->addOrcamento(orcamento);
  int escolheProduto=0;
  int quantidade=0;
  int x=0;
  double valorTotal=0;
  while(x==0){
   int sair=0; 
   escolheProduto=0;
   empresa->getProdutos();
   std::cout << "Escolha um produto: " << std::endl;
   cin>>escolheProduto;
   escolheProduto--;
   orcamento.setProduto(empresa->getProduto(escolheProduto));
   std::cout << "Digite a quantidade do produto: " << std::endl; 
  cin>>quantidade;
    int qtdProdEst=0;
    int qtdProdEstMin=0;
    std::string nome = empresa->getProduto(escolheProduto).getNome();
    qtdProdEst=empresa->getEstoqueProd(nome).getEstoque();
    qtdProdEstMin=empresa->getEstoqueProd(nome).getEstoqueMin();
    
    if((qtdProdEst-quantidade)<qtdProdEstMin){
      OrdemProducao ordem_producao(dataOrcamento,empresa->getProduto(escolheProduto));
      empresa->addOrdemProducao(ordem_producao);
      cout<<"Ordem de produção criada, não temos essa quantidade do produto no estoque."<<endl;
    }
  
    
   orcamento.setQuantidade(quantidade);
   valorTotal+=(empresa->getProduto(escolheProduto).getPreco())*(quantidade);
  std::cout << "Digite 0 para cancelar a operação ou 1 para escolher mais funcionários: " << std::endl; 
   cin>>sair;
    if(sair==1){
    x=0;
    }
    else{
    x=1;  
    }
  }
  LogLeitura logleitura2(usermain,dataLogLeitura,"Orcamento","Cadastrar Orcamento","Vector de produtos da empresa");
 empresa->addLogLeitura(logleitura2);
  orcamento.setValorTotal(valorTotal);
  system("clear");
  cout << "Orçamento realizado com sucesso!" << endl;
  cout << "O valor total ficou:" << valorTotal<<endl;
  std::this_thread::sleep_for(2s);
  system("clear");
}

void alterarQtdMateriaMin(){
  int escolheMateriaPrima;
  int quantidadeMin;
  Data dataLogLeitura;
  dataLogLeitura.dateNow();
  cout << "Escolha a matéria prima que deseja adicionar ao fornecedor:" << endl;
  empresa->getMateriasPrimas();
  LogLeitura logleitura(usermain,dataLogLeitura,"Materia Prima","Alterar quantidade minima de matéria prima","Vector de matérias primas da empresa");
 empresa->addLogLeitura(logleitura);
  cin>>escolheMateriaPrima;
  escolheMateriaPrima--;
  cout << "Digite a quantidade min da materia prima" << endl;
  cin>>quantidadeMin;
  empresa->getMateriaPrima(escolheMateriaPrima).setQtdMateriaMin(quantidadeMin);
  system("clear");

  Data dataLogEscrita;
  string a;
  string b;
  b=std::to_string(quantidadeMin);
  dataLogEscrita.dateNow();
  LogEscrita logescrita(usermain,dataLogEscrita,"Funcionario","Alterar Salario","Vector de salarios",a,b);
 empresa->addLogEscrita(logescrita);
  system("clear");
  cout << "Quantidade alterada com sucesso!" << endl;
  std::this_thread::sleep_for(2s);
  system("clear");
}

void cadastrarMateriaPrima(){
  system("clear");
  std::string nome;
  std::string unidadeMedida;
  int quantidadeEstoque=0;
  int quantidadeEstoqueMin=0;
  cout << "Digite o nome da matéria prima:" << endl;
  cin.ignore();
  getline(cin,nome);
  cout << "Digite a unidade de medida:" << endl;
  cin.ignore();
  getline(cin,unidadeMedida);
  cout << "Quantidade que o estoque possui:" << endl;
  cin>>quantidadeEstoque;
  cout << "Quantidade minima estoque" << endl;
  cin>>quantidadeEstoqueMin;
  MateriaPrima materiaPrima(nome,unidadeMedida,quantidadeEstoque,quantidadeEstoqueMin);
  empresa->addMateriaPrima(materiaPrima);
  system("clear");
  cout << "Matéria prima cadastrada com sucesso!" << endl;
  std::this_thread::sleep_for(2s);
  system("clear");
}

void menuMateriaPrima()
{
  system("clear");
  int a=0;
  while(a==0)
  {
    cout <<"Matéria Prima:"<< endl;
    cout <<"1- Cadastrar matéria prima"<< endl;
    cout <<"2- Atualizar quantidade minima de estoque"<< endl;
    cout <<"3- Voltar ao menu"<<endl;
    cout <<"Digite uma das opcoes:" << endl;
  
    int numx=0;
    cin >> numx;

    if(numx==1)
    {
      if(usermain.getPermissao("Materia Prima","Cadastrar Materia Prima")==false){
      system("clear");
      cout<<"O usuário logado não tem permissão para cadastrar materia prima.";
      Data data;
      data.dateNow();
      LogAcessoNegado logacessonegado(usermain,data,"Materia Prima","Cadastrar Materia Prima");
      empresa->addLogAcessoNegado(logacessonegado);
      a=1;
      break;
      }
      else{
        cadastrarMateriaPrima();
        //break;
      }
      
    }
      
    else if(numx==2)
    {
      if(usermain.getPermissao("Materia Prima","Alterar quantidade de materia prima.")==false){
      system("clear");
      cout<<"O usuário logado não tem permissão para alterar quantidade de materia prima.";
      Data data;
      data.dateNow();
      LogAcessoNegado logacessonegado(usermain,data,"Materia Prima","Alterar quantidade de materia prima");
      empresa->addLogAcessoNegado(logacessonegado);
      a=1;
      break;
      }
      else{
        alterarQtdMateriaMin();
        //break;
      }
    }

    else if(numx==3)
    {
      system("clear");
      a=1;
      //break;
    }


    else
      cout << "Digite um valor valido!" << endl;
  }
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
  std::this_thread::sleep_for(2s);
  system("clear");
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
  std::this_thread::sleep_for(2s);
  system("clear");
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
  std::this_thread::sleep_for(2s);
  system("clear");
}

void cadastrarVeiculo(){
  std::string placa;
  system("clear");
  std::string tipo;
  std::cout << "Digite a placa do veículo: " << std::endl;
  cin.ignore();
  getline(cin,placa);
  std::cout << "Digite o tipo do veiculo: " << std::endl;
  cin.ignore();
  getline(cin,tipo);
  int capacidade;
  std::cout << "Digite a capacidade do veiculo: " << std::endl;
  cin >> capacidade;
  Veiculo veiculo(placa,tipo, capacidade);
  empresa->addVeiculo(veiculo);
  system("clear");
  cout << "Veiculo cadastrado com sucesso!" << endl;
  std::this_thread::sleep_for(2s);
  system("clear");
}

void cadastrarRota(){
  int escolheVeiculo=0;
  int escolheFuncionarios=0;
  int x=0;
  Data horario;
  system("clear");
  std::string turno;
  empresa->getVeiculos();
  
  Data dataLogLeitura;
  dataLogLeitura.dateNow();
  LogLeitura logleitura(usermain,dataLogLeitura,"Rota","Cadastrar Rota","Vector de veiculos da empresa.");
  empresa->addLogLeitura(logleitura);
  
  std::cout << "Digite o veiculo que vai ser responsável pela rota: " << std::endl;
  cin>>escolheVeiculo;
  escolheVeiculo--;
  std::cout << "Digite o turno da rota: " << std::endl;
  cin.ignore();
  getline(cin,turno);
  int hora, min;
  std::cout << "Digite as horas: " << std::endl;
  cin>>hora;
  horario.setHora(hora);
  std::cout << "Digite os minutos: " << std::endl;
  cin>>min;
  horario.setMin(min);
  float latitude;
  std::cout << "Digite latitude da empresa: " << std::endl;
  cin>>latitude;
  float longitude;
  std::cout << "Digite longitude da empresa: " << std::endl;
  cin>>longitude;
  Rota rota(empresa->getVeiculo(escolheVeiculo),turno,horario,latitude,longitude);
  empresa->addRota(rota);
  while(x==0){
   int sair=0;
   system("clear"); 
   escolheFuncionarios=0;
   empresa->getFuncionarios();
   std::cout << "Escolha um funcionario: " << std::endl;
   cin>>escolheFuncionarios;
   escolheFuncionarios--;
   rota.setFuncionarios(empresa->getFuncionario(escolheFuncionarios));
  std::cout << "Digite 0 para cancelar a operação ou 1 para escolher mais funcionários: " << std::endl; 
   cin>>sair;
    if(sair==1){
    x=0;
    }
    else{
    x=1;  
    }
  }
  LogLeitura logleitura2(usermain,dataLogLeitura,"Rota","Cadastrar rota","Vector de funcionarios da empresa");
 empresa->addLogLeitura(logleitura2);
  std::cout << "Rota cadastrada com sucesso! " << std::endl;
  std::this_thread::sleep_for(2s);
  system("clear");
}

void cadastrarLote(){

  system("clear");
  
  Data dataLote;
  int  diaLote;
  int  mesLote;
  int  anoLote;
  int  horaLote;
  int  minutoLote;

  int d=0;
  while(d==0)
  {
    cout << "Digite o dia de produção do lote:" << endl;
    cin>>diaLote;

    if(diaLote>31)
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
    cout << "Digite o mês de produção do lote:" << endl;
    cin>>mesLote;

    if(mesLote>12)
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
    cout << "Digite o ano  de produção do lote:" << endl;
    cin>>anoLote;

    if(anoLote<1900)
    {
      cout << "Digite um ano válido" << endl;  
      f=0;
    }

    else
      f=1;
  }

  int g=0;
  while(g==0)
  {
    cout << "Digite a hora em que o lote foi produzido:" << endl;
    cin>>horaLote;

    if(horaLote>24)
    {
      cout << "Digite uma hora válida" << endl;  
      g=0;
    }

    else
      g=1;
  }

  int h=0;
  while(h==0)
  {
    cout << "Digite o minuto em que o lote foi produzido:" << endl;
    cin>>minutoLote;

    if(minutoLote>60)
    {
      cout << "Digite um minuto válido" << endl;  
      h=0;
    }

    else
      h=1;
  }
  dataLote.setDia(diaLote);
  dataLote.setMes(mesLote);
  dataLote.setAno(anoLote);
  dataLote.setHora(horaLote);
  dataLote.setMin(minutoLote);

  int numLote=0;
  cout << "Digite o número do lote:" << endl;
  cin >>numLote;

  int escolherProduto=0;
  empresa->getProdutos();

  Data dataLogLeitura;
  dataLogLeitura.dateNow();
  LogLeitura logleitura(usermain,dataLogLeitura,"Lote","Cadastrar lote","Vector de lote da classe empresa.");
  empresa->addLogLeitura(logleitura);
  
  cout << "Escolha o produto que foi produzido no lote:" << endl;
  cin >> escolherProduto;
  escolherProduto--;

  int quantidade=0;
  cout << "Digite a quantidade do produto que foi produzido no lote:" << endl;
  cin >> quantidade;

  int tam2=0;
  tam2=empresa->getProduto(escolherProduto).getTamVetor();
  int z=0;
  int quantidadequegasta=0;
  int quantidadequetenhoestoque=0;
  int quantidademinima=0;

  for(z=0;z<tam2;z++){
  std::string nome = empresa->getProduto(escolherProduto).getMateriaPrima(z).getNome();
  quantidadequegasta = empresa->getProduto(escolherProduto).getQuantidadeQueGasta(z);
  quantidadequetenhoestoque = empresa->getProduto(escolherProduto).getMateriaPrima(z).getEstoque();
  quantidademinima= empresa->getProduto(escolherProduto).getMateriaPrima(z).getEstoqueMin();
  if((quantidadequetenhoestoque-(quantidadequegasta*quantidade))<quantidademinima){
  OrdemCompra ordemCompra(dataLote);
  ordemCompra.setMateria(nome);  
  empresa->addOrdemCompra(ordemCompra);
  cout << "A quantidade da matéria prima" << nome <<"é menor que a quantidade mínuma, uma ordem de produção foi gerada" <<endl;
  }
  }

  
  Lote lote(dataLote,numLote,empresa->getProduto(escolherProduto),quantidade);
  empresa->addLote(lote);

  int a=0;
  int tam=empresa->getTamEstoque();
  for(a=0;a<tam;a++){
  if(empresa->getEstoque(a).getProduto().getNome() == empresa->getProduto(escolherProduto).getNome()){
  empresa->getEstoque(a).setLote(lote);
  empresa->getEstoque(a).setQuantidade(quantidade);
  }  
  }

  
  

  system("clear");
  cout << "Lote produzido com sucesso!" << endl;
  std::this_thread::sleep_for(2s);
  system("clear");
}

void adicionarMateriaPrimaProd(){
  int escolherProduto=0;
  int escolherMateriaPrima=0;
  int quantidade=0;
  system("clear");
  empresa->getProdutos();

  Data dataLogLeitura;
  dataLogLeitura.dateNow();
  
  LogLeitura logleitura(usermain,dataLogLeitura,"Produto","Adicionar matéria prima ao produto","Vector de produtos da empresa");
  empresa->addLogLeitura(logleitura);
  cout << "Escolha o produto que deseja adicionar matéria prima:" << endl;
  cin>>escolherProduto;
  escolherProduto--;
  empresa->getMateriasPrimas();

   
  LogLeitura logleitura2(usermain,dataLogLeitura,"Produto","Adicionar matéria prima ao produto","Vector de materias primas da empresa");
  empresa->addLogLeitura(logleitura2);
  
  cout << "Escolha a matéria prima que deseja adicionar:" << endl;
  cin>>escolherMateriaPrima;
  escolherMateriaPrima--;
  cout << "Digite a quantidade de matéria prima:" << endl;
  cin>>quantidade;
  empresa->getProduto(escolherProduto).setMateriaPrima(empresa->getMateriaPrima(escolherMateriaPrima));
  empresa->getProduto(escolherProduto).setQuantidade(quantidade);
  system("clear");
  cout << "Matéria prima adicionada com sucesso!" << endl;
  std::this_thread::sleep_for(2s);
  system("clear");
  
}

void adicionarPrecoProduto(){
  int escolherProduto=0;
  system("clear");
  empresa->getProdutos();
  Data dataLogLeitura;
  dataLogLeitura.dateNow();

  LogLeitura logleitura(usermain,dataLogLeitura,"Produto","Adicionar preco produto","Vector de produtos da empresa");
  empresa->addLogLeitura(logleitura);
  
  double preco;
  cout << "Escolha o produto que deseja alterar o preço:" << endl;
  cin>>escolherProduto;
  escolherProduto--;
  cout << "Digite o novo valor do produto:" << endl;
  cin>>preco;
  empresa->getProduto(escolherProduto).setPreco(preco);
  system("clear");
  cout << "Preço alterado com sucesso!" << endl;
  std::this_thread::sleep_for(2s);
  system("clear");
  
}

void cadastrarProduto(){
  int escolherCategoria=0;
  int escolherProduto=0;
  system("clear");
  string nome_p;
  cout << "Digite o nome do produto:" << endl;
  cin.ignore();
  getline(cin,nome_p);
  int codigo;
  cout << "Digite o codigo do produto:" << endl;
  cin>>codigo;
  double preco;
  cout << "Digite o preco do produto:" << endl;
  cin>>preco;
  int lote_min;
  cout << "Digite o lote mínimo que o produto deve ter:" << endl;
  cin>>lote_min;
  int estoque_min;
  cout << "Digite o estoque mínimo que o produto deve ter:" << endl;
  cin>>estoque_min;
  cout << "Escolha a categoria do produto:" << endl;
  empresa->getCategorias();

  Data dataLogLeitura;
  dataLogLeitura.dateNow();

  LogLeitura logleitura(usermain,dataLogLeitura,"Produto","Cadastrar produto","Vector de categorias da empresa");
  empresa->addLogLeitura(logleitura);
  
  cin>>escolherCategoria;
  escolherCategoria--;
  
  Produto produto(nome_p, codigo, preco, empresa->getCategoria(escolherCategoria), lote_min, estoque_min);
  empresa->addProduto(produto);
  Estoque estoque(produto);
  empresa->addEstoque(estoque);
  estoque.setQuantidadeMin(estoque_min);

   int x=0;
   while(x==0){
   int sair=0;
   system("clear"); 
   int escolherMateriasPrimas=0;
   empresa->getMateriasPrimas();
   cin>>escolherMateriasPrimas;
   escolherMateriasPrimas--;
   int quantidade = 0;
   cout << "Digite a quantidade de matéria prima:" << endl;
   cin>>quantidade;
   empresa->getProduto(escolherProduto).setMateriaPrima(empresa->getMateriaPrima(escolherMateriasPrimas));
   empresa->getProduto(escolherProduto).setQuantidade(quantidade);
   std::cout << "Digite 0 para cancelar a operação ou 1 para escolher mais materias primas: " << std::endl; 
   cin>>sair;
    if(sair==1){
    x=0;
    }
    else{
    x=1;  
    }
  }
  LogLeitura logleitura2(usermain,dataLogLeitura,"Produto","Cadastrar produto","Vector de matérias primas da empresa");
  empresa->addLogLeitura(logleitura2);
  
  system("clear");
  cout << "Produto cadastrado com sucesso!" << endl;
  std::this_thread::sleep_for(2s);
  system("clear");
  
}

void menuProduto(){
  system("clear");
  int a=0;
  while(a==0)
  {
    cout <<"Produto:"<< endl;
    cout <<"1- Cadastrar produto"<< endl;
    cout <<"2- Adicionar novo preço ao produto"<< endl;
    cout <<"3- Adicionar matéria prima e quantidade"<< endl;
    cout <<"Digite uma das opcoes:" << endl;
  
    int numx=0;
    cin >> numx;

    if(numx==1)
    {
      if(usermain.getPermissao("Produto","Cadastrar Produto")==false){
      system("clear");
      cout<<"O usuário logado não tem permissão para cadastrar produtos";
      Data data;
      data.dateNow();
      LogAcessoNegado logacessonegado(usermain,data,"Produto","Cadastrar Produto");
      empresa->addLogAcessoNegado(logacessonegado);
      a=1;
      break;
      }
      else{
      cadastrarProduto();
      a=1;
      }
    }
      
    if(numx==2)
    {
      if(usermain.getPermissao("Produto","Adicionar PrecoProduto")==false){
      system("clear");
      cout<<"O usuário logado não tem permissão para adicionar um novo preço ao produto";
      Data data;
      data.dateNow();
      LogAcessoNegado logacessonegado(usermain,data,"Produto","Adicionar PrecoProduto");
      empresa->addLogAcessoNegado(logacessonegado);
      a=1;
      break;
      }
      else{
      adicionarPrecoProduto();
      a=1;
      }
    }

    if(numx==3)
    {
      if(usermain.getPermissao("Produto","Adicionar Materia Prima Produto")==false){
      system("clear");
      cout<<"O usuário logado não tem permissão para adicionar uma nova matéria prima ao produto";
      Data data;
      data.dateNow();
      LogAcessoNegado logacessonegado(usermain,data,"Produto","Adicionar Materia Prima Produto");
      empresa->addLogAcessoNegado(logacessonegado);
      a=1;
      break;
      }
      else{
      adicionarMateriaPrimaProd();
      a=1;
      }
    }

    if(numx==4)
    {
      system("clear");
      a=1;
      break;
    }

    else
      cout << "Digite um valor valido!" << endl;
  }
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
  std::this_thread::sleep_for(2s);
  system("clear");
}

void alterarPrecoMateriaPrimaFornecedor(){
  int escolheFornecedor;
  int escolheMateriaPrima;
  double preco;
  cout << "Escolha o fornecedor que deseja alterar o preço da matéria prima:" << endl;
  empresa->getFornecedores();
  Data dataLogLeitura;
  dataLogLeitura.dateNow();

  LogLeitura logleitura(usermain,dataLogLeitura,"Fornecedor","Alterar preço da matéria prima do fornecedor","Vector de fornecedores");
  empresa->addLogLeitura(logleitura);
  
  cin>>escolheFornecedor;
  escolheFornecedor--;
  empresa->getFornecedor(escolheFornecedor).getMateriasPrimasFornecedor();
  cin>>escolheMateriaPrima;
  escolheMateriaPrima--;
  cout << "Digite o preço da unidade da matéria prima:" << endl;
  cin>>preco;
  empresa->getFornecedor(escolheFornecedor).setPrecoMateriaPrimaPosicao(escolheMateriaPrima,preco);

  Data dataLogEscrita;
  string a;
  string b;
  b=std::to_string(preco);
  dataLogEscrita.dateNow();
  LogEscrita logescrita(usermain,dataLogEscrita,"Fornecedor","Alterar Preco Materia Prima Fornecedor","Preco Materia Prima",a,b);
 empresa->addLogEscrita(logescrita);
}

void adicionarMateriaPrimaFornecedor(){
  int escolheFornecedor;
  int escolheMateriaPrima;
  double preco;
  cout << "Escolha o fornecedor que deseja adicionar uma matéria prima:" << endl;
  empresa->getFornecedores();

  Data dataLogLeitura;
  dataLogLeitura.dateNow();
  LogLeitura logleitura(usermain,dataLogLeitura,"Fornecedor","Adicionar materia prima fornecedor","Vector de fornecedores da empresa");
  empresa->addLogLeitura(logleitura);
  
  cin>>escolheFornecedor;
  escolheFornecedor--;
  cout << "Escolha a matéria prima que deseja adicionar ao fornecedor:" << endl;
  empresa->getMateriasPrimas();
  
  LogLeitura logleitura2(usermain,dataLogLeitura,"Fornecedor","Adicionar materia prima fornecedor","Vector de matérias primas da empresa");
  empresa->addLogLeitura(logleitura2);
  
  cin>>escolheMateriaPrima;
  escolheMateriaPrima--;
  cout << "Digite o preço da unidade da matéria prima:" << endl;
  cin>>preco;
  empresa->getFornecedor(escolheFornecedor).setMateriaPrima(empresa->getMateriaPrima(escolheMateriaPrima));
  empresa->getFornecedor(escolheFornecedor).setPrecoMateriaPrima(preco);
}

void cadastrarFornecedor()
{
  string nome;
  cout << "Digite o nome do fornecedor:" << endl;
  cin.ignore();
  getline(cin,nome);
  Fornecedor fornecedor(nome);
  empresa->addFornecedor(fornecedor);
  cout << "Fornecedor cadastrado com sucesso" << endl;
  std::this_thread::sleep_for(2s);
  system("clear");
}


void menuFornecedor()
{
  system("clear");
  int a=0;
  while(a==0)
  {
    cout <<"Fornecedor:"<< endl;
    cout <<"1- Cadastrar fornecedor"<< endl;
    cout <<"2- Adicionar nova matéria prima ao fornecedor"<< endl;
    cout <<"3- Alterar preço da matéria prima do fornecedor"<< endl;
    cout <<"4- Voltar ao menu"<<endl;
    cout <<"Digite uma das opcoes:" << endl;
  
    int numx=0;
    cin >> numx;

    if(numx==1)
    {
      if(usermain.getPermissao("Fornecedor","Cadastrar Fornecedor")==false){
      system("clear");
      cout<<"O usuário logado não tem permissão para cadastrar fornecedor.";
      Data data;
      data.dateNow();
      LogAcessoNegado logacessonegado(usermain,data,"Fornecedor","Cadastrar Fornecedor");
      empresa->addLogAcessoNegado(logacessonegado);
      a=1;
      break;
    }
    else{
      cadastrarFornecedor();
      a=1;
      break;
    }
  } 
  
  if(numx==2)
    {
      if(usermain.getPermissao("Fornecedor","Adicionar materia prima fornecedor")==false){
      system("clear");
      cout<<"O usuário logado não tem permissão para adicionar materia prima fornecedor.";
      Data data;
      data.dateNow();
      LogAcessoNegado logacessonegado(usermain,data,"Fornecedor","Adicionar materia prima fornecedor");
      empresa->addLogAcessoNegado(logacessonegado);
      a=1;
      break;
    }
    else{
      adicionarMateriaPrimaFornecedor();
      a=1;
      break;
    }   
 }

    if(numx==3)
    {
      if(usermain.getPermissao("Fornecedor","Alterar Preco Materia Prima Fornecedor")==false){
      system("clear");
      cout<<"O usuário logado não tem permissão para Alterar Preco Materia Prima Fornecedor.";
      Data data;
      data.dateNow();
      LogAcessoNegado logacessonegado(usermain,data,"Fornecedor","Alterar Preco Materia Prima Fornecedor");
      empresa->addLogAcessoNegado(logacessonegado);
      a=1;
      break;
    }
    else{
      alterarPrecoMateriaPrimaFornecedor();
      a=1;
      break;
    }   
     
  }

    if(numx==4)
    {
      system("clear");
      a=1;
      break;
    }

    else
      cout << "Digite um valor valido!" << endl;
  }
}

void cadastrarCliente()
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
  cout << "Digite o email do cliente:" << endl;
  cin.ignore();
  getline(cin,email);
  cout << "Digite o endereço do cliente:" << endl;
  cin.ignore();
  getline(cin,endereco);

  
  int d=0;
  while(d==0)
  {
    cout << "Digite o dia de nascimento do cliente:" << endl;
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
    cout << "Digite o mês de nascimento do cliente:" << endl;
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
    cout << "Digite o ano de nascimento do cliente:" << endl;
    cin>>ano;

    if(ano<1900)
    {
      cout << "Digite um ano válido" << endl;  
      f=0;
    }

    else
      f=1;
  }

  
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
  
  int z=0;
  while(z==0){
  cout << "Digite o documento do cliente:" << endl;
  cin>>documento;

  if(tipo==true){
  if(validaCPF(documento)==true)
      z=1; 

    else
    {
      cout << "Digite um CPF válido" << endl;  
      z=0;
    }    
  }
    
  if(tipo==false){
  if(validaCNPJ(documento)==true)
      z=1; 

    else
    {
      cout << "Digite um CNPJ válido" << endl;  
      z=0;
    }    
  }
    
    
  }

  data.setDia(dia);
  data.setMes(mes);
  data.setAno(ano);
  Cliente cliente(nome,documento,email,endereco,data,telefone,tipo);
  empresa->addCliente(cliente);
  system("clear");
  cout << "Cliente cadastrado com sucesso!" << endl;
  std::this_thread::sleep_for(2s);
  system("clear");
}

void alterarSalario()
{
  empresa->getFuncionarios();
  
  Data dataLogLeitura;
  dataLogLeitura.dateNow();
  LogLeitura logleitura(usermain,dataLogLeitura,"Funcionario","Alterar salario funcionario","Vector de funcionarios da empresa");
  empresa->addLogLeitura(logleitura);
  
  double salario;
  int funcionario;
  Data data;
  int dia,mes,ano;
  cout <<"Escolha o funcionário"<< endl;
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

  Data dataLogEscrita;
  string a;
  string b;
  b=std::to_string(salario);
  dataLogEscrita.dateNow();
  LogEscrita logescrita(usermain,dataLogEscrita,"Funcionario","Alterar Salario","Vector de salarios",a,b);
 empresa->addLogEscrita(logescrita);

  
  system("clear");
  cout << "Salário alterado com sucesso!" << endl;
  std::this_thread::sleep_for(2s);
  system("clear");
}

void historicoSalarios()
{
Data dataLogLeitura;
dataLogLeitura.dateNow();
int funcionario=0;
system("clear");
empresa->getFuncionarios();
LogLeitura logleitura(usermain,dataLogLeitura,"Funcionario","Historico de salários","Vector funcionarios da empresa");
empresa->addLogLeitura(logleitura);
cout <<"Escolha o funcionário"<< endl;
cin>>funcionario;
funcionario--;
empresa->getFuncionario(funcionario).getSalarios();
LogLeitura logleitura2(usermain,dataLogLeitura,"Funcionario","Historico de salários","Vector de salarios do funcionário");
empresa->addLogLeitura(logleitura2);
}

void aplicarDissidio()
{

}

void demitirFuncionario()
{
  
  empresa->getFuncionarios();

  Data dataLogLeitura;
  dataLogLeitura.dateNow();
  LogLeitura logleitura(usermain,dataLogLeitura,"Funcionario","Demitir funcionario","Vector de funcionarios da empresa");
  empresa->addLogLeitura(logleitura);
  
  int funcionario;
  Data data;
  int dia,mes,ano;

  cout <<"Escolha o funcionário"<< endl;
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

  Data dataLogEscrita;
  dataLogEscrita.dateNow();
  string data2;
  data2=data.getData();
  LogEscrita logescrita(usermain,dataLogEscrita,"Funcionario","Demitir Funcionario","dataDemissao","nulo",data2);
 empresa->addLogEscrita(logescrita); 

  system("clear");
  cout << "Funcionário demitido com sucesso!" << endl;
}

void cadastrarFuncionario()
{
  Data dataLogLeitura;
  dataLogLeitura.dateNow();
  
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
    cin>>documento;

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
  LogLeitura logleitura(usermain,dataLogLeitura,"Funcionario","Cadastrar funcionário","Vector de departamentos da empresa");
empresa->addLogLeitura(logleitura);
  cin>>escolheDepartamento;
  escolheDepartamento--;
  cout << "Escolha um cargo" << endl;
  empresa->getCargos();

  LogLeitura logleitura2(usermain,dataLogLeitura,"Funcionario","Cadastrar funcionario ","Vector de cargos da empresa");
  empresa->addLogLeitura(logleitura2);
  
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
    salario,status,xfuncionario,yfuncionario);
  empresa->addFuncionario(funcionario);
  funcionario.setSalarios(salario,dataAdmissao);
  system("clear");
  cout << "Funcionário cadastrado com sucesso!" << endl;
  std::this_thread::sleep_for(2s);
  system("clear");
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
      if(usermain.getPermissao("Funcionario","Cadastrar Funcionario")==false){
      system("clear");
      cout<<"O usuário logado não tem permissão para cadastrar funcionário";
      Data data;
      data.dateNow();
      LogAcessoNegado logacessonegado(usermain,data,"Funcionario","Cadastrar Funcionario");
      empresa->addLogAcessoNegado(logacessonegado);
      a=1;
      break;
      }    
      else{
      cadastrarFuncionario();
      a=1;
      break;
      }
    }
      
    if(numx==2)
    {
      if(usermain.getPermissao("Funcionario","Demitir Funcionario")==false){
      system("clear");
      cout<<"O usuário logado não tem permissão para demitir funcionário";
      Data data;
      data.dateNow();
      LogAcessoNegado logacessonegado(usermain,data,"Funcionario","Demitir Funcionario");
      empresa->addLogAcessoNegado(logacessonegado);
      a=1;
      break;
      }    
      else{
      demitirFuncionario();
      a=1;
      break;
      }
    }

    if(numx==3)
    {
      if(usermain.getPermissao("Funcionario","Alterar Salario")==false){
        system("clear");
        cout<<"O usuário logado não tem permissão para alterar salario.";
        Data data;
        data.dateNow();
        LogAcessoNegado logacessonegado(usermain,data,"Funcionario","Alterar Salario");
        empresa->addLogAcessoNegado(logacessonegado);
        a=1;
        break;
      }    
      else{
        alterarSalario();
        a=1;
        break;
      }  
    }

    if(numx==4)
    {
      if(usermain.getPermissao("Funcionario","Dissídio Funcionario")==false){
      system("clear");
      cout<<"O usuário logado não tem permissão para aplicar dissídio funcionário";
      Data data;
      data.dateNow();
      LogAcessoNegado logacessonegado(usermain,data,"Funcionario","Dissídio Funcionario");
      empresa->addLogAcessoNegado(logacessonegado);
      a=1;
      break;
      }  
      else{
      aplicarDissidio();
      a=1;
      break;
      }
    }

    if(numx==5)
    {
      if(usermain.getPermissao("Funcionario","Consultar histórico de salário")==false){
      system("clear");
      cout<<"O usuário logado não tem permissão para consultar histórico de salário";
      Data data;
      data.dateNow();
      LogAcessoNegado logacessonegado(usermain,data,"Funcionario","Consultar histórico de salário");
      empresa->addLogAcessoNegado(logacessonegado);
      a=1;
      break;
      }    
      else{
      historicoSalarios();
      a=1;
      break;
      }
    }
    
    if(numx==6)
    {
      if(usermain.getPermissao("Funcionario","Consultar Funcionários")==false){
      system("clear");
      cout<<"O usuário logado não tem permissão para consultar os funcionários";
      Data data;
      data.dateNow();
      LogAcessoNegado logacessonegado(usermain,data,"Funcionario","Consultar Funcionários");
      empresa->addLogAcessoNegado(logacessonegado);
      a=1;
      break;
      }
      else{
      empresa->getFuncionarios();
      a=1;
      break; 
      }

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
  int b=0;

  while(b==0){
  a=0;
  while(a==0){
  
    cout <<"." << endl;
    cout <<"1- Usuário" << endl;
    cout <<"2- Funcionário" << endl;
    cout <<"3- Fornecedor" << endl;
    cout <<"4- Cadastrar cliente"<<endl;
    cout <<"5- Cargo"<<endl;
    cout <<"6- Departamento"<<endl;
    cout <<"7- Categoria" <<endl;
    cout <<"8- Matéria Prima" <<endl;
    cout <<"9- Produto" <<endl;
    cout <<"10- Lote" <<endl;
    cout <<"11- Veículo" <<endl;
    cout <<"12- Rota" <<endl;
    cout <<"13- Orçamento" <<endl;
    cout <<"14- Cadastrar forma de pagamento" <<endl;
    cout <<"15- Venda" <<endl;
    cout <<"16- Logs" <<endl;
    cout <<"17- Logout" <<endl;
    cout <<"Digite uma das opcoes:" << endl;
  
    int numx=0;
    cin >> numx;

    if(numx==1)
    {
      if(usermain.getPermissao("Usuario","Cadastrar Usuario")==false){
      system("clear");
      cout<<"O usuário logado não tem permissão para cadastrar usuarios";
      Data data;
      data.dateNow();
      LogAcessoNegado logacessonegado(usermain,data,"Usuario","Cadastrar Usuario");
      empresa->addLogAcessoNegado(logacessonegado);
      a=1;
      break;
      }    
      else{
      cadastrarUsuario();
      a=1;
      break;
      }
    }
      
    if(numx==2)
    {
      menuFuncionario();
      a=1;
      break;
    }

    if(numx==3)
    {
      menuFornecedor();
      a=1;
      break;
    }

    if(numx==4)
    {
      if(usermain.getPermissao("Cliente","Cadastrar Cliente")==false){
      system("clear");
      cout<<"O usuário logado não tem permissão para cadastrar clientes";
      Data data;
      data.dateNow();
      LogAcessoNegado logacessonegado(usermain,data,"Cliente","Cadastrar Cliente");
      empresa->addLogAcessoNegado(logacessonegado);
      a=1;
      break;
      }
      else{
      cadastrarCliente();
      a=1;
      break; 
      }
    }

    if(numx==5)
    {
      if(usermain.getPermissao("Cargo","Cadastrar Cargo")==false){
      system("clear");
      cout<<"O usuário logado não tem permissão para cadastrar cargos";
      Data data;
      data.dateNow();
      LogAcessoNegado logacessonegado(usermain,data,"Cargo","Cadastrar Cargo");
      empresa->addLogAcessoNegado(logacessonegado);
      a=1;
      break;
      }
      else{
      cadastrarCargo();
      a=1;
      break;
      }
    }
    
    if(numx==6)
    {
       if(usermain.getPermissao("Departamento","Cadastrar Departamento")==false){
      system("clear");
      cout<<"O usuário logado não tem permissão para cadastrar departamentos";
      Data data;
      data.dateNow();
      LogAcessoNegado logacessonegado(usermain,data,"Departamento","Cadastrar Departamento");
      empresa->addLogAcessoNegado(logacessonegado);
      a=1;
      break;
      }
      else{
      cadastrarDepartamento();
      a=1;
      break;
      }
    }
      
    if(numx==7)
    {
      if(usermain.getPermissao("Categoria","Cadastrar Categoria")==false){
      system("clear");
      cout<<"O usuário logado não tem permissão para cadastrar categorias";
      Data data;
      data.dateNow();
      LogAcessoNegado logacessonegado(usermain,data,"Categoria","Cadastrar Categoria");
      empresa->addLogAcessoNegado(logacessonegado);
      a=1;
      break;
      }
      else{
      cadastrarCategoria();
      a=1;
      break;
      }
    }
    
    if(numx==8)
    {
      menuMateriaPrima();
      a=1;
      break;
    }
    
    if(numx==9)
    {
      menuProduto();
      a=1;
      break;
    }

    if(numx==10)
    {
      if(usermain.getPermissao("Lote","Cadastrar Lote")==false){
      system("clear");
      cout<<"O usuário logado não tem permissão para cadastrar lotes";
      Data data;
      data.dateNow();
      LogAcessoNegado logacessonegado(usermain,data,"Lote","Cadastrar Lote");
      empresa->addLogAcessoNegado(logacessonegado);
      a=1;
      break;
      }
      else{
      cadastrarLote();
      a=1;
      break;
      }
    }
    
    if(numx==11)
    {
      if(usermain.getPermissao("Veiculo","Cadastrar Veiculo")==false){
      system("clear");
      cout<<"O usuário logado não tem permissão para cadastrar veiculos";
      Data data;
      data.dateNow();
      LogAcessoNegado logacessonegado(usermain,data,"Veiculo","Cadastrar Veiculo");
      empresa->addLogAcessoNegado(logacessonegado);
      a=1;
      break;
      }
      else{
      cadastrarVeiculo();
      a=1;
      break;
      }
    }
      if(numx==12)
    {
      if(usermain.getPermissao("Rota","Cadastrar Rota")==false){
      system("clear");
      cout<<"O usuário logado não tem permissão para cadastrar rotas";
      Data data;
      data.dateNow();
      LogAcessoNegado logacessonegado(usermain,data,"Rota","Cadastrar Rota");
      empresa->addLogAcessoNegado(logacessonegado);
      a=1;
      break;
      }
      else{
      cadastrarRota();
      a=1;
      break;
      }  
    }

      if(numx==13)
    {
      if(usermain.getPermissao("Orcamento","Cadastrar Orcamento")==false){
      system("clear");
      cout<<"O usuário logado não tem permissão para cadastrar orcamentos";
      Data data;
      data.dateNow();
      LogAcessoNegado logacessonegado(usermain,data,"Orcamento","Cadastrar Orcamento");
      empresa->addLogAcessoNegado(logacessonegado);
      a=1;
      break;
      }
      else{
      cadastraOrcamento();
      a=1;
      break;
      }
    }

     if(numx==14)
    {
      if(usermain.getPermissao("Pagamento","Cadastrar Forma Pagamento")==false){
      system("clear");
      cout<<"O usuário logado não tem permissão para cadastrar formas de pagamento";
      Data data;
      data.dateNow();
      LogAcessoNegado logacessonegado(usermain,data,"Pagamento","Cadastrar Forma Pagamento");
      empresa->addLogAcessoNegado(logacessonegado);
      a=1;
      break;
      }
      else{
      cadastraFormaPagamento();
      a=1;
      break;
      }
    }

    if(numx==15)
    {
      if(usermain.getPermissao("Venda","Realizar Venda")==false){
      system("clear");
      cout<<"O usuário logado não tem permissão para realizar uma venda";
      Data data;
      data.dateNow();
      LogAcessoNegado logacessonegado(usermain,data,"Venda","Realizar Venda");
      empresa->addLogAcessoNegado(logacessonegado);
      a=1;
      break;
      }
      else{
      realizarVenda();
      a=1;
      break;
      }
    }

    if(numx==16)
    {
      if(usermain.getPermissao("Log","Mostrar Logs")==false){
      system("clear");
      cout<<"O usuário logado não tem permissão para consultar os logs do sistema";
      Data data;
      data.dateNow();
      LogAcessoNegado logacessonegado(usermain,data,"Log","Mostrar Logs");
      empresa->addLogAcessoNegado(logacessonegado);
      a=1;
      break;
      }
      else{
      mostrarLogs();
      a=1;
      break;
      }
    }
    if(numx==17){
      a=1;
      b=1;
      break; 
    }
    else
      cout << "Digite um valor valido!" << endl;
  }
    }
}


int main()
{
  //teste singleton
  empresa->addUsuario(usermain);
  empresa->addFormasPagamento(pagamento1);
  empresa->addFormasPagamento(pagamento2);
  usermain.setPermissao("Funcionario","Demitir Funcionario",false);
  usermain.setPermissao("Funcionario","Dissídio Funcionario",true);
  usermain.setPermissao("Funcionario","Consultar histórico de salário",true);
  usermain.setPermissao("Funcionario","Cadastrar Funcionario",true);
  usermain.setPermissao("Funcionario","Alterar Salario",true);
  usermain.setPermissao("Funcionario","Consultar Funcionários",true);
  usermain.setPermissao("Cliente","Cadastrar Cliente",true);
  usermain.setPermissao("Usuario","Cadastrar Usuario",true);
  usermain.setPermissao("Cargo","Cadastrar Cargo",true);
  usermain.setPermissao("Departamento","Cadastrar Departamento",true);
  usermain.setPermissao("Categoria","Cadastrar Categoria",true);
  usermain.setPermissao("Lote","Cadastrar Lote",true);
  usermain.setPermissao("Veiculo","Cadastrar Veiculo",true);
  usermain.setPermissao("Rota","Cadastrar Rota",true);
  usermain.setPermissao("Orcamento","Cadastrar Orcamento",true);
  usermain.setPermissao("Fornecedor","Alterar Preco Materia Prima Fornecedor",true);
  usermain.setPermissao("Fornecedor","Cadastrar Fornecedor",true);
  usermain.setPermissao("Fornecedor","Alterar Preco Materia Prima Fornecedor",true);
  usermain.setPermissao("Pagamento","Cadastrar Forma Pagamento",true);
  usermain.setPermissao("Venda","Realizar Venda",true);
  usermain.setPermissao("Produto","Cadastrar Produto",true);
  usermain.setPermissao("Produto","Adicionar PrecoProduto",true);
  usermain.setPermissao("Produto","Adicionar Materia Prima Produto",true);
  usermain.setPermissao("Materia Prima","Cadastrar Materia Prima", true);
  usermain.setPermissao("Materia Prima","Alterar quantidade de materia prima.", true);
  usermain.setPermissao("Log","Mostrar Logs", true);

 
  system("clear");

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
        //teste singleton usuario logado
        std::cout << "Endereço singleton usuario: " << &usermain << std::endl;
        std::this_thread::sleep_for(2s);
        system("clear");
        case_1();
      }
        
      else
      {
        system("clear");
        cout<<"Usuário e/ou senha não existem!"<<endl;
        std::this_thread::sleep_for(2s);
        system("clear");
      y=1;
      }
    }
  }
  
  return 0;
}


