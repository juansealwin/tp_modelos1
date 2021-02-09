#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

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


map<size_t, size_t> ciudad_poblacion = {
  {A, 15000},
  {B, 20000},
  {C, 38000},
  {D, 12000},
  {E, 22000},
  {F, 31000},
  {G, 300000},
  {H, 62000},
  {I, 15000},
  {J, 6000},
  {K, 30000}
};

int obtener_z(map<size_t, size_t> ciudad_tiene_hospital){
	int z = 0;
	for (size_t i = 0 ; i < MAX_CIUDADES ; i++)
	    z = z + ( 60 - 45*ciudad_tiene_hospital[i]) * ciudad_poblacion[i];
	return z;
}

bool config_valida(map<size_t, size_t> ciudad_tiene_hospital) {

	size_t ciudades = 0;
	  for (size_t i = 0 ; i < MAX_CIUDADES ; i++)
	    ciudades += ciudad_tiene_hospital[i];


  return(
    (ciudad_tiene_hospital[A] + ciudad_tiene_hospital[B] + ciudad_tiene_hospital[D] + ciudad_tiene_hospital[F] >= 1) &&
    (ciudad_tiene_hospital[A] + ciudad_tiene_hospital[B] + ciudad_tiene_hospital[C] + ciudad_tiene_hospital[D] >= 1) &&
    (ciudad_tiene_hospital[C] + ciudad_tiene_hospital[B] + ciudad_tiene_hospital[D] + ciudad_tiene_hospital[E] >= 1) &&
    (ciudad_tiene_hospital[D] + ciudad_tiene_hospital[A] + ciudad_tiene_hospital[B] + ciudad_tiene_hospital[C] + ciudad_tiene_hospital[F] + ciudad_tiene_hospital[G] + ciudad_tiene_hospital[E] >= 1) &&
    (ciudad_tiene_hospital[C] + ciudad_tiene_hospital[D] + ciudad_tiene_hospital[G] + ciudad_tiene_hospital[H] + ciudad_tiene_hospital[I] >= 1) &&
    (ciudad_tiene_hospital[F] + ciudad_tiene_hospital[A] + ciudad_tiene_hospital[B] + ciudad_tiene_hospital[C] + ciudad_tiene_hospital[D] >= 1) &&
    (ciudad_tiene_hospital[G] + ciudad_tiene_hospital[F] + ciudad_tiene_hospital[D] + ciudad_tiene_hospital[E] + ciudad_tiene_hospital[H] >= 1) &&
    (ciudad_tiene_hospital[H] + ciudad_tiene_hospital[G] + ciudad_tiene_hospital[E] + ciudad_tiene_hospital[I] + ciudad_tiene_hospital[J] >= 1) &&
    (ciudad_tiene_hospital[E] + ciudad_tiene_hospital[H] + ciudad_tiene_hospital[J] + ciudad_tiene_hospital[I] >= 1) &&
    (ciudad_tiene_hospital[J] + ciudad_tiene_hospital[H] + ciudad_tiene_hospital[I] >= 1) &&
    (ciudad_tiene_hospital[K] + ciudad_tiene_hospital[F] >= 1) &&
	(ciudades <= 4)
  );
}

map<size_t, size_t> obtener_ciudad_tiene_hospital(){
	  map<size_t, size_t> ciudad_tiene_hospital = {
	    {A, 0},
	    {B, 0},
	    {C, 0},
	    {D, 0},
	    {E, 0},
	    {F, 0},
	    {G, 0},
	    {H, 0},
	    {I, 0},
	    {J, 0},
	    {K, 0}
	  };

	  return ciudad_tiene_hospital;
}

void mostrar_ciudades(map<size_t, size_t> ciudad_tiene_hospital){
	   cout<<"Ciudad A:"<< ciudad_tiene_hospital[A] << endl;
	   cout<<"Ciudad B:"<< ciudad_tiene_hospital[B] << endl;
	   cout<<"Ciudad C:"<< ciudad_tiene_hospital[C] << endl;
	   cout<<"Ciudad D:"<< ciudad_tiene_hospital[D] << endl;
	   cout<<"Ciudad E:"<< ciudad_tiene_hospital[E] << endl;
	   cout<<"Ciudad F:"<< ciudad_tiene_hospital[F] << endl;
	   cout<<"Ciudad G:"<< ciudad_tiene_hospital[G] << endl;
	   cout<<"Ciudad H:"<< ciudad_tiene_hospital[H] << endl;
	   cout<<"Ciudad I:"<< ciudad_tiene_hospital[I] << endl;
	   cout<<"Ciudad J:"<< ciudad_tiene_hospital[J] << endl;
	   cout<<"Ciudad K:"<< ciudad_tiene_hospital[K] << endl;
}

int main(int argc, char** argv) {
 //obtengo mapa inicial
  map<size_t, size_t> ciudad_tiene_hospital = obtener_ciudad_tiene_hospital();

  for (size_t i = 0 ; i < MAX_CIUDADES - MAX_HOSPITALES; i++) {

	  //cargo primeros MAX_HOSPITALES - 1
	   size_t j = 0;
	   while ( j < MAX_HOSPITALES - 1) {
		   ciudad_tiene_hospital[i+j] = 1;
		   j++;
	   }

	   //voy probando las distintas configuraciones
	   for (size_t k = i+j ; k < MAX_CIUDADES; k++) {
		   ciudad_tiene_hospital[k] = 1;

		   if(config_valida(ciudad_tiene_hospital)){
			   mostrar_ciudades(ciudad_tiene_hospital);
			   cout<<"Z:"<< obtener_z(ciudad_tiene_hospital) << endl;
		   }
	       else
			   ciudad_tiene_hospital[k] = 0;
	   }

	   //reinicio configuraciones
	   ciudad_tiene_hospital = obtener_ciudad_tiene_hospital();
  }

    return EXIT_SUCCESS;
}



