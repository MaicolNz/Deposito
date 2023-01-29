/* 5209148 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/pila.h"
#include "../include/cadena.h"
#include "../include/producto.h"

struct _rep_pila
{
  TCadena pila;
  nat cantidad;
};

/*
  Devuelve una TPila vacía (sin elementos).
  El tiempo de ejecución debe ser O(1).
 */
TPila crearPila()
{
  TPila pila = new _rep_pila;
  pila->cantidad = 0;
  pila->pila = crearCadena();
  return pila;
}

/*
  Libera la memoria asignada a 'p' si la pila no contiene elementos.
  El tiempo de ejecución debe ser O(n), siendo 'n' la cantidad de elementos de
  'p'.
 */
void liberarPila(TPila p)
{

  while (p->pila != NULL)
  {
    p = desapilar(p);
  }

  delete (p);
}

/*
  Devuelve la cantidad de elementos de 'p'.
  El tiempo de ejecución debe ser O(1).
 */
nat cantidadEnPila(TPila p)
{
  if (p != NULL)
    return p->cantidad;
  else
    return 0;
}

/*
  Apila 'info' en 'p'-
  Devuelve 'p'.
  La TPila resultado no comparte memoria con 'info'.
  El tiempo de ejecución debe ser O(1).
 */
TPila apilar(Producto dato, TPila p)
{
  p->pila = insertarAlInicio(p->pila, dato);
  p->cantidad++;
  return p;
}
/*
  Devuelve el elemento más nuevo en 'p'.
  Precondición: cantidadEnPila(p) > 0.
  El tiempo de ejecución debe ser O(1).W
 */
Producto cima(TPila p)
{
  if (cantidadEnPila(p) > 0)
  {
    return datoCadena(p->pila);
  }
  else
    return NULL;
}

/*
  Remueve de 'p' su elemento más nuevo.
  Se libera la memoria asignada utilizada por la pila para almacenarlo.
  Devuelve 'p'.
  Precondición: cantidadEnPila(p) > 0.
  El tiempo de ejecución debe ser O(1).
 */
TPila desapilar(TPila p)
{
  if (cantidadEnPila(p) > 0)
  {
    removerPrimero(p->pila);
    p->cantidad--;
    return p;
  }
  else
    return NULL;
}
