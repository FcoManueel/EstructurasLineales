#include "../Cabeceras/Pila.h"

/* Se inicializa la pila con cero elementos (apuntador a NULL) y
 * longitud de 0.
 */
Pila::Pila()
{
  inicio = NULL;
  longitud = 0;
}

/* Recorre la pila de inicio a fin eliminando cada uno de los nodos
 * sencillos. Termina por asignarle a longitud el valor numérico 0.
 */
Pila::~Pila()
{
  NodoSencillo *aux, *anterior;
  aux = inicio;
  while(aux){
    anterior = aux;
    aux = aux->get_siguiente();
    delete anterior;
  }
  longitud = 0;
  inicio = NULL;
}

/* Crea un nodo sencillo con dato igual al valor dado e inserta el nodo
 * al inicio de la pila. Aumenta el valor numérico de la longitud en 1.
 */
void Pila::push(int valor)
{
  NodoSencillo *aux;
  aux = new NodoSencillo(valor, inicio);
  inicio = aux;
  ++longitud;
}

/* En caso de ser una pila no vacía, remueve el nodo sencillo ubicado al
 * inicio de la pila. De lo contrario se manda un error de underflow.
 */
int Pila::pop()
{
  NodoSencillo *aux;
  int valor;
  if(inicio == NULL)
    throw std::underflow_error("underflow en la Pila");
  aux=inicio;
  inicio = inicio->get_siguiente();
  valor = aux->get_valor();
  delete aux;
  --longitud;
  return valor;
}

/* Imprime en consola un diagrama que representa el estado de la pila.
 */
void Pila::pintar()
{
  NodoSencillo *aux;
  aux = inicio;
  std::cout<<"Pila]";
  while(aux){
    std::cout<<"-["<<aux->get_valor()<<"]";
    aux = aux->get_siguiente();
  }
  std::cout<<"-[NULL]\n";
}

/* Regresa un entero no negativo cuyo valor es el numero de elementos
 * en la pila.
 */
int Pila::get_longitud()
{
  return longitud;
}
