#ifndef ESTOQUE_H
#define ESTOQUE_H

#include "../include/Lote.h"
#include "../include/Produto.h"

class Estoque{
  private:
    Produto _produto;
    std::vector<Lote> _lotes;
    int _quantidade;
    int _quantidademin;
  public:
    Estoque(Produto produto);
    void setLote(Lote lote);
    Produto getProduto();
    void setQuantidade(int quantidade);
    void setQuantidadeMin(int quantidade);
    void verificaEstoque();
    int getEstoqueMin();
    int getEstoque();
};
#endif