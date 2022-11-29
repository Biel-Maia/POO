#include <iostream>
#include "../include/Empresa.h"
#include "../include/Usuario.h"
#include "../include/Pessoa.h"
#include "../include/Funcionario.h"
#include "../include/Cliente.h"
#include "../include/Cargo.h"  
#include "../include/Departamento.h"
#include "../include/Categoria.h"
#include "../include/Veiculo.h"
#include "../include/MateriaPrima.h"
#include "../include/Fornecedor.h"
#include "../include/Produto.h"
#include "../include/Lote.h"
#include "../include/Estoque.h"
#include "../include/Orcamento.h"
#include "../include/Venda.h"
#include "../include/OrdemCompra.h"
#include "../include/OrdemProducao.h"

#include <vector>
#include <string>


Empresa *Empresa::ptr = 0; 

Empresa::Empresa()
{
  
}

void Empresa::addUsuario(Usuario usuario)
{
  _usuarios.push_back(usuario);
}

void Empresa::addCategoria(Categoria categoria)
{
  _categorias.push_back(categoria);
}

void Empresa::addCargo(Cargo cargo)
{
  _cargos.push_back(cargo);
}

void Empresa::addDepartamento(Departamento departamento)
{
  _departamentos.push_back(departamento);
}

void Empresa::addCliente(Cliente cliente)
{
  _clientes.push_back(cliente);
}

void Empresa::addFuncionario(Funcionario funcionario)
{
  _funcionarios.push_back(funcionario);
}

void Empresa::addVeiculo(Veiculo veiculo){
  _veiculos.push_back(veiculo);
}

void Empresa::addMateriaPrima(MateriaPrima materiaprima){
  _materias.push_back(materiaprima);
}

void Empresa::addFornecedor(Fornecedor fornecedor){
  _fornecedores.push_back(fornecedor);
}

void Empresa::addRota(Rota rota){
  _rotas.push_back(rota);
}

void Empresa::addProduto(Produto produto){
  _produtos.push_back(produto);
}

void Empresa::addLote(Lote lote){
  _lotes.push_back(lote);
}

void Empresa::addEstoque(Estoque estoque){
  _estoques.push_back(estoque);
}

void Empresa::addOrcamento(Orcamento orcamento){
  _orcamentos.push_back(orcamento);
}

void Empresa::addFormasPagamento(Pagamento pagamento){
  _formaspagamento.push_back(pagamento);
}

void Empresa::addVenda(Venda venda){
  _vendas.push_back(venda);
}

void Empresa::addLogAcessoNegado(LogAcessoNegado logAcessoNegado){
  _logsAcessoNegado.push_back(logAcessoNegado);
}

void Empresa::addLogEscrita(LogEscrita logEscrita){
  _logsEscrita.push_back(logEscrita);
}

void Empresa::addLogLeitura(LogLeitura logLeitura){
  _logsLeitura.push_back(logLeitura);
}

void Empresa::addOrdemCompra(OrdemCompra ordemCompra){
  _ordensCompra.push_back(ordemCompra);
}

void Empresa::addOrdemProducao(OrdemProducao ordemProducao){
  _ordensProducao.push_back(ordemProducao);
}


int Empresa::verificaLogin(std::string user, std::string senha)
{
  int tamanho;
  tamanho=_usuarios.size();
  for(int x=0;x<tamanho;x++)
  {
    std::string userx;
    std::string senhax;
    userx=_usuarios[x].getUser();
    senhax=_usuarios[x].getSenha();
    if(user==userx)
    {
      if(senha==senhax)
        return 1;
    }
  }
  
  return 0;
}

void Empresa::getDepartamentos()
{
  int tamanho = this->_departamentos.size();
  int num=0;
  for(int x=0;x<tamanho;x++)
  {
    num++;
    cout<<num;
    cout<<"- ";
    cout<<_departamentos[x].getNome()<<endl;
  }
}

void Empresa::getCargos()
{
  int tamanho = this->_cargos.size();
  int num=0;
  for(int x=0;x<tamanho;x++)
  {
    num++;
    cout<<num;
    cout<<"- ";
    cout<<_cargos[x].getNome()<<endl;
  }
}

