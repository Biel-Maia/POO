#ifndef EXCECAOACESSONEGADO_H
#define EXCECAOACESSONEGADO_H

#include <string>
#include <exception>

using namespace std;

class ExcecaoAcessoNegado : public exception{
    public:
        ExcecaoAcessoNegado();
        ~ExcecaoAcessoNegado();
};

#endif