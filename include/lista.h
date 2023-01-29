/*
  Módulo de definición de 'TLista'.

  Los elementos de tipo TLista son Listas de elementos de tipo TInfo.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */

#ifndef _LISTA_H
#define _LISTA_H

#include "utils.h"
#include "vencimiento.h"
#include "fecha.h"

// Representación de 'TLista'.
// Se debe definir en Lista.cpp.
// struct _rep_Lista;
// Declaración del tipo 'TLista'
typedef struct _rep_lista* TLista;

/*
  Devuelve una TLista vacía (sin elementos).
  El tiempo de ejecución debe ser O(1).
 */
TLista crearLista();

/*
  Libera la memoria asignada a la TLista 'p' y la de todos sus elementos.
  El tiempo de ejecución debe ser O(n), siendo 'n' la cantidad de elementos de la TLista
  'p'.
 */
void liberarLista(TLista p);

/*
  Devuelve true si la TLista 'p' es vacia.
  El tiempo de ejecución debe ser O(1).
 */
bool esVaciaLista(TLista p);

/*
  Devuelve 'p' con un nuevo vencimiento insertado en caso de que no exista la fecha
  en la lista. Si ya existe un vencimiento con f_venc se le aumenta cantidad a dicho elemento.
  En caso de crear un nuevo vencimiento, la fecha utilizada al crearlo no debe 
  compartir memoria con 'f_venc' que se pasa por parámetro. 
  El tiempo de ejecución debe ser O(n).
 */
TLista agregarAListaOrdenado(TLista p, TFecha f_venc, nat cantidad);

/*
  Devuelve el elemento en 'p' con menor fecha de vencimiento de la lista.
  Precondición: cantidadEnLista(p) > 0.
  El tiempo de ejecución debe ser O(1).
 */
Vencimiento obtenerMasViejo(TLista p);

/*	
	Quita de la lista 'p' al elemento con la menor fecha de vencimiento.
	Pre: la lista tiene al menos un elemento.
*/
TLista quitarMasViejo(TLista p);

/*
Elimina 'cantidad' de unidades de vencimientos con menor fecha 
de la TLista 'p'. Si 'cantidad' es mayor que la cantidad de unidades 
sumadas que hay en la lista, entonces se deben eliminar todos los elementos de la lista. 
*/
TLista quitarDeLista(TLista p, nat cantidad);

/*Imprime información de la lista en el formato siguiente: 
	%Fecha vencimiento% -> %cantidad unidades%
	%Fecha vencimiento% -> %cantidad unidades%
	%Fecha vencimiento% -> %cantidad unidades%
*/
void imprimirInfoLista(TLista p);

#endif