void Empresa::getFuncionarios()
{
  int tamanho = this->_funcionarios.size();
  int num=0;
  for(int x=0;x<tamanho;x++)
  {
    num++;
    cout<<num;
    cout<<"- ";
    std::string nome;
    nome=_funcionarios[x].getNome();
    cout<<nome<<endl;
  }
}

void Empresa::getMateriasPrimas()
{
  int tamanho = this->_materias.size();
  int num=0;
  for(int x=0;x<tamanho;x++)
  {
    num++;
    cout<<num;
    cout<<"- ";
    cout<<_materias[x].getNome()<<endl;
  }
}

void Empresa::getFornecedores()
{
  int tamanho = this->_fornecedores.size();
  int num=0;
  for(int x=0;x<tamanho;x++)
  {
    num++;
    cout<<num;
    cout<<"- ";
    cout<<_fornecedores[x].getNome()<<endl;
  }
}

void Empresa::getVeiculos()
{
  int tamanho = this->_veiculos.size();
  int num=0;
  for(int x=0;x<tamanho;x++)
  {
    num++;
    cout<<num;
    cout<<"- ";
    cout<<"Placa::"<<_veiculos[x].getPlaca()<<" Tipo:"<<_veiculos[x].getTipo()<<endl;
  }
}

void Empresa::getProdutos()
{
  int tamanho = this->_produtos.size();
  int num=0;
  for(int x=0;x<tamanho;x++)
  {
    num++;
    cout<<num;
    cout<<"- ";
    cout<<_produtos[x].getNome()<<endl;
  }
}

void Empresa::getCategorias()
{
  int tamanho = this->_categorias.size();
  int num=0;
  for(int x=0;x<tamanho;x++)
  {
    num++;
    cout<<num;
    cout<<"- ";
    cout<<_categorias[x].getNome()<<endl;
  }
}

void Empresa::getLotes()
{
  int tamanho = this->_lotes.size();
  int num=0;
  for(int x=0;x<tamanho;x++)
  {
    num++;
    cout<<num;
    cout<<"- ";
    cout<<_lotes[x].getNumeroLote()<<endl;
  }
}

void Empresa::getClientes()
{
  int tamanho = this->_clientes.size();
  int num=0;
  for(int x=0;x<tamanho;x++)
  {
    num++;
    cout<<num;
    cout<<"- ";
    cout<<_clientes[x].getNome()<<endl;
  }
}

void Empresa::getFormasPagamento()
{
  int tamanho = this->_formaspagamento.size();
  int num=0;
  for(int x=0;x<tamanho;x++)
  {
    num++;
    cout<<num;
    cout<<"- ";
    cout<<_formaspagamento[x].getNomeFormaPagamento()<<endl;
  }
}

Orcamento Empresa::getOrcamento(int posicao){
  return _orcamentos[posicao];
}

void Empresa::getOrcamentos(Cliente cliente){
  int x;
  x=0;
  int tamanho =0;
  tamanho = this->_orcamentos.size();
  int num;
  num=0;


  for(x=0;x<tamanho;x++){
  
  string nome;
  nome=cliente.getNome();
  string nome2;
  nome2=_orcamentos[x].getCliente().getNome();
  if(nome==nome2){
  num++;
  cout<<num<<" - Orçamento"<<num<<" Valor: R$ "<<_orcamentos[x].getValorTotal()<<endl;
  }
  }
  }

void Empresa::getLogsAcessoNegado()
{
  int tamanho = this->_logsAcessoNegado.size();
  for(int x=0;x<tamanho;x++)
  {
    cout<<"Usuário: "<<_logsAcessoNegado[x].getUsuario().getUser();
    cout<<" Data do acesso: "<<_logsAcessoNegado[x].getData().getDia()<<"/";
    cout<<_logsAcessoNegado[x].getData().getMes()<<"/";
    cout<<_logsAcessoNegado[x].getData().getAno();
    cout<<" Classe acessada: "<<_logsAcessoNegado[x].getClasse();
    cout<<" Metodo acessado: "<<_logsAcessoNegado[x].getMetodo()<<endl;
  }
}

void Empresa::getLogsEscrita()
{
  int tamanho = this->_logsEscrita.size();
  for(int x=0;x<tamanho;x++)
  {
    cout<<"Usuário: "<<_logsEscrita[x].getUsuario().getUser();
    cout<<" Data do acesso: "<<_logsEscrita[x].getData().getDia()<<"/";
    cout<<_logsEscrita[x].getData().getMes()<<"/";
    cout<<_logsEscrita[x].getData().getAno();
    cout<<" Classe acessada: "<<_logsEscrita[x].getClasse();
    cout<<" Metodo acessado: "<<_logsEscrita[x].getMetodo();
    cout<<" Atributo alterado: "<<_logsEscrita[x].getNomeAtributoAlterado();
    cout<<" Valor antes: "<<_logsEscrita[x].getValorAtributoAlteradoAntes();
    cout<<" Valor depois: "<<_logsEscrita[x].getValorAtributoAlteradoDepois()<<endl;
  }
}

void Empresa::getLogsLeitura()
{
  int tamanho = this->_logsLeitura.size();
  for(int x=0;x<tamanho;x++)
  {
    cout<<"Usuário: "<<_logsLeitura[x].getUsuario().getUser();
    cout<<" Data do acesso: "<<_logsLeitura[x].getData().getDia()<<"/";
    cout<<_logsLeitura[x].getData().getMes()<<"/";
    cout<<_logsLeitura[x].getData().getAno();
    cout<<" Classe acessada: "<<_logsLeitura[x].getClasse();
    cout<<" Metodo acessado: "<<_logsLeitura[x].getMetodo();
    cout<<" Atributo acessado: "<<_logsLeitura[x].getAtributoAcessado()<<endl;
  }
}

Estoque Empresa::getEstoqueProd(std::string nome){
  int x=0;
  int z=0;
  int tam = this->_estoques.size();
  std::string nome1;
  for(x=0;x<tam;x++){
    nome1=_estoques[x].getProduto().getNome();
   if(nome1==nome){
   z=x; 
   } 
  }
  return _estoques[z];
}

Departamento Empresa::getDepartamento(int posicao)
{
  return this->_departamentos[posicao];
}

Cargo Empresa::getCargo(int posicao)
{
  return this->_cargos[posicao];
}

Veiculo Empresa::getVeiculo(int posicao)
{
  return this->_veiculos[posicao];
}

MateriaPrima Empresa::getMateriaPrima(int posicao)
{
  return this->_materias[posicao];
}

Fornecedor Empresa::getFornecedor(int posicao)
{
  return this->_fornecedores[posicao];
}

Funcionario Empresa::getFuncionario(int posicao)
{
  return this->_funcionarios[posicao];
}

Produto Empresa::getProduto(int posicao)
{
  return this->_produtos[posicao];
}

Categoria Empresa::getCategoria(int posicao)
{
  return this->_categorias[posicao];
}

Lote Empresa::getLote(int posicao){
  return this->_lotes[posicao];
}

Estoque Empresa::getEstoque(int posicao){
  return this->_estoques[posicao];
}

Cliente Empresa::getCliente(int posicao){
  return this->_clientes[posicao];
}

Pagamento Empresa::getFormaPagamento(int posicao){
  return this->_formaspagamento[posicao];
}

Orcamento Empresa::getOrcamento(Cliente cliente,int posicao){
  int x=0;
  x=0;
  int tamanho=0;
  tamanho = this->_orcamentos.size();
  int num;
  num=0;
  for(x=0;x<tamanho;x++){
    
  string nome;
  nome = cliente.getNome();
  string nome2;
  nome2=_orcamentos[x].getCliente().getNome();
  if(nome==nome2){
  num++;
  if(num==posicao){
  cout<<_orcamentos[x].getValorTotal()<<endl;
  return _orcamentos[x];
  }
  }
  }
  

}
  
void Empresa::alterarSalario(int funcionario, double salario, Data data)
{
  this->_funcionarios[funcionario].setSalario(salario);
  this->_funcionarios[funcionario].setSalarios(salario,data);
}

bool Empresa::getTamDepartamentos()
{
  int x=0;
  x=this->_departamentos.size();
  if(x==0)
    return false;  
  
  else
    return true;  
}

bool Empresa::getTamCargos()
{
  int x=0;
   x=this->_cargos.size();
  if(x==0)
    return false;  
  
  else
    return true;  
}

void Empresa::demiteFuncionario(int funcionario,Data data)
{
  this->_funcionarios[funcionario].demiteFuncionario(data);
}

int Empresa::getTamEstoque(){
  return _estoques.size();
}