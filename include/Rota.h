#ifndef ROTA_H
#define ROTA_H

#include "../include/Funcionario.h"
#include "../include/Data.h"
#include "../include/Veiculo.h"

#include <vector>
#include <string>

class Rota 
{
  private:
    std::vector<Funcionario> _rota;
    std::vector<float> _distancia;
    std::vector<Data> _tempo;
    std::vector<Data> _embarque;
    Veiculo _veiculo;
    std::string _turno;
    Data _horario;
    float _xempresa;
    float _yempresa;
  
  public:
    Rota
    ( 
      Veiculo veiculo,
      std:: string turno,
      Data horario,
      float xempresa,
      float yempresa
    );

    void calculaDistancia();
    void calculaHorarioSaida();
    void calculaTempoPercurso();
    void listaSequenciaEmbarqueFuncionarios();
};

#endif