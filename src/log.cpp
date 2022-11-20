#include "Log.h"

Log::Log(){}

Log::Log(int _user, Data* data){
    this->user_usuario = _user;
    this->data = data;
}

int Log::getUser(){
    return this->user_usuario;
}

Log::~Log(){}