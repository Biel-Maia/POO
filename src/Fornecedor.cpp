#include "../include/Fornecedor.h"
#include "../include/MateriaPrima.h"

#include <iostream>
#include <string>
#include <vector>


Fornecedor::Fornecedor(
  std::string nome):
    _nome(nome){}

void Fornecedor::setMateriaPrima(MateriaPrima materiaprima)
{
  this->_materiaprima.push_back(materiaprima);
}

void Fornecedor::setPrecoMateriaPrima(double preco)
{
  this->_precomateriaprima.push_back(preco);
}

void Fornecedor::setPrecoMateriaPrimaPosicao(int posicao, double preco)
{
  this->_precomateriaprima[posicao] = preco;
}

void Fornecedor::getMateriasPrimasFornecedor()
{
  int tamanho = this->_materiaprima.size();
  int num = 0;
  
  for(int x = 0; x < tamanho; x++)
  {
    num++;
    std::cout << num;
    std::cout << "- ";
    std::cout << _materiaprima[x].getNome() << std::endl;
  }
}

std::string Fornecedor::getNome()
{
  return this->_nome;
}
