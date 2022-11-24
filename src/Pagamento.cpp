#include "../include/Pagamento.h"

Pagamento::Pagamento(Cliente* c, Data* d)
{
  this->cliente = c;
  this->data = d;
}