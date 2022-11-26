#ifndef MENUFUNCIONARIO_H
#define MENUFUNCIONARIO_H

using namespace std;
#include <string>

class MenuFuncionario
{
  public:
    MenuFuncionario();
    bool validaCPF(string documento);
    void cadastrarFuncionario();
    void alterarSalario();
    void historicoSalarios();
    void aplicarDissidio();
    void demitirFuncionario();


};


#endif