#include "Log.h"
#include "../include/Data.h"

Log::Log(){}

Log::Log(std::string _user, Data* data){
    this->user_usuario = _user;
    this->data = data;
}

int Log::getUser(){
    return this->user_usuario;
}

Log::~Log(){}