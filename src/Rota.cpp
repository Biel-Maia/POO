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


/*
void Rota::mapa(){
  int i=0;
  int tam=_funcionarios.size();
  vector<float> lon;
  map<float, float> lonlat;
  
  for(i=0; i < tam; i++){
    lonlat[_funcionarios[i].getXfuncionario()] = _funcionarios[i].getYfuncionario();
    lon.pushback(_funcionarios[i].getXfuncionario());
  }
  sort(lon.begin(),lon.end()); //ordena as lontitudes
  string maps ="https://www.google.com.br/maps/dir/"; //url base que será inserido os pontos da rota
  
  maps= maps + to_string(this->_xempresa)+",+"+to_string(this->_yempresa)+"/"; // Endereço da Empresa

  for(auto a:lon){
    maps= maps + to_string(a)+",+"+to_string(lonlat[a])+"/"; //concatena um novo ponto da rota na url
  }

  maps= maps + to_string(this->_xempresa)+",+"+to_string(this->_yempresa); // Endereço da Empresa

  cout <<"Copie e cole a seguinte URL no seu navegador de preferência para ver uma sugestão de rota:     "<<endl << maps; 
  
}
*/