#include "../include/MateriaPrima.h"
#include "../include/Data.h"
#include "../include/OrdemCompra.h"

#include <string>
#include <vector>


MateriaPrima::MateriaPrima(
  std::string nome,
  std::string unidade_medida,
  int quantidade_estoque,
  int quantidade_estoque_min):
    _nome(nome),
    _unidade_medida(unidade_medida),
    _quantidade_estoque(quantidade_estoque),
    _quantidade_estoque_min(quantidade_estoque_min){}

void MateriaPrima::cadastraFornecedor(int posicaoFornecedor)
{
  _fornecedor.push_back(posicaoFornecedor);
}

void MateriaPrima::cadastraOrcamento(int posicaoOrcamento)
{
  _orcamento.push_back(posicaoOrcamento);
}

void MateriaPrima::verificaEstoque()
{
  int estoque_min = getEstoqueMin();
  int estoque = getEstoque();

  if(estoque < estoque_min)
  {
    Data data;
    OrdemCompra ordem_compra = OrdemCompra(data.dateNow());
    std::string nome = getNome();
    ordem_compra.setMateria(nome);
  } 
}

void MateriaPrima::setEstoque(int estoque)
{
  _quantidade_estoque = estoque;
}

std::string MateriaPrima::getNome()
{
  return this->_nome;
}

int MateriaPrima::getEstoqueMin()
{
  return this->_quantidade_estoque_min;
}

int MateriaPrima::getEstoque()
{
  return this->_quantidade_estoque;
}

void MateriaPrima::setQtdMateriaMin(int qtdMin)
{
  _quantidade_estoque_min = qtdMin;
}