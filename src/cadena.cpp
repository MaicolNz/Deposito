/* 5209148 */
/*
  Módulo de implementación de 'TCadena'.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */

#include "../include/cadena.h"
#include "../include/utils.h"
#include "../include/producto.h"

#include <assert.h>
#include <stdlib.h>

struct _rep_cadena
{
  Producto dato;
  TCadena sig;
};

TCadena crearCadena() { return NULL; }

TCadena insertarAlInicio(TCadena cad, Producto dato)
{
  _rep_cadena *nuevo = new _rep_cadena;
  nuevo->dato = dato;
  if (cad == NULL)
  {
    nuevo->sig = NULL;
    cad = nuevo;
  }
  else
  {
    nuevo->sig = cad;
    cad = nuevo;
  }
  return cad;
}

TCadena insertarAlFinal(TCadena cad, Producto dato)
{
  TCadena iter = cad;
  TCadena nuevo = new _rep_cadena;
  nuevo->dato = dato;
  nuevo->sig = NULL;
  if (cad == NULL)
  {
    cad = nuevo;
  }
  else
  {
    while (iter->sig != NULL)
    {
      iter = iter->sig;
    }
    iter->sig = nuevo;
  }
  return cad;
}

TCadena insertarEnPos(TCadena cad, Producto dato, nat pos)
{
  TCadena nuevo = new _rep_cadena;
  nuevo->dato = dato;
  nuevo->sig = NULL;
  if (cad == NULL)
  {
    cad = nuevo;
  }
  else
  {
    TCadena iter = cad;
    while (pos > 0)
    {
      pos--;
      iter = iter->sig;
    }
    nuevo->sig = iter->sig;
    iter->sig = nuevo;
  }
  return cad;
}

Producto removerPrimero(TCadena &cad)
{
  if (cad == NULL)
    return NULL;
  TCadena inicio = cad;
  cad = cad->sig;
  Producto ret = inicio->dato;
  inicio->dato = NULL;
  delete inicio;
  return ret;
}

Producto removerPos(TCadena &cad, nat pos)
{
  if (cad == NULL)
    return NULL;
  TCadena ret = cad;
  TCadena ant = cad;
  if (pos == 1)
  {
    ret = cad->sig;
  }
  else
  {
    while (pos > 0)
    {
      pos--;
      ant = cad;
      cad = cad->sig;
    }
    ant->sig = cad->sig;
  }
  Producto retVal = cad->dato;
  cad->dato = NULL;
  delete cad;
  cad = ret;
  return retVal;
}

nat cantidadEnCadena(TCadena cad)
{
  nat cantidad = 0;
  if (cad != NULL)
  {
    TCadena cursor = cad;
    while (cursor != NULL)
    {
      cantidad++;
      cursor = cursor->sig;
    }
  }
  return cantidad;
}

TCadena ultimoEnCadena(TCadena cad)
{
  TCadena ret = NULL;
  if (cad != NULL)
  {
    TCadena iter = cad;
    while (iter->sig != NULL)
    {
      iter = iter->sig;
    }
    ret = iter;
  }
  return ret;
}

Producto datoCadena(TCadena cad)
{
  return cad->dato;
}

TCadena cadenaSiguiente(TCadena cad)
{
  _rep_cadena *cursor = cad;
  if (cursor != NULL)
    cursor = cad->sig;
  return cursor;
}
