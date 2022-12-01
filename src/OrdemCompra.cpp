#include "../include/OrdemCompra.h"
#include "../include/Data.h"
#include "../include/Orcamento.h"


OrdemCompra::OrdemCompra(
  Data data):
    _data(data){}

void OrdemCompra::setMateria(std::string nome_materiaprima)
{
  _nome_materiaprima = nome_materiaprima;
}

