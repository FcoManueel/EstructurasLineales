#include "../Cabeceras/Cola.h"

/* Se inicializa la cola con cero elementos (apuntador inicio y final a NULL) y
 * longitud de 0.
 */
Cola::Cola()
{
  inicio = NULL;
  final = NULL;
  longitud = 0;
}

/* Recorre la cola de inicio a fin eliminando cada uno de los nodos
 * sencillos. Termina por asignarle a longitud el valor numérico 0.
 */
Cola::~Cola()
{
  NodoSencillo *aux, *anterior;
  aux = inicio;
  while( aux ){
    anterior = aux;
    aux = aux->get_siguiente();
    delete anterior;
  }
  longitud = 0;
  inicio = final = NULL;
}

/* Crea un nodo sencillo con dato igual al valor dado e inserta el nodo
 * al final de la cola. Aumenta el valor numérico de la longitud en 1.
 */
void  Cola::push(int a)

{
  NodoSencillo *aux;
  aux = new NodoSencillo(a, NULL);
  if(!inicio){
    inicio = aux;
    final = aux;
  }else{
    final->set_siguiente(aux);
    final = aux;
  }
  ++longitud;
}

/* En caso de ser una cola no vacía, remueve el nodo sencillo ubicado al
 * inicio. De lo contrario se manda un error de underflow. Regresa el valor
 * del dato del nodo sencillo removido.
 */
int Cola::pop()
{
  NodoSencillo *aux;
  int valor;
  if(!inicio)
    throw std::underflow_error("underflow en la Cola");
  aux = inicio;
  inicio = aux->get_siguiente();
  valor = aux->get_valor();
  delete aux;
  --longitud;
  return valor;
}

/* Imprime en consola un diagrama que representa el estado de la cola.
 */
void Cola::pintar()
{
  NodoSencillo *aux;
  aux = inicio;
  std::cout<<"Cola]";
  while( aux ){
    std::cout<<"-["<<aux->get_valor()<<"]";
    aux = aux->get_siguiente();
  }
  std::cout<<"-[NULL]\n";
}

/* Regresa un entero no negativo cuyo valor es el numero de elementos
 * en la cola.
 */
int Cola::get_longitud()
{
  return longitud;
}
