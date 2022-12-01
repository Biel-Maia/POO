#include "../include/Orcamento.h"
#include "../include/Data.h"
#include "../include/Produto.h"
#include "../include/Cliente.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;


Orcamento::Orcamento(
  Data data,
  Cliente cliente):
    _data(data),
    _cliente(cliente){}

void Orcamento::setProduto(Produto produto)
{
  _produtos.push_back(produto);
}

void Orcamento::setQuantidade(int quantidade)
{
  _quantidades.push_back(quantidade);
}

int Orcamento::getTam()
{
  return _produtos.size();
}

Cliente Orcamento::getCliente()
{
  return this->_cliente;
}

double Orcamento::getValorTotal()
{
  int x = 0;
  int tam = 0;
  this->_valorTotal = 0;
  tam = _produtos.size();
  
  for(x = 0; x < tam; x++)
    this->_valorTotal += (_produtos[x].getPreco()) * (_quantidades[x]);
  
  return this->_valorTotal;
}

Produto Orcamento::getProduto(int posicao)
{
  return _produtos[posicao];
}

int Orcamento::getQuantidade(int posicao)
{
  return _quantidades[posicao];
}