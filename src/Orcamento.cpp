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

void Orcamento::setProduto(Produto produto){
  _produtos.push_back(produto);
}
void Orcamento::setQuantidade(int quantidade){
  _quantidades.push_back(quantidade);
}

void Orcamento::setValorTotal(double precoTotal){
  _valorTotal=precoTotal;
}

Cliente Orcamento::getCliente(){
  return this->_cliente;
}

double Orcamento::getValorTotal(){
  return this->_valorTotal;
}