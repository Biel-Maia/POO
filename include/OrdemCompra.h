#ifndef ORDEMCOMPRA_H
#define ORDEMCOMPRA_H

#include "../include/Data.h"
#include "../include/Orcamento.h"

#include <string>
#include <vector>

class OrdemCompra
{
  private:
    Data _data;
    std::string _nome_materiaprima;
    std::vector<Orcamento> _orcamento;

  public:
    OrdemCompra(Data data);
    
    void setMateria(std::string nome_materiaprima);
};

#endif