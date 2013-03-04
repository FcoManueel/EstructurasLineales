/* Este es el codigo del programa utilizado para probar las estructuras 
 * implementadas en la clase de Estructuras de Datos.
 * 
 * los comentarios en el codigo funcionan como tutorial para expandir el
 * programa a otras estructuras.
 *
 * AUTOR Eduardo Acuña Yeomans
 * FECHA 03-03-2013
 */

// Agrega las librerías estándar que se usarán en este codigo.
#include <iostream>
#include <string>

// Agrega las cabeceras de las estructuras de datos que implementaste.
#include "../Cabeceras/Pila.h"
#include "../Cabeceras/Cola.h"
#include "../Cabeceras/ListaOrdenadaSinRepeticion.h"

 // Añade un termino en el enum para hacer referencia a las estructuras
 // agregadas. Elige un nombre no repetible (representativo).
enum {pila, cola, lista_ordenada_sr};

// Agrega las funciones que se utilizarán en este codigo (no relacionadas
// a las estructuras)
void mostrarMenu();

// Agrega una función para cada estructura, éstas se encargan de proveer el
// loop principal para realizar operaciones sobre las estructuras.
void sub_Pila();
void sub_Cola();
void sub_ListaOrdenadaSinRepeticion();

// Para agregar una estructura al programa se siguen los siguientes pasos:
// 
// *   = Modifica la cadena que se imprime en pantalla para que muestre
//       el rango correcto.
// **  = Modifica las condiciones del while para aceptar valores dentro
//       del rango correcto.
// *** = Añade un caso por estructura que referencíe al termino en el enum
//       correspondiente. Deberá llamar a la funcion que gestiona la estructura
// Cuando se dice rango correcto, hago referencia a las opciones mostradas en
// mostrarMenu().
int main()
{
  int programa;
  mostrarMenu();
  do{
    std::cout<<"INGRESA UN NUMERO DEL [0 - 2] "; // *
    std::cin>>programa;
  }while( programa<0 || programa>2 ); // **
  
  switch(programa){ // ***
  case pila:
    sub_Pila();
    break;
  case cola:
    sub_Cola();
    break; 
  case lista_ordenada_sr:
    sub_ListaOrdenadaSinRepeticion();
    break;
  }
  return 0;
}
// El formato de las funciones que gestionan las estructuras es algo genérico.
// Se requiere tener un entero llamado 'op' para conocer que operacion desea
// realizarse sobre la estructura.
//
// Se recomiendoa dejar un espacio en blanco con el comando:
// std::string blank (10, '\n');
// std::cout<<blank;
//
// Después se imprime en pantalla el siguiente formato.
// std::cout<<"PROG (NOMBRE DE LA ESTRUCTURA)\n\n";
// std::cout<<"Descripcion del estado inicial de la estructura. Puedes realizar diversas operaciones sobre ella\n";
// std::cout<<"+ OPERACIONES\n";
// std::cout<<"|- [0] OPERACION\n";
// std::cout<<"|- [1] OPERACION\n";
// std::cout<<"|- [2] OPERACION\n";
//                      ···
// std::cout<<"|- [n] OPERACION\n";
// std::cout<<"+ [-1] SALIR\n\n";
//
// Crea nueva estructura
// 
// Inicia un ciclo do con condicion de parado (op!=-1) que es la opcion salir
// Dentro de este ciclo do, se pinta el estado inicial de la estructura y se
// captura de consola la operación a realizar.
// Añade un switch con un caso por operación.
// En las operaciones en donde es propenso que ocurra un error, usa un bloque
// try-catch.
void sub_Pila()
{
  int op, resp;
  std::string blank (10, '\n');
  std::cout<<blank;
  std::cout<<"PROG (PILA)\n\n";
  std::cout<<"tienes una pila vacía. Puedes realizar diversas operaciones sobre ella\n";
  std::cout<<"+ OPERACIONES\n";
  std::cout<<"|- [0] METER\n";
  std::cout<<"|- [1] SACAR\n";
  std::cout<<"|- [2] CUANTOS?\n";
  std::cout<<"|- [9] LIMPIAR \n";
  std::cout<<"+ [-1] SALIR\n\n";
  Pila* mi_pila = new Pila();
  do{
    mi_pila->pintar();
    do{
      std::cout<<"\nOPER ";
      std::cin>>op;
    }while( op<-1 || (op>2 && op<9) || op>9);
    switch(op){
    case 0:
      std::cout<<"DATO ";
      std::cin>>resp;
      mi_pila->meter(resp);
      break;
    case 1:
      try{
        resp = mi_pila->sacar();
        std::cout<<"SALE {"<<resp<<"}\n";
      }catch( std::underflow_error& e ){
        std::cerr << "Error: " << e.what( ) << "\n";
      }
      break;
    case 2:
      std::cout<<"CANT "<<mi_pila->obtenerLongitud()<<"\n";
      break;
    case 9:
      delete mi_pila;
      mi_pila = new Pila();
      break;
    case -1:
      std::cout<<"\nPROGRAMA TERMINADO\n\n";
    }
  }while(op!=-1);  
}
void sub_Cola()
{
  int op, resp;
  std::string blank (10, '\n');
  std::cout<<blank;
  std::cout<<"PROG (COLA)\n\n";
  std::cout<<"tienes una cola vacía. Puedes realizar diversas operaciones sobre ella\n";
  std::cout<<"+ OPERACIONES\n";
  std::cout<<"|- [0] METER\n";
  std::cout<<"|- [1] SACAR\n";
  std::cout<<"|- [2] CUANTOS?\n";
  std::cout<<"|- [9] LIMPIAR \n";
  std::cout<<"+ [-1] SALIR\n\n";
  Cola* mi_cola = new Cola();
  do{
    mi_cola->pintar();
    do{
      std::cout<<"\nOP ";
      std::cin>>op;
    }while( op<-1 || (op>2 && op<9) || op>9);
    switch(op){
    case 0:
      std::cout<<"KEY ";
      std::cin>>resp;
      mi_cola->meter(resp);
      std::cin.get();
      break;
    case 1:
      try{
        resp = mi_cola->sacar();
        std::cout<<"SALE {"<<resp<<"}\n";
      }catch( std::underflow_error& e ){
        std::cerr << "Error: " << e.what( ) << "\n";
      }
      break;
    case 2:
      std::cout<<"CANT "<<mi_cola->obtenerLongitud()<<"\n";
      break;
    case 9:
      delete mi_cola;
      mi_cola = new Cola();
      break;
    case -1:
      std::cout<<"\nPROGRAMA TERMINADO\n\n";
    }
  }while(op!=-1);
}

