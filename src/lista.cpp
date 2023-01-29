/* 5209148 */

/*
  Módulo de definición de 'TLista'.

  Los elementos de tipo TLista son Listas de elementos de tipo TFecha.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */

#include "../include/utils.h"
#include "../include/lista.h"
#include "../include/vencimiento.h"
#include "../include/fecha.h"

// Representación de 'TLista'.
// Se debe definir en Lista.cpp.
// Declaración del tipo 'TLista'
struct _rep_lista
{
  _rep_lista *sig;
  Vencimiento ven;
};

// Que sentido tiene esta funcion?
/*
  Devuelve una TLista vacía (sin elementos).
  El tiempo de ejecución debe ser O(1).
 */
TLista crearLista()
{

  return NULL;
}

/*
  Libera la memoria asignada a la TLista 'p' y la de todos sus elementos.
  El tiempo de ejecución debe ser O(n), siendo 'n' la cantidad de elementos de la TLista
  'p'.
 */
void liberarLista(TLista p)
{
  TLista aux;
  while (p != NULL)
  {
    aux = p;
    p = p->sig;
    liberarVencimiento(aux->ven);
    delete (aux);
  }
  delete (p);
  p = NULL;
}

/*
  Devuelve true si la TLista 'p' es vacia.
  El tiempo de ejecución debe ser O(1).
 */
bool esVaciaLista(TLista p)
{
  if (p != NULL)
    return false;
  else
    return true;
}

/*
  Devuelve 'p' con un nuevo vencimiento insertado en caso de que no exista la fecha
  en la lista. Si ya existe un vencimiento con f_venc se le aumenta cantidad a dicho elemento.
  En caso de crear un nuevo vencimiento, la fecha utilizada al crearlo no debe
  compartir memoria con 'f_venc' que se pasa por parámetro.
  El tiempo de ejecución debe ser O(n).
 */
TLista agregarAListaOrdenado(TLista p, TFecha f_venc, nat cantidad)
{
  TLista nuevo = new _rep_lista;
  nuevo->ven = crearVencimiento(f_venc, cantidad);
  if (p == NULL)
  {
    nuevo->sig = NULL;
    p = nuevo;
  }
  else
  {
    if (compararFechas(f_venc, obtenerFVencimiento(p->ven)) == -1)
    {
      nuevo->sig = p;
      p = nuevo;
    }
    else
    {

      TLista aux = p;
      while (aux->sig != NULL && compararFechas(f_venc, obtenerFVencimiento(aux->sig->ven)) == 1)
      {
        aux = aux->sig;
      }
      if (aux->sig == NULL)
      {
        aux->sig = nuevo;
        nuevo->sig = NULL;
      }
      else if (aux->sig != NULL && compararFechas(f_venc, obtenerFVencimiento(aux->sig->ven)) == -1)
      {
        nuevo->sig = aux->sig;
        aux->sig = nuevo;
      }
      else if (compararFechas(f_venc, obtenerFVencimiento(aux->sig->ven)) == 0)
      {
        agregarUnidades(aux->sig->ven, cantidad);
        liberarVencimiento(nuevo->ven);
        delete (nuevo);
      }
    }
  }
  return p;
}

/*
  Devuelve el elemento en 'p' con menor fecha de vencimiento de la lista.
  Precondición: cantidadEnLista(p) > 0.
  El tiempo de ejecución debe ser O(1).
 */
Vencimiento obtenerMasViejo(TLista p)
{
  if (p)
  {
    return p->ven;
  }
  else
    return NULL;
}

/*
  Quita de la lista 'p' al elemento con la menor fecha de vencimiento.
  Pre: la lista tiene al menos un elemento.
*/
TLista quitarMasViejo(TLista p)
{
  if (p->ven != NULL)
  {
    TLista aux = p;
    p = p->sig;
    delete (aux);
  }

  return p;
}

/*
Elimina 'cantidad' de unidades de vencimientos con menor fecha
de la TLista 'p'. Si 'cantidad' es mayor que la cantidad de unidades
sumadas que hay en la lista, entonces se deben eliminar todos los elementos de la lista.
*/
TLista quitarDeLista(TLista p, nat cantidad)
{
  Vencimiento venc;
  while (p != NULL && obtenerCantidad(p->ven) < cantidad)
  {
    cantidad -= obtenerCantidad(p->ven);
    venc = obtenerMasViejo(p);
    p = quitarMasViejo(p);
    liberarVencimiento(venc);
  };
  if (p != NULL && obtenerCantidad(p->ven) > cantidad)
  {
    quitarUnidades(p->ven, cantidad);
  }
  else if (p != NULL && obtenerCantidad(p->ven) == cantidad)
  {
    venc = obtenerMasViejo(p);
    p = quitarMasViejo(p);
    liberarVencimiento(venc);
  }
  return p;
}

/*
    Imprime información de la lista en el formato siguiente:
  %Fecha vencimiento% -> %cantidad unidades%
  %Fecha vencimiento% -> %cantidad unidades%
  %Fecha vencimiento% -> %cantidad unidades%
*/
void imprimirInfoLista(TLista p)
{
  TLista aux = p;
  while (aux != NULL)
  {
    imprimirVencimiento(aux->ven);
    aux = aux->sig;
  }
}
