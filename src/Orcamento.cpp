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

Cliente Orcamento::getCliente(){
  return this->_cliente;
}

double Orcamento::getValorTotal(){
  int x;
  x=0;
  int tam=0;
  _valorTotal=0;
  tam=_produtos.size();
  for(x=0;x<tam;x++){
  _valorTotal+=(_produtos[x].getPreco())*(_quantidades[x]);
  }
  return this->_valorTotal;
}