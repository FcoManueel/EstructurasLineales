#ifndef NODOSENCILLO_H_
#define NODOSENCILLO_H_

/* Un nodo sencillo (NodoSencillo) es una estructura compuesta por un dato
 * numérico llamado valor (entero) y un apuntador que contiene la dirección
 * de un nodo sencillo al cual está conectado.
 *
 * AUTOR Eduardo Acuña Yeomans
 * FECHA 03-03-2013
 */
class NodoSencillo {
	// Dato principal del nodo
 	int valor;
 	// Apuntador a nodo sencillo
	NodoSencillo * siguiente;

 public:
	NodoSencillo(int v, NodoSencillo * s);
	~NodoSencillo();

	void fijarValor(int v);
	void conectarA(NodoSencillo * s);
	int obtenerValor();
	NodoSencillo * obtenerConexion();
};

#endif	//	NODOSENCILLO_H_