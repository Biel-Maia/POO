#ifndef MATERIAPRIMA_H
#define MATERIAPRIMA_H

#include <string>
#include <vector>

class MateriaPrima
{
  private:
    std::string _nome;
    std::string _unidade_medida;
    int _quantidade_estoque;
    int _quantidade_estoque_min;
    std::vector<int> _fornecedor;
    std::vector<int> _orcamento;

  public:
    MateriaPrima(
      std::string nome,
      std::string unidade_medida,
      int quantidade_estoque,
      int quantidade_estoque_min
    );

    void verificaEstoque();
    void setEstoque(int estoque);
    void setQtdMateriaMin(int qtdMin);
    std::string getNome();
    int getEstoque();
    int getEstoqueMin();
    void cadastraFornecedor(int posicaoFornecedor);
    void cadastraOrcamento(int posicaoOrcamento);
    
};

#endif