#include "ciudad.h"

Ciudad::Ciudad(){
  this->hospitales = 0;
  this->poblacion = 0;
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
  this->adyacentes = ciudades_adyacentes;
}

bool Ciudad::hay_hospital_disponible(std::map<size_t, Ciudad>& ciudades){
  bool hay_hospital = hospitales > 0;

  if(!hay_hospital) {
    for(auto& numero_ciudad : this->adyacentes)
      if(ciudades[numero_ciudad].hospitales) {
        hay_hospital = true;
        break;
      }   
  }
  return hay_hospital;
}