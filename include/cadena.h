/*
  Módulo de definición de 'TCadena'.

  Los elementos de tipo TCadena son colecciones lineales NO acotadas de elementos.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */

#ifndef _CADENA_H
#define _CADENA_H

#include "utils.h"
#include "producto.h"

// Representación de 'TCadena'.
// Se debe definir en 'cadena.cpp'.
// struct _rep_cadena;
// Declaración del tipo 'TCadena'
typedef struct _rep_cadena *TCadena;

/*
  Devuelve la 'TCadena' vacía (sin elementos).
  No se debe obtener memoria.
  El tiempo de ejecución debe ser O(1).
 */
TCadena crearCadena();

/*
  Inserta al inicio de 'cad' un elemento.
  Los demás elementos de 'cad' mantienen su orden relativo.
  Devuelve 'cad'.
  El tiempo de ejecución debe ser O(1).
 */
TCadena insertarAlInicio(TCadena cad, Producto dato);

/*
  Inserta al final de 'cad' un elemento.
  Devuelve 'cad'.
  El tiempo de ejecución debe ser O(n).
 */
TCadena insertarAlFinal(TCadena cad, Producto dato);

/*
  Remueve el primer elemento de 'cad'.
  Se libera la memoria asignada al mismo.
  Precondición: cantidadEnCadena(cad) > 0.
  El tiempo de ejecución debe ser O(1).
 */
Producto removerPrimero(TCadena & cad);

/*
  Devuelve la cantidad de elementos de 'cad'.
  El tiempo de ejecución debe ser O(n), siendo 'n' la cantidad de elementos de 'cad'.
 */
nat cantidadEnCadena(TCadena cad);

/*
  Devuelve el ultimo nodo de 'cad'.
  El tiempo de ejecución debe ser O(n), siendo 'n' la cantidad de elementos de 'cad'.
 */
TCadena ultimoEnCadena(TCadena cad);

/*
  Devuelve el elemento asociado al primer nodo de 'cad'.
*/

Producto datoCadena(TCadena cad);

#endif
