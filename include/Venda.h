#ifndef VENDA_H
#define VENDA_H

#include "../include/Data.h"
#include "../include/Cliente.h"
#include "../include/Pagamento.h"
#include "../include/Orcamento.h"


class Venda
{
  private:
    Data _data;
    Cliente _cliente;
    Orcamento _orcamento;
    double _valorFinal;
    Pagamento _formapagamento;
    int _parcelas;
    double _valorparcelas;
  
  public:
    Venda
    (
      Data data,
      Cliente cliente,
      Orcamento orcamento,
      double valorFinal,
      Pagamento formapagamento,
      int parcelas
    );

    void setCliente(Cliente cliente);
    double getValorParcelas();
    void setValorParcelas(double valorParcelas);
};

#endif