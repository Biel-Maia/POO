#ifndef ROTA_H
#define ROTA_H

#include "../include/Funcionario.h"
#include "../include/Data.h"

#include <vector>
#include <string>

class Rota {
  private:
    std::vector<Funcionario> _rota;
    int _distancia;
    std::string _turno;
    Data _horario;
    float _xempresa;
    float _yempresa;
  public:
    Rota(
      int distancia,
      std:: string turno,
      Data horario,
      float xempresa,
      float yempresa
    );
    calculaDistancia(float xfuncionario, float yfuncionario);
    calculaHorarioSaida();
    calculaTempoPercurso();
    alteraHorario();
    listaSequenciaEmbarqueFuncionarios();
};

#endif