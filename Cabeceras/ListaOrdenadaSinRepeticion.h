#ifndef LISTA_ORDENADA_SINREP_H_
#define LISTA_ORDENADA_SINREP_H_

#include <iostream>
#include <stdexcept>

#include "NodoSencillo.h"

/* La lista ordenada sin repetición (ListaOrdenadaSinRepeticion) es una lista
 * simple enlazada conformada por nodos sencillos con valor único
 * 
 * AUTOR Eduardo Acuña Yeomans
 * FECHA 03-03-2013
 */
class ListaOrdenadaSinRepeticion {
	// Apuntador al inicio de la lista (sentinela)
 	NodoSencillo * principio;
 	// Magnitud o tamaño de la lista
 	int longitud;

 public:
 	ListaOrdenadaSinRepeticion();
 	~ListaOrdenadaSinRepeticion();

 	NodoSencillo * buscar(int v);
 	bool insertar(int v);
 	bool remover(int v);
 	int sacarNodo();
 	int obtenerLongitud();
	void pintar();
};

#endif	//	LISTA_ORDENADA_SINREP_H_
