#ifndef CLIENTE_H
#define CLIENTE_H

class Cliente{

  private:
    bool _tipo;

  public:
    Cliente(bool tipo);
    bool getTipo();

};

#endif