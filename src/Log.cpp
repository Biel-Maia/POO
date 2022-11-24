#include "Log.h"
#include "../include/Data.h"
#include <string>


Log::Log(){}

Log::Log(std::string _user, Data* data)
{
  this->user_usuario = _user;
  this->data = data;
}

std::string Log::getUser()
{
  return this->user_usuario;
}

Log::~Log(){}