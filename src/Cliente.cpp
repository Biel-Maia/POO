#include "../include/Cliente.h"


  Cliente::Cliente(bool tipo):
  _tipo(tipo){}
    
  bool Cliente::getTipo(){
  return this->_tipo;  
  }