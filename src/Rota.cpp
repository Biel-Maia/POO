#include "../include/Rota.h"
#include "../include/Data.h"
#include <cmath>
#include <iostream>



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
  int z=0;
  int tam=_rota.size();
  float x, y, distancia;
  for(z=0; z < tam; z++){
    x = 0; 
    y = 0;
    distancia = 0;
    x = _rota[z].getXfuncionario();
    y = _rota[z].getYfuncionario();
    distancia = 110.57 * sqrt( pow(x - this->_xempresa,2) + pow(y - this->_yempresa, 2) );
    _distancia.push_back(distancia);
  }
}

void Rota::calculaHorarioSaida()
{
  /*Data aux;
  auto iterator it;
  for(it = _tempo.begin(); it != _tempo.end(); it++){
    aux = _horario.operator-(it);
    _embarque.push_back(aux);
  }*/
}

void Rota::calculaTempoPercurso()
{
  int x=0;
  Data data;
  data = this->_horario;
  float tempo, velocidade;
  int hora, min;
  velocidade = 18;
  int tam =_distancia.size();
  
  for(x=0; x < tam; x++){
    tempo = 0;
    tempo = (_distancia[x] / velocidade);
    hora = (int)tempo;
    tempo =(tempo - hora) * 60;
    min = tempo;
    data.setMin(min);
    data.setHora(hora);
    _tempo.push_back(data);
  }
}

void Rota::listaSequenciaEmbarqueFuncionarios()
{
  int x=0;
  int y=0;
  int tamRota = _rota.size();
  int tamEmbarque = _embarque.size();
  
  for(x= 0; x < tamRota; x++){
    std::cout << "Funcionario: " << _rota[x].getNome() << std::endl;
    for(y=0; y<tamEmbarque; y++){
      std::cout << "Horário de Embarque: " << _embarque[y].getHora() << " : " << _embarque[y].getMin() << std::endl;
    }
  }
}
