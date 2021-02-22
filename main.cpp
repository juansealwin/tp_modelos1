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
#define MAX_HOSPITALES 6
#define MAX_SOLUCIONES_VALIDAS 6

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

  // Contabilizo los hospitales encendidos
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
	  (hospitales_totales == MAX_HOSPITALES)
  );
}

void imprimir_solucion(std::map<size_t, Ciudad> ciudades){
  
  std::map<size_t, Ciudad>::iterator it;
  size_t minutos_totales = obtener_tiempo(ciudades);
  for(it = ciudades.begin() ; it != ciudades.end() ; ++it)
    std::cout<<"Ciudad "<< it->first<< " : "<< it->second.hospitales << " Poblacion: "<< it->second.poblacion <<std::endl;
  
  std::cout<<"Tiempo total de viaje al hospital: "<< std::endl<< 
    minutos_totales << " minutos" << std::endl << 
    minutos_totales/60 << " horas"<<std::endl << std::endl;
}

void reiniciar_hospitales(std::map<size_t, Ciudad>& ciudades){
  std::map<size_t, Ciudad>::iterator it;
  
  for(it = ciudades.begin() ; it != ciudades.end() ; ++it){
    it->second.hospitales = 0;
  }
}

void imprimir_mejora(size_t minutos_primer_solucion, size_t minutos_mejora){
  size_t diferencia_minutos = minutos_primer_solucion - minutos_mejora;
  float porcentaje_de_mejora = (float)diferencia_minutos*100/minutos_primer_solucion;

  std::cout<<"Se mejoró la solución en: "<<diferencia_minutos<<" minutos"<<std::endl;
  std::cout<<"La mejora fue de un: "<<porcentaje_de_mejora<<"%"<<std::endl;

  return;
}  


bool permutar_hospitales(std::map<size_t, Ciudad>& ciudades){
  
  //Si no se completa la permutaciÃ³n es que fue la Ultima
  bool permutacion_completa = false;
  size_t hospitales_a_encender = 1;
  size_t total_ciudades = ciudades.size() - 1;
 
  for(size_t i = total_ciudades ; i >= 0  && !permutacion_completa ; i--){
    
    
    //Hay un hospital(o varios) en el ultimo elemento
    if(i == total_ciudades && ciudades[i].hospitales == 1){
      ciudades[i].hospitales = 0;
      hospitales_a_encender++;
      i--;

      //Desactivamos todos los hospitales que estan a lo Ultimo del conjunto
      while(ciudades[i].hospitales == 1){
        ciudades[i].hospitales = 0;
        hospitales_a_encender++;
        i--;
      }
    }

    //Encontramos un hospital encendido y no es el final del conjunto
    if(i != total_ciudades && ciudades[i].hospitales == 1) {
      ciudades[i].hospitales = 0;
      
      //Enciendo todos los hospitales necesarios para que se complete la permutacion
      while(hospitales_a_encender){
        ciudades[i+hospitales_a_encender].hospitales = 1;
        hospitales_a_encender--;
      }
      permutacion_completa = true;
    }
  }
  return permutacion_completa;
}

void buscar_soluciones_validas(std::map<size_t, Ciudad>& ciudades){
  
  size_t cantidad_de_soluciones = 0;
  
  //Cargo primero MAX_HOSPITALES
  size_t j = 0;
  while (j < MAX_HOSPITALES - 1) {
    ciudades[j].hospitales = 1;
    j++;
  }
 
  while(permutar_hospitales(ciudades) && cantidad_de_soluciones < MAX_SOLUCIONES_VALIDAS){
    if(config_valida(ciudades)){
      imprimir_solucion(ciudades);
      cantidad_de_soluciones++;
    }
  }

  return;
}

void buscar_soluciones_validas_mejoramiento(std::map<size_t, Ciudad>& ciudades){

  size_t cantidad_de_soluciones = 0;
  std::map<size_t, Ciudad> ciudades_mejorada = ciudades;
  size_t minutos_primer_solucion = 0;

  //Cargo primero MAX_HOSPITALES
  size_t j = 0;
  while (j < MAX_HOSPITALES) {
    ciudades[j].hospitales = 1;
    j++;
  }

  //Obtengo tiempo antes de comenzar
  size_t minutos_totales = obtener_tiempo(ciudades);
  
  //mientras pueda permutar y cantidades de mejoramiento a aplicar
  while(permutar_hospitales(ciudades) && cantidad_de_soluciones < MAX_SOLUCIONES_VALIDAS){
	  size_t minutos_totales_actual = obtener_tiempo(ciudades);
    if( config_valida(ciudades) && (minutos_totales > minutos_totales_actual)){
    	minutos_totales = minutos_totales_actual;
    	ciudades_mejorada = ciudades;
    	cantidad_de_soluciones++;

      // Guardamos el tiempo de la primera solucion para saber cuando mejora con la heurística
      if(cantidad_de_soluciones == 1){
        minutos_primer_solucion = minutos_totales_actual;
      }
    }
  }

  imprimir_solucion(ciudades_mejorada);
  
  if(minutos_primer_solucion > minutos_totales)
    imprimir_mejora(minutos_primer_solucion, minutos_totales);

  return;
}


void ordenar_ciudades_por_poblacion(std::map<size_t, Ciudad>& ciudades){
  std::map<size_t, Ciudad>::iterator it;

  for(size_t ranking_ciudad = 0; ranking_ciudad < ciudades.size(); ranking_ciudad++){
    
    size_t indice_ciudad_mas_poblada = ranking_ciudad;

    for(size_t i = indice_ciudad_mas_poblada ; i < ciudades.size() ; i++){
      if (ciudades[i].poblacion > ciudades[indice_ciudad_mas_poblada].poblacion)
        indice_ciudad_mas_poblada = i; 
    }
    ciudades[ranking_ciudad].cambio_ciudades(ciudades[indice_ciudad_mas_poblada]);
  }
}




int main(int argc, char** argv) {

  //Obtengo mapa inicial
  std::map<size_t, Ciudad> ciudades = inicializar_ciudades();

  //Comentar esta funcion si no se quiere buscar los hospitales por ciudades mas pobladas
  //ordenar_ciudades_por_poblacion(ciudades);

  //buscar_soluciones_validas(ciudades);
  buscar_soluciones_validas_mejoramiento(ciudades);
  
  return EXIT_SUCCESS;
}

