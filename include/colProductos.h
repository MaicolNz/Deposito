/*
  Módulo de definición de 'ColProductos'.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */

#ifndef _COLPRODUCTOS_H
#define _COLPRODUCTOS_H

#include "producto.h"
#include "pila.h"
#include "utils.h"

// Representación de 'ColProductos'.
// Declaración del tipo 'TColProductos'
typedef struct rep_colproductos *TColProductos;

/*
  Devuelve un 'ColProductos' vacío (sin elementos).
  El tiempo de ejecución debe ser O(1).
 */
TColProductos crearColProductos(); 

/*
  Libera la memoria asociada a 'colProd' y todos sus elementos.
  El tiempo de ejecución debe ser O(n), siendo 'n' la cantidad de elementos de
  'colProd'.
 */
void liberarColProductos(TColProductos colProd); 

/*
Devuelve true si existe un Producto con identificador 'idProd'.
En caso contrario devuelve false.
El tiempo de ejecución debe ser O(log(n)).
*/
bool existeProductoEnColProductos(nat idProd, TColProductos colProd);

/*
  Devuelve el Producto cuyo componente natural es 'idProd'.
  Si 'idProd' no pertenece a 'colProd', devuelve NULL.
  El tiempo de ejecución debe ser O(log(n)).
 */
Producto buscarProductoEnColProductos(nat idProd, TColProductos colProd); 

/*
  Inserta 'dato' en 'colProd'. 
  Precondición: !existeProductoEnColProductos()
  El tiempo de ejecución debe ser O(log(n)).
 */
TColProductos insertarEnColProductos(Producto dato, TColProductos colProd);

/*
  Remueve de 'colProd' el elemento con identificador idProd.
  Devuelve 'colProd'.
  Precondición: existeProductoEnColProductos()
  El tiempo de ejecución debe ser O(log(n)).
 */
TColProductos removerDeColProductos(nat idProd, TColProductos colProd);

/*
  Devuelve una pila con los elementos de la colección ordenados por identificador
  de menor a mayor.
*/
TPila colProdAPila(TColProductos colProd);

#endif
