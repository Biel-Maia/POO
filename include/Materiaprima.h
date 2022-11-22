#ifndef MATERIA_H
#define MATERIA_H

#include "../include/Fornecedor.h"
#include "../include/Orcamento.h"
#include "../include/OrdemCompra.h"

#include <string>
#include <vector>

class Materiaprima{
  private:
    std::string _nome;
    int _unidade_medida;
    int _quantidade_estoque;
    int _quantidade_estoque_min;
    std::vector<Fornecedor> _fornecedor;
    std::vector<Orcamento> _orcamento;

  public:
    Materia
    (
      std::string nome,
      int unidade_medida,
      int quantidade_estoque,
      int quantidade_estoque_min,
      std::vector<Fornecedor> fornecedor,
      std::vector<Orcamento> orcamento
    );
    int verificaQuantidade();
    void atualizaQuantidade();
    void cadastraFornecedor();
    OrdemCompra geraordemCompra();
    Orcamento comparaOrcamento();
};

#endif