void sub_ListaOrdenadaSinRepeticion()
{
  int op, resp;
  std::string blank (10, '\n');
  std::cout<<blank;
  std::cout<<"PROG (LISTA ORDENADA SIN REPETICION)\n\n";
  std::cout<<"tienes una lista vacía. Puedes realizar diversas operaciones sobre ella\n";
  std::cout<<"+ OPERACIONES\n";
  std::cout<<"|- [0] INSERTAR\n";
  std::cout<<"|- [1] REMOVER\n";
  std::cout<<"|- [2] SACAR\n";
  std::cout<<"|- [3] CUANTOS?\n";
  std::cout<<"|- [9] LIMPIAR\n";
  std::cout<<"+ [-1] SALIR\n\n";
  ListaOrdenadaSinRepeticion* mi_lista = new ListaOrdenadaSinRepeticion();
  do{
    mi_lista->pintar();
    do{
      std::cout<<"\nOPER ";
      std::cin>>op;
    }while( op<-1 || (op>3 && op<9) || op>9);
    switch(op){
    case 0:
      std::cout<<"DATO ";
      std::cin>>resp;
      mi_lista->insertar(resp);
      break;
    case 1:
      std::cout<<"DATO ";
      std::cin>>resp;
      mi_lista->remover(resp);
      break;
    case 2:
      try{
      	resp = mi_lista->sacarNodo();
      	std::cout<<"NODO {"<<resp<<"}\n";
      }catch(std::underflow_error& e){
      	std::cerr << "Error: " << e.what( ) << "\n";
      }
      break;
    case 3:
      std::cout<<"CANT "<<mi_lista->obtenerLongitud()<<"\n";
      break;
    case 9:
      delete mi_lista;
      mi_lista = new ListaOrdenadaSinRepeticion();
      break;
    case -1:
      std::cout<<"\nPROGRAMA TERMINADO\n\n";
    }
  }while(op!=-1);
}

// Este menu se mostrará al inicio del programa. Modificalo para que muestre
// las estructuras agregadas. Tiene que mantenerse el mismo orden que en los
// enums.
void mostrarMenu()
{
  std::cout<<"PROBADOR DE PROGRAMAS\nESTRUCTURAS LINEALES\nPARCIAL 2\n";
  std::cout<<"ELIGE UNA DE LAS SIGUIENTES OPCIONES:\n";
  std::cout<<" [0] PILA (STACK)\n";
  std::cout<<" [1] COLA (QUEUE)\n";
  std::cout<<" [2] LISTA ORDENADA SIN REPETICIONES (LINKEDLIST)\n";
}
