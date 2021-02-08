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

bool config_valida(map<size_t, size_t> ciudad_tiene_hospital) {
  return(
    (ciudad_tiene_hospital[A] + ciudad_tiene_hospital[B] + ciudad_tiene_hospital[D] + ciudad_tiene_hospital[F] >= 1) &&
    (ciudad_tiene_hospital[A] + ciudad_tiene_hospital[B] + ciudad_tiene_hospital[C] + ciudad_tiene_hospital[D] >= 1) &&
    (ciudad_tiene_hospital[C] + ciudad_tiene_hospital[B] + ciudad_tiene_hospital[D] + ciudad_tiene_hospital[E] >= 1) &&
    (ciudad_tiene_hospital[D] + ciudad_tiene_hospital[A] + ciudad_tiene_hospital[B] + ciudad_tiene_hospital[C] + ciudad_tiene_hospital[F] + ciudad_tiene_hospital[G] + ciudad_tiene_hospital[E] >= 1) &&
    (ciudad_tiene_hospital[C] + ciudad_tiene_hospital[D] + ciudad_tiene_hospital[G] + ciudad_tiene_hospital[H] + ciudad_tiene_hospital[I] >= 1) &&
    (ciudad_tiene_hospital[F] + ciudad_tiene_hospital[A] + ciudad_tiene_hospital[B] + ciudad_tiene_hospital[C] + ciudad_tiene_hospital[D] >= 1) &&
    (ciudad_tiene_hospital[G] + ciudad_tiene_hospital[F] + ciudad_tiene_hospital[D] + ciudad_tiene_hospital[E] + ciudad_tiene_hospital[H] >= 1) &&
    (ciudad_tiene_hospital[H] + ciudad_tiene_hospital[G] + ciudad_tiene_hospital[E] + ciudad_tiene_hospital[I] + ciudad_tiene_hospital[J] >= 1) &&
    (ciudad_tiene_hospital[I] + ciudad_tiene_hospital[H] + ciudad_tiene_hospital[J] + ciudad_tiene_hospital[I] >= 1) &&
    (ciudad_tiene_hospital[J] + ciudad_tiene_hospital[H] + ciudad_tiene_hospital[I] >= 1) &&
    (ciudad_tiene_hospital[K] + ciudad_tiene_hospital[F] >= 1)
  );
}

int main(int argc, char** argv) {

  // size_t poblacion_ciudad_A = 15000;
  // size_t poblacion_ciudad_B = 20000;
  // size_t poblacion_ciudad_C = 38000;
  // size_t poblacion_ciudad_D = 12000;
  // size_t poblacion_ciudad_E = 22000;
  // size_t poblacion_ciudad_F = 31000;
  // size_t poblacion_ciudad_G = 300000;
  // size_t poblacion_ciudad_H = 62000;
  // size_t poblacion_ciudad_I = 15000;
  // size_t poblacion_ciudad_J = 6000;
  // size_t poblacion_ciudad_K = 30000;
  
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

  for (size_t i = 0 ; i < MAX_CIUDADES ; i++) {
    ciudad_tiene_hospital[i] = 1;
    for (size_t j = i ; j < MAX_CIUDADES ; j++) {
      ciudad_tiene_hospital[j] = 1;
      for (size_t k = j ; k < MAX_CIUDADES ; k++) {
        ciudad_tiene_hospital[k] = 1;
        for (size_t l = k ; l < MAX_CIUDADES ; l++) {
          ciudad_tiene_hospital[l] = 1;
          if(config_valida(ciudad_tiene_hospital))
            break;
          else
            ciudad_tiene_hospital[l] = 0;
        }
        ciudad_tiene_hospital[k] = 0;
      }
      ciudad_tiene_hospital[j] = 0;
    }
    ciudad_tiene_hospital[i] = 0;
  }

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

  return EXIT_SUCCESS;
}


  
