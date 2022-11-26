#include "../include/Rota.h"
#include "../include/Data.h"
#include "../include/Funcionario.h"

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
  int tam=_funcionarios.size();
  float x, y, distancia;
  for(z=0; z < tam; z++){
    x = 0; 
    y = 0;
    distancia = 0;
    x = _funcionarios[z].getXfuncionario();
    y = _funcionarios[z].getYfuncionario();
    distancia = 110.57 * sqrt( pow(x - this->_xempresa,2) + pow(y - this->_yempresa, 2) );
    _distancia.push_back(distancia);
  }
}

void Rota::calculaHorarioSaida()
{
  Data aux;
  int x=0;
  int tam=_tempo.size();
  for(x=0;x<tam;x++){
    aux = _horario.operator-(_tempo[x]);
    _embarque.push_back(aux);
  }
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
  int tamRota = _funcionarios.size();
  int tamEmbarque = _embarque.size();
  
  for(x= 0; x < tamRota; x++){
    std::cout << "Funcionario: " << _funcionarios[x].getNome() << std::endl;
    for(y=0; y<tamEmbarque; y++){
      std::cout << "Horário de Embarque: " << _embarque[y].getHora() << " : " << _embarque[y].getMin() << std::endl;
    }
  }
}

void Rota::setFuncionarios(Funcionario funcionario){
  this->_funcionarios.push_back(funcionario);
}
