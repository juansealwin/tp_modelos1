#include <stdio.h>
#include <iostream>
#include <map>
#include "ciudad.h"

#define A 0
#define B 1
#define C 2
#define D 3
#define E 4
#define F 5
#define G 6
#define H 7
#define I 8
#define J 9
#define K 10
#define MAX_CIUDADES 11
#define MAX_HOSPITALES 4
#define MAX_SOLUCIONES_VALIDAS 1

std::map<size_t, Ciudad> inicializar_ciudades(){ 
    return {
      {A, Ciudad(15000, {B, D, F})},
      {B, Ciudad(20000, {A, C, D})},
      {C, Ciudad(38000, {B, D, E})},
      {D, Ciudad(12000, {A, B, C, F, G, E})},
      {E, Ciudad(22000, {C, D, G, H, I})},
      {F, Ciudad(31000, {A, D, G, K})},
      {G, Ciudad(300000, {F, D, E, H})},
      {H, Ciudad(62000, {G, E, I, J})},
      {I, Ciudad(15000, {E, H, J})},
      {J, Ciudad(6000, {H, I})},
      {K, Ciudad(30000, {F})}
	  };
}

size_t obtener_tiempo(std::map<size_t, Ciudad> ciudades){
	
  size_t tiempo = 0;
  std::map<size_t, Ciudad>::iterator it;

	for (it = ciudades.begin() ; it != ciudades.end() ; ++it)
	    tiempo += ( 60 - 45*ciudades[it->first].hospitales) * ciudades[it->first].poblacion;

	return tiempo;
}

bool config_valida(std::map<size_t, Ciudad> ciudades) {

	size_t hospitales_totales = 0;
  std::map<size_t, Ciudad>::iterator it;

	for (it = ciudades.begin() ; it != ciudades.end() ; ++it)
	  hospitales_totales += ciudades[it->first].hospitales;

  return(
    ciudades[A].hay_hospital_disponible(ciudades) &&
    ciudades[B].hay_hospital_disponible(ciudades) &&
    ciudades[C].hay_hospital_disponible(ciudades) &&
    ciudades[D].hay_hospital_disponible(ciudades) &&
    ciudades[E].hay_hospital_disponible(ciudades) &&
    ciudades[F].hay_hospital_disponible(ciudades) &&
    ciudades[G].hay_hospital_disponible(ciudades) &&
    ciudades[H].hay_hospital_disponible(ciudades) &&
    ciudades[I].hay_hospital_disponible(ciudades) &&
    ciudades[J].hay_hospital_disponible(ciudades) &&
    ciudades[K].hay_hospital_disponible(ciudades) &&
	  (hospitales_totales <= MAX_HOSPITALES)
  );
}

void imprimir_solucion(std::map<size_t, Ciudad> ciudades){
  
  std::map<size_t, Ciudad>::iterator it;
  
  for(it = ciudades.begin() ; it != ciudades.end() ; ++it)
    std::cout<<"Ciudad "<< it->first<< " : "<< it->second.hospitales << std::endl;
  
  std::cout<<"Tiempo total de viaje al hospital: "<< obtener_tiempo(ciudades) << " minutos" << std::endl << std::endl;
}


void buscar_soluciones_por_orden_alfabetico(std::map<size_t, Ciudad>& ciudades, size_t& cantidad_de_soluciones){
  
  for (size_t i = 0 ; i < MAX_CIUDADES - MAX_HOSPITALES ; i++) {
    
    std::map<size_t, Ciudad>::iterator it;
    ciudades = inicializar_ciudades();

	  //Cargo primeros MAX_HOSPITALES - 1
    size_t j = 0;
	  while (j < MAX_HOSPITALES - 1) {
		  ciudades[i+j].hospitales = 1;
      j++;
	  }


	  //Voy chequeando las distintas configuraciones
	  for (size_t k = i+j ; k < MAX_CIUDADES ; k++) {
	    ciudades[k].hospitales = 1;

      if(config_valida(ciudades)){
        cantidad_de_soluciones++;
        imprimir_solucion(ciudades);
        ciudades = inicializar_ciudades();
      }
	    else{
			  ciudades[k].hospitales = 0;
      }
	  }

	  //Chequeo si hayé una solución válida 
    if(cantidad_de_soluciones == MAX_SOLUCIONES_VALIDAS)
      break;
    else if (i == MAX_CIUDADES - MAX_HOSPITALES - 1)
      std::cout<<"No hay mas soluciones disponibles"<<std::endl;
  }

  return;
}

int main(int argc, char** argv) {

  size_t cantidad_de_soluciones = 0;

  //Obtengo mapa inicial
  std::map<size_t, Ciudad> ciudades; 
  
  buscar_soluciones_por_orden_alfabetico(ciudades, cantidad_de_soluciones);
  
  return EXIT_SUCCESS;
}


