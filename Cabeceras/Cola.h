#ifndef COLA_H_
#define COLA_H_

#include <iostream>
#include <stdexcept>

#include "NodoSencillo.h"

/* La clase cola es una estructura sencilla en donde el primer elemento que
 * entra es el primero que sale.
 *
 * AUTOR Eduardo Acuña Yeomans
 * FECHA 03-03-2013
 */
class Cola {
  // Apuntador al inicio de la cola
  NodoSencillo *inicio;
  // Apuntador al final de la cola
  NodoSencillo *final;
  // Magnitud o tamaño de la cola
  int longitud;

 public:
  Cola();
  ~Cola();

  void  push(int a);
  int pop();
  void pintar();
  int get_longitud();
};

#endif  //  COLA_H_
