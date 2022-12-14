#ifndef ORCAMENTO_H
#define ORCAMENTO_H

#include "../include/Data.h"
#include "../include/Produto.h"
#include "../include/Cliente.h"

#include <vector>
#include <string>


class Orcamento
{
  private:
    Data _data;
    Cliente _cliente;
    std::vector<Produto> _produtos;
    std::vector<int> _quantidades;
    double _valorTotal;

  public:
    Orcamento
    (
      Data data,
      Cliente cliente
    );
    
    void setProduto(Produto produto);
    void setQuantidade(int quantidade);
    Produto getProduto(int posicao);
    int getQuantidade(int posicao);
    int getTam();
    Cliente getCliente();
    double getValorTotal();
};

#endif