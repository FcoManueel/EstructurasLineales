#include "../Cabeceras/NodoSencillo.h"

/* Se asigna un dato entero dado al atributo valor y una dirección de nodo
 * sencillo al atributo siguiente.
 */
NodoSencillo::NodoSencillo(int v, NodoSencillo *s)
{
  valor = v;
  siguiente = s;
}

/* Le asigna el valor de cero a los atributos del objeto. */
NodoSencillo::~NodoSencillo()
{
  valor = 0;
  siguiente = 0;
}

/* Le asigna al atributo valor un número entero dado por la variable v. */
void NodoSencillo::fijarValor(int v)
{
  valor = v;
}

/* Enlaza el nodo sencillo a otro nodo alojado en la dirección a la que
 * apunta s.
 */
void NodoSencillo::conectarA(NodoSencillo *s)
{
  siguiente = s;
}

/* Regresa un entero dado por el atributo valor. */
int NodoSencillo::obtenerValor()
{
  return valor;
}

/* Regresa un apuntador a nodo sencillo dado por el atributo siguiente. */
NodoSencillo* NodoSencillo::obtenerConexion()
{
  return siguiente;
}
