#include "../Cabeceras/ListaOrdenadaSinRepeticion.h"

/* Se almacena en memoria dinámica un nodo sencillo que juega el papel
 * de sentinela y se inicializa en cero. Se le asigna al atributo longitud
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
  aux = principio->obtenerConexion();
  while(aux){
    anterior = aux;
    aux = aux->obtenerConexion();
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
  aux = principio->obtenerConexion();
  while(aux){
    if(aux->obtenerValor() <= v)
      break;
    anterior = aux;
    aux = aux->obtenerConexion();
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
  if((anterior->obtenerConexion()) &&
     (anterior->obtenerConexion())->obtenerValor() == v)
    return false;
  aux = new NodoSencillo(v, anterior->obtenerConexion());
  anterior->conectarA(aux);
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
  if(!(anterior->obtenerConexion()))
    return false;
  aux = anterior->obtenerConexion();
  anterior->conectarA(aux->obtenerConexion());
  delete aux;
  --longitud;
  return true;
}

/* Regresa el valor mas grande de todos los nodos sencillos de la lista.
 */
int ListaOrdenadaSinRepeticion::sacarNodo()
{
  NodoSencillo *nodo;
  int valor;
  nodo = principio->obtenerConexion();
  if(!nodo)
    throw std::underflow_error("underflow en lista ordenada sin repeticion");
  principio->conectarA(nodo->obtenerConexion());
  valor = nodo->obtenerValor();
  delete nodo;
  --longitud;
  return valor;
}

/* Regresa un entero cuyo valor es la magnitud o longitud de la lista.
 */
int ListaOrdenadaSinRepeticion::obtenerLongitud()
{
  return longitud;
}

/* Imprime en consola un diagrama que representa el estado de la lista.
 */
void ListaOrdenadaSinRepeticion::pintar()
{
  NodoSencillo *aux;
  aux = principio->obtenerConexion();
  std::cout<<"LOSR]";
  while(aux){
    std::cout<<"-["<<aux->obtenerValor()<<"]";
    aux=aux->obtenerConexion();
  }
  std::cout<<"-[NULL]\n";
}
