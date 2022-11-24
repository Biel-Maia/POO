#include "../include/MateriaPrima.h"
#include "../include/Fornecedor.h"


#include <string>
#include <vector>

Fornecedor::Fornecedor(
  std::string nome,
  std::vector<MateriaPrima> materiaprima):
    _nome(nome),
    _materiaPrima(materiaprima)
{}
