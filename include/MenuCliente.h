#ifndef MENUCLIENTE_H
#define MENUCLIENTE_H

using namespace std;
#include <string>

class MenuCliente{
    public:
    MenuCliente();
    bool validaCPF(string documento);
    void cadastrarCliente();
};

#endif