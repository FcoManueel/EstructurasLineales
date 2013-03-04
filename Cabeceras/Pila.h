#ifndef PILA_H_
#define PILA_H_

#include <iostream>
#include <stdexcept>

#include "NodoSencillo.h"

/* La clase pila es una estructura sencilla en donde el primer elemento que
 * entra es el ultimo que sale.
 *
 * AUTOR Eduardo Acuña Yeomans
 * FECHA 03-03-2013
 */
 class Pila {
 	// Apuntador al inicio de la pila
 	NodoSencillo *inicio;
 	// Magnitud o tamaño de la pila
 	int longitud;

 public:
 	Pila();
 	~Pila();

 	void meter(int valor);
 	int sacar();
 	void pintar();
 	int obtenerLongitud();
 };

#endif	//	PILA_H_