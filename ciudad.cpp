#include "ciudad.h"
#include <iostream>
Ciudad::Ciudad(){
  this->hospitales = 0;
  this->poblacion = 0;
  this->ranking_max_poblada = 0;
  this->adyacentes.clear();
}

Ciudad::Ciudad(size_t nueva_poblacion){
  this->hospitales = 0;
  this->poblacion = nueva_poblacion;
  this->adyacentes.clear();
}

Ciudad::Ciudad(size_t nueva_poblacion, std::vector<size_t> ciudades_adyacentes){
  this->hospitales = 0;
  this->poblacion = nueva_poblacion;
  this->ranking_max_poblada = 0;
  this->adyacentes = ciudades_adyacentes;
}

bool Ciudad::hay_hospital_disponible(std::map<size_t, Ciudad>& ciudades){
  bool hay_hospital = hospitales > 0;

  if(!hay_hospital) {
    // Verificamos si hay al menos un hospital en una ciudad aledaña (del vector de ciudades adyacentes)
    for(auto& numero_ciudad : this->adyacentes){
      if(ciudades[numero_ciudad].hospitales){
        hay_hospital = true;
        break;
      }
    }   
  }
  return hay_hospital;
}

void Ciudad::cambio_ciudades(Ciudad& otra_ciudad){
  Ciudad temp = otra_ciudad;
  otra_ciudad = *this;
  *this = temp;
}

Ciudad& Ciudad::operator=(const Ciudad& other_game) {
  poblacion = other_game.poblacion;
  hospitales = other_game.hospitales;
  ranking_max_poblada = other_game.ranking_max_poblada;
  adyacentes = other_game.adyacentes;
  return *this;
}