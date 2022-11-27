#include "../include/Produto.h"
#include "../include/Categoria.h"
#include "../include/Data.h"
#include "../include/MateriaPrima.h"

#include <map>


Produto::Produto(
  std::string nome,
  int codigo,
  double preco,
  Categoria categoria,
  int lote_min,
  int estoque_min): 
    _nome(nome),
    _codigo(codigo),
    _preco(preco),
    _categoria(categoria),
    _lote_min(lote_min),
    _estoque_min(estoque_min){}

int Produto::get_codigo()
{
  return this->_codigo;
}

void Produto::setPreco(double preco)
{
  _preco = preco;
}

std::string Produto::getNome(){
  return this->_nome;
}

void Produto::setMateriaPrima(MateriaPrima materiaprima){
  _materiaprima.push_back(materiaprima);
}

void Produto::setQuantidade(int quantidade){
  _quantidade.push_back(quantidade);
}