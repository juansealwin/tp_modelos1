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
      {A, Ciudad(15000)},
      {B, Ciudad(20000)},
      {C, Ciudad(38000)},
      {D, Ciudad(12000)},
      {E, Ciudad(22000)},
      {F, Ciudad(31000)},
      {G, Ciudad(300000)},
      {H, Ciudad(62000)},
      {I, Ciudad(15000)},
      {J, Ciudad(6000)},
      {K, Ciudad(30000)}
	  };
}

int obtener_tiempo(std::map<size_t, Ciudad> ciudades){
	int tiempo = 0;
	for (size_t i = 0 ; i < MAX_CIUDADES ; i++)
	    tiempo += ( 60 - 45*ciudades[i].hospitales) * ciudades[i].poblacion;
	return tiempo;
}

bool config_valida(std::map<size_t, Ciudad> ciudades) {

	size_t hospitales_totales = 0;
	for (size_t i = 0 ; i < MAX_CIUDADES ; i++)
	  hospitales_totales += ciudades[i].hospitales;


  return(
    (ciudades[A].hospitales + ciudades[B].hospitales + ciudades[D].hospitales + ciudades[F].hospitales >= 1) &&
    (ciudades[A].hospitales + ciudades[B].hospitales + ciudades[C].hospitales + ciudades[D].hospitales >= 1) &&
    (ciudades[C].hospitales + ciudades[B].hospitales + ciudades[D].hospitales + ciudades[E].hospitales >= 1) &&
    (ciudades[D].hospitales + ciudades[A].hospitales + ciudades[B].hospitales + ciudades[C].hospitales + ciudades[F].hospitales + ciudades[G].hospitales + ciudades[E].hospitales >= 1) &&
    (ciudades[C].hospitales + ciudades[D].hospitales + ciudades[G].hospitales + ciudades[H].hospitales + ciudades[I].hospitales >= 1) &&
    (ciudades[F].hospitales + ciudades[A].hospitales + ciudades[B].hospitales + ciudades[C].hospitales + ciudades[D].hospitales >= 1) &&
    (ciudades[G].hospitales + ciudades[F].hospitales + ciudades[D].hospitales + ciudades[E].hospitales + ciudades[H].hospitales >= 1) &&
    (ciudades[H].hospitales + ciudades[G].hospitales + ciudades[E].hospitales + ciudades[I].hospitales + ciudades[J].hospitales >= 1) &&
    (ciudades[E].hospitales + ciudades[H].hospitales + ciudades[J].hospitales + ciudades[I].hospitales >= 1) &&
    (ciudades[J].hospitales + ciudades[H].hospitales + ciudades[I].hospitales >= 1) &&
    (ciudades[K].hospitales + ciudades[F].hospitales >= 1) &&
	  (hospitales_totales <= MAX_HOSPITALES)
  );
}


void imprimir_resultados(std::map<size_t, Ciudad> ciudades){
  std::cout<<"Ciudad A:"<< ciudades[A].hospitales << std::endl;
  std::cout<<"Ciudad B:"<< ciudades[B].hospitales << std::endl;
  std::cout<<"Ciudad C:"<< ciudades[C].hospitales << std::endl;
  std::cout<<"Ciudad D:"<< ciudades[D].hospitales << std::endl;
  std::cout<<"Ciudad E:"<< ciudades[E].hospitales << std::endl;
  std::cout<<"Ciudad F:"<< ciudades[F].hospitales << std::endl;
  std::cout<<"Ciudad G:"<< ciudades[G].hospitales << std::endl;
  std::cout<<"Ciudad H:"<< ciudades[H].hospitales << std::endl;
  std::cout<<"Ciudad I:"<< ciudades[I].hospitales << std::endl;
  std::cout<<"Ciudad J:"<< ciudades[J].hospitales << std::endl;
  std::cout<<"Ciudad K:"<< ciudades[K].hospitales << std::endl;
  std::cout<<"Tiempo total de viaje al hospital: "<< obtener_tiempo(ciudades) << " minutos" << std::endl << std::endl;
}

int main(int argc, char** argv) {

  size_t cantidad_de_soluciones = 0;

  //Obtengo mapa inicial
  std::map<size_t, Ciudad> ciudades; 

  for (size_t i = 0 ; i < MAX_CIUDADES - MAX_HOSPITALES ; i++) {

    ciudades = inicializar_ciudades();

	  //cargo primeros MAX_HOSPITALES - 1
	   size_t j = 0;
	   while ( j < MAX_HOSPITALES - 1) {
		   ciudades[i+j].hospitales = 1;
		   j++;
	   }

	  //Voy probando las distintas configuraciones
	  for (size_t k = i+j ; k < MAX_CIUDADES ; k++) {
	    ciudades[k].hospitales = 1;

      if(config_valida(ciudades)){
        cantidad_de_soluciones++;
        imprimir_resultados(ciudades);
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
  
  //imprimir_resultados(ciudades);
  
  return EXIT_SUCCESS;
}



