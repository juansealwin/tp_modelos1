#include <stdio.h>
#include <iostream>
#include <vector>
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

typedef enum {
  ciudad_A, 
  ciudad_B, 
  ciudad_C, 
  ciudad_D, 
  ciudad_E, 
  ciudad_F, 
  ciudad_G, 
  ciudad_H, 
  ciudad_I, 
  ciudad_J, 
  ciudad_K
} ciudad_t;

int main(int argc, char* argv) {

  size_t poblacion_ciudad_A = 15000;
  size_t poblacion_ciudad_B = 20000;
  size_t poblacion_ciudad_C = 38000;
  size_t poblacion_ciudad_D = 12000;
  size_t poblacion_ciudad_E = 22000;
  size_t poblacion_ciudad_F = 31000;
  size_t poblacion_ciudad_G = 300000;
  size_t poblacion_ciudad_H = 62000;
  size_t poblacion_ciudad_I = 15000;
  size_t poblacion_ciudad_J = 6000;
  size_t poblacion_ciudad_K = 30000;
  
  map<ciudad_t, size_t> ciudad_tiene_hospital = {
    {ciudad_A, 0},
    {ciudad_B, 0}, 
    {ciudad_C, 0}, 
    {ciudad_D, 0}, 
    {ciudad_E, 0}, 
    {ciudad_F, 0}, 
    {ciudad_G, 0}, 
    {ciudad_H, 0}, 
    {ciudad_I, 0}, 
    {ciudad_J, 0}, 
    {ciudad_K, 0}
  };


  for (size_t i = 0 ; i < MAX_CIUDADES ; i++) {
    ciudad_tiene_hospital[ciudad_A] = 1;
    ciudad_tiene_hospital[ciudad_B] = 1;
    ciudad_tiene_hospital[ciudad_C] = 1;
    ciudad_tiene_hospital[ciudad_D] = 1;

  }

  

  // size_t tiempo_ciudad_A = 60 - ciudad_A_tiene_hospital * 45;
  // size_t tiempo_ciudad_B = 60 - ciudad_B_tiene_hospital * 45;
  // size_t tiempo_ciudad_C = 60 - ciudad_C_tiene_hospital * 45;
  // size_t tiempo_ciudad_D = 60 - ciudad_D_tiene_hospital * 45;
  // size_t tiempo_ciudad_E = 60 - ciudad_E_tiene_hospital * 45;
  // size_t tiempo_ciudad_F = 60 - ciudad_F_tiene_hospital * 45;
  // size_t tiempo_ciudad_G = 60 - ciudad_G_tiene_hospital * 45;
  // size_t tiempo_ciudad_H = 60 - ciudad_H_tiene_hospital * 45;
  // size_t tiempo_ciudad_I = 60 - ciudad_I_tiene_hospital * 45;
  // size_t tiempo_ciudad_J = 60 - ciudad_J_tiene_hospital * 45;
  // size_t tiempo_ciudad_K = 60 - ciudad_K_tiene_hospital * 45;

  return 0;
}

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

  
