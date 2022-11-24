#include "../include/Rota.h"


Rota::Rota(
  Veiculo veiculo,
  std:: string turno,
  Data horario,
  float xempresa,
  float yempresa):
    _veiculo(veiculo),
    _turno(turno),
    _horario(horario),
    _xempresa(xempresa),
    _yempresa(yempresa){}

void Rota::calculaDistancia()
{
  auto::interator it;
  float x, y, distancia;
  for(it = _rota.begin(); it != _rota.end(); it++){
    x = 0; 
    y = 0;
    distancia = 0;
    x = it->getXfuncionario();
    y = it->getYfuncionario();
    distancia = 110.57 * sqrt( pow(x - this->_xempresa,2) + pow(y - this->yempresa, 2) );
    _distancia.push_back(distancia);
  }
}

void Rota::calculaHorarioSaida()
{
  auto::interator it;
  float hora, minuto;
  hora = this->getHora();
  minuto = this->getMin();
  for(it = _tempo.begin(); it != _tempo.end(); it++){
  
  }
}

void Rota::calculaTempoPercurso()
{
  float tempo, velocidade;
  velocidade = this->get_velocidade();
  auto::interator it;
  for(it = _distancia.begin(); it != _distancia.end(); it++){
    tempo = 0;
    tempo = (*it / velocidade) * 60;
    _tempo.push_back(tempo);
  }
}

void Rota::listaSequenciaEmbarqueFuncionarios()
{
  
}
