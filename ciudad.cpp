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