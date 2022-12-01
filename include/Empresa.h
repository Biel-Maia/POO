#ifndef EMPRESA_H
#define EMPRESA_H

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
#include "../include/Rota.h"
#include "../include/Produto.h"
#include "../include/Lote.h"
#include "../include/Estoque.h"
#include "../include/Orcamento.h"
#include "../include/Pagamento.h"
#include "../include/Venda.h"
#include "../include/LogAcessoNegado.h"
#include "../include/LogLeitura.h"
#include "../include/LogEscrita.h"
#include "../include/OrdemCompra.h"
#include "../include/OrdemProducao.h"


#include <vector>
#include <string>


class Empresa
{
  private:
    Empresa();
    static Empresa *ptr; 
    std::vector<Usuario> _usuarios;
    std::vector<Pessoa> _pessoas;
    std::vector<Funcionario> _funcionarios;
    std::vector<Cliente> _clientes;
    std::vector<Cargo> _cargos;
    std::vector<Veiculo> _veiculos;
    std::vector<Departamento> _departamentos;
    std::vector<Categoria> _categorias;
    std::vector<MateriaPrima> _materias;
    std::vector<Fornecedor>  _fornecedores;
    std::vector<Rota> _rotas;
    std::vector<Produto> _produtos;
    std::vector<Lote> _lotes;
    std::vector<Estoque> _estoques;
    std::vector<Orcamento> _orcamentos;
    std::vector<Pagamento> _formaspagamento;
    std::vector<Venda> _vendas;
    std::vector<LogAcessoNegado> _logsAcessoNegado;
    std::vector<LogEscrita> _logsEscrita;
    std::vector<LogLeitura> _logsLeitura;
    std::vector<OrdemCompra> _ordensCompra; 
    std::vector<OrdemProducao> _ordensProducao;
  
  public:
    static Empresa *Instance(void)
    {
      if(!ptr)
        ptr = new Empresa();

      return ptr;
    } 
    
    void addUsuario(Usuario usuario);
    void addCategoria(Categoria categoria);
    void addCargo(Cargo cargo);
    void addCliente(Cliente cliente);
    void addFuncionario(Funcionario funcionario);
    void addVeiculo(Veiculo veiculo);
    void addDepartamento(Departamento departamento);
    void addMateriaPrima(MateriaPrima materiaprima);
    void addFornecedor(Fornecedor fornecedor);
    void addRota(Rota rota);
    void addProduto(Produto produto);
    void addLote(Lote lote);
    void addEstoque(Estoque estoque);
    void addOrcamento(Orcamento orcamento);
    void addFormasPagamento(Pagamento pagamento);
    void addVenda(Venda venda);
    void addLogAcessoNegado(LogAcessoNegado logAcessoNegado);
    void addLogEscrita(LogEscrita logEscrita);
    void addLogLeitura(LogLeitura logLeitura);
    void addOrdemCompra(OrdemCompra ordemCompra);
    void addOrdemProducao(OrdemProducao ordemProducao);
    int verificaLogin(std::string user, std::string senha);
    void getDepartamentos();
    void getCargos();
    void getFuncionarios();
    int getTamFuncionarios();
    void getMateriasPrimas();
    void getFornecedores();
    void getVeiculos();
    void getProdutos();
    void getCategorias();
    void getLotes();
    void getClientes();
    void getLogsAcessoNegado();
    void getLogsEscrita();
    void getLogsLeitura();
    void getFormasPagamento();
    void getOrcamentos(Cliente cliente);
    Orcamento getOrcamento(int posicao);
    Departamento getDepartamento(int posicao);
    Cargo getCargo(int posicao);
    MateriaPrima getMateriaPrima(int posicao);
    Fornecedor getFornecedor(int posicao);
    Veiculo getVeiculo(int posicao);
    Funcionario getFuncionario(int posicao);
    Produto getProduto(int posicao);
    Categoria getCategoria(int posicao);
    Lote getLote(int posicao);
    Estoque getEstoquex(int pos);
    Estoque getEstoqueProd(std::string nome);
    Cliente getCliente(int posicao);
    Pagamento getFormaPagamento(int posicao);
    Orcamento getOrcamento(Cliente cliente,int posicao);
    void alterarSalario(int funcionario, double salario, Data data);
    bool getTamDepartamentos();
    bool getTamCargos();
    int  getTamEstoque();
    void demiteFuncionario(int funcionario, Data data);
};

#endif
