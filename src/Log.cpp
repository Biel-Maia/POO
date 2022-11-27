#include "Log.h"
#include "../include/Data.h"
#include "../include/Usuario.h"
#include <string>


Log::Log(Usuario usuario, Data data):
  _usuario(usuario),
  _data(data){}

Usuario Log::getUsuario(){
  return this->_usuario;
}

Data Log::getData(){
  return this->_data;
}