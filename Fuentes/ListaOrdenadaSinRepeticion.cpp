#include "../Cabeceras/ListaOrdenadaSinRepeticion.h"

/* Se almacena en memoria dinámica un nodo sencillo que juega el papel
 * de centinela y se inicializa en cero. Se le asigna al atributo longitud
 * el valor 0.
 */
ListaOrdenadaSinRepeticion::ListaOrdenadaSinRepeticion()
{
  principio = new NodoSencillo(0, NULL);
  longitud = 0;
}

/* Recorre la lista eliminando cada uno de los nodos sencillos y le asigna
 * al atributo de longitud el valor de 0.
 */
ListaOrdenadaSinRepeticion::~ListaOrdenadaSinRepeticion()
{
  NodoSencillo *aux, *anterior;
  aux = principio->get_siguiente();
  while(aux){
    anterior = aux;
    aux = aux->get_siguiente();
    delete anterior;
  }
  longitud = 0;
  delete principio;
}

/* Recorre la lista elemento por elemento hasta encontrar un nodo cuyo
 * valor sea menor o igual al entero v. Regresa un puntero al elemento
 * que se conecta con dicho nodo (el anterior).
 */
NodoSencillo * ListaOrdenadaSinRepeticion::buscar(int v)
{
  NodoSencillo *aux, *anterior;
  anterior = principio;
  aux = principio->get_siguiente();
  while(aux){
    if(aux->get_valor() <= v)
      break;
    anterior = aux;
    aux = aux->get_siguiente();
  }
  return anterior;
}

/* En caso de no haber nodos con valor v, añade un elemento nuevo
 * a la lista, en la posición correspondiente a un orden decreciente.
 * Regresa true si se insertó un nodo y false si fallo la operación.
 */
bool ListaOrdenadaSinRepeticion::insertar(int v)
{
  NodoSencillo *aux, *anterior;
  anterior = buscar(v);
  if((anterior->get_siguiente()) &&
     (anterior->get_siguiente())->get_valor() == v)
    return false;
  aux = new NodoSencillo(v, anterior->get_siguiente());
  anterior->set_siguiente(aux);
  ++longitud;
  return true;
}

/* En caso de tener un elemento con valor v y no ser una lista vacía.
 * Remueve el nodo simple con valor v de la lista. Regresa true si se
 * removió un elemento de la lista y false si falló la operación.
 */
bool ListaOrdenadaSinRepeticion::remover(int v)
{
  NodoSencillo *aux, *anterior;
  anterior = buscar(v);
  if(!(anterior->get_siguiente())) //***
    return false;
  if((anterior->get_siguiente())->get_valor() != v) //***
    return false;
  aux = anterior->get_siguiente();
  anterior->set_siguiente(aux->get_siguiente());
  delete aux;
  --longitud;
  return true;
}

/* Regresa el valor mas grande de todos los nodos sencillos de la lista.
 */
int ListaOrdenadaSinRepeticion::pop()
{
  NodoSencillo *nodo;
  int valor;
  nodo = principio->get_siguiente();
  if(!nodo)
    throw std::underflow_error("underflow en lista ordenada sin repeticion");
  principio->set_siguiente(nodo->get_siguiente());
  valor = nodo->get_valor();
  delete nodo;
  --longitud;
  return valor;
}

/* Regresa un entero cuyo valor es la magnitud o longitud de la lista.
 */
int ListaOrdenadaSinRepeticion::get_longitud()
{
  return longitud;
}

/* Imprime en consola un diagrama que representa el estado de la lista.
 */
void ListaOrdenadaSinRepeticion::pintar()
{
  NodoSencillo *aux;
  aux = principio->get_siguiente();
  std::cout<<"LOSR]";
  while(aux){
    std::cout<<"-["<<aux->get_valor()<<"]";
    aux=aux->get_siguiente();
  }
  std::cout<<"-[NULL]\n";
}
