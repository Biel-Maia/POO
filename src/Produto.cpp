#include "../include/Produto.h"
#include "../include/Categoria.h"
#include "../include/Data.h"

Produto::Produto(std::string nome,
    int codigo,
    double preco,
    Categoria categoria,
    int lote_min,
    int estoque_min,
    std::map<double, Data> precos,
    std::map<int, MateriaPrima> materiaprima
    ) : _nome(nome),
        _codigo(codigo),
        _preco(preco),
        _categoria(categoria),
        _lote_min(lote_min),
        _estoque_min(estoque_min),
        _precos(precos),
        _materiaprima(materiaprima) {}

void Produto::setPreco(double preco)
{
  _preco = preco;
}

