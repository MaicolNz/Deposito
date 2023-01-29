/* 5209148 */

/*
  Módulo de implementación de 'ColProductos'.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */

#include "../include/producto.h"
#include "../include/pila.h"
#include "../include/utils.h"
#include "../include/colProductos.h"

// Representación de 'ColProductos'.
// Declaración del tipo 'TColProductos'
struct rep_colproductos
{
  Producto prod;
  rep_colproductos *izq, *der;
};

/*
  Devuelve un 'ColProductos' vacío (sin elementos).
  El tiempo de ejecución debe ser O(1).
 */
TColProductos crearColProductos()
{

  return NULL;
}

/*
  Libera la memoria asociada a 'colProd' pero no la de sus productos.
  El tiempo de ejecución debe ser O(n), siendo 'n' la cantidad de elementos de
  'colProd'.
 */
void liberarColProductos(TColProductos colProd)
{
  if (colProd != NULL)
  {
    TColProductos izq = colProd->izq;
    TColProductos der = colProd->der;
    //
    liberarProducto(colProd->prod);
    delete (colProd);
    //
    liberarColProductos(izq);
    liberarColProductos(der);
  }
  colProd = NULL;
}

/*
Devuelve true si existe un Producto con identificador 'idProd'.
En caso contrario devuelve false.
El tiempo de ejecución debe ser O(log(n)).
*/
bool existeProductoEnColProductos(nat idProd, TColProductos colProd)
{
  if (colProd == NULL)
  {
    return false;
  }
  else if (obtenerIdentificadorDeProducto(colProd->prod) == idProd)
  {
    return true;
  }
  else if (idProd < obtenerIdentificadorDeProducto(colProd->prod))
  {
    return existeProductoEnColProductos(idProd, colProd->izq);
  }
  else
    return existeProductoEnColProductos(idProd, colProd->der);
}

/*
  Devuelve el Producto cuyo componente natural es 'idProd'.
  Si 'idProd' no pertenece a 'colProd', devuelve NULL.
  El tiempo de ejecución debe ser O(log(n)).
 */
Producto buscarProductoEnColProductos(nat idProd, TColProductos colProd)
{

  if (colProd == NULL)
  {
    return NULL;
  }
  else if (obtenerIdentificadorDeProducto(colProd->prod) == idProd)
  {
    return colProd->prod;
  }
  else if (idProd < obtenerIdentificadorDeProducto(colProd->prod))
  {
    return buscarProductoEnColProductos(idProd, colProd->izq);
  }
  else
    return buscarProductoEnColProductos(idProd, colProd->der);
}
/*Devuelve el TColProd con el producto con el identificador dado*/
TColProductos ColbuscarProductoEnColProductos(nat idProd, TColProductos colProd)
{
  if (colProd == NULL)
  {
    return NULL;
  }
  else if (obtenerIdentificadorDeProducto(colProd->prod) == idProd)
  {

    return colProd;
  }
  else if (idProd < obtenerIdentificadorDeProducto(colProd->prod))
  {
    return ColbuscarProductoEnColProductos(idProd, colProd->izq);
  }
  else
    return ColbuscarProductoEnColProductos(idProd, colProd->der);
}
/*
  Inserta 'dato' en 'colProd'.
  Precondición: !existeProductoEnColProductos()
  El tiempo de ejecución debe ser O(log(n))
 */
TColProductos insertarEnColProductos(Producto dato, TColProductos colProd)
{
  if (colProd == NULL)
  {
    TColProductos nuevo = new rep_colproductos;
    nuevo->prod = dato;
    nuevo->der = NULL;
    nuevo->izq = NULL;
    return nuevo;
  }
  else
  {
    if (obtenerIdentificadorDeProducto(dato) < obtenerIdentificadorDeProducto(colProd->prod))
    {
      colProd->izq = insertarEnColProductos(dato, colProd->izq);
    }
    else if (obtenerIdentificadorDeProducto(dato) > obtenerIdentificadorDeProducto(colProd->prod))
    {
      colProd->der = insertarEnColProductos(dato, colProd->der);
    }
    return colProd;
  }
}
/*
  Remueve de 'colProd' el elemento con identificador idProd.
  Devuelve 'colProd'.
  Precondición: existeProductoEnColProductos()
  El tiempo de ejecución debe ser O(log(n))
 */
TColProductos min(TColProductos colProd)
{
  if (colProd == NULL)
  {
    return NULL;
  }
  if (colProd->izq)
  {
    return min(colProd->izq);
  }
  else
    return colProd;
}

/*Padre de un nodo*/
TColProductos padreN(TColProductos padre, TColProductos hijo)
{
  if (padre == NULL)
  {
    return NULL;
  }

  else if (padre->izq == hijo || padre->der == hijo || padre == hijo)
  {
    return padre;
  }
  else if (padre->der != NULL && obtenerIdentificadorDeProducto(padre->prod) < obtenerIdentificadorDeProducto(hijo->prod))
  {
    return padreN(padre->der, hijo);
  }
  else
    return padreN(padre->izq, hijo);
}

TColProductos removerDeColProductos(nat idProd, TColProductos colProd)
{
  if (colProd->der == NULL && colProd->izq == NULL)
  {
    liberarColProductos(colProd);
    colProd = NULL;
  }
  else
  {
    TColProductos raiz = ColbuscarProductoEnColProductos(idProd, colProd);
    /*caso raiz es una hoja*/
    if (raiz->der == NULL && raiz->izq == NULL)
    {

      TColProductos padre = padreN(colProd, raiz);
      if (padre->der == raiz)
      {
        padre->der = NULL;
      }
      else if (padre->izq == raiz)
      {
        padre->izq = NULL;
      }
      liberarColProductos(raiz);
      raiz = NULL;
    }
    /*Caso raiz tiene 2 hijos*/
    else if (raiz->der != NULL && raiz->izq != NULL)
    {
      TColProductos nuevaRaiz = min(raiz->der);
      TColProductos padre = padreN(colProd, nuevaRaiz);
      /*Swap*/

      Producto guardar = raiz->prod;
      raiz->prod = nuevaRaiz->prod;
      nuevaRaiz->prod = guardar;
      /*Borro nodo*/
      if (nuevaRaiz->der == NULL)
      {
        if (padre->der == nuevaRaiz)
        {
          liberarColProductos(nuevaRaiz);
          padre->der = NULL;
        }
        else
        {
          liberarColProductos(nuevaRaiz);
          padre->izq = NULL;
        }
      }
      else
      {
        if (raiz->der == nuevaRaiz)
        {

          raiz->der = nuevaRaiz->der;
          nuevaRaiz->der = NULL;
          liberarColProductos(nuevaRaiz);
        }
        else
        {
          padre->izq = nuevaRaiz->der;
          nuevaRaiz->der = NULL;
          liberarColProductos(nuevaRaiz);
        }
      }
    }
    else if (raiz->izq != NULL)
    {

      /*SWap*/
      if (raiz == colProd)
      {
        TColProductos eliminar = raiz;
        colProd = colProd->izq;
        eliminar->izq = NULL;
        liberarColProductos(eliminar);
        eliminar = NULL;
      }
      else
      {

        TColProductos padreNV = padreN(colProd, raiz);
        if (padreNV->der == raiz)
        {
          padreNV->der = raiz->izq;
        }
        else if (padreNV->izq == raiz)
        {
          padreNV->izq = raiz->izq;
        }
        raiz->izq = NULL;
        liberarColProductos(raiz);
      }
    }
    else if (raiz->der != NULL)
    {
      if (raiz == colProd)
      {
        TColProductos eliminar = raiz;
        colProd = colProd->der;
        eliminar->der = NULL;
        liberarColProductos(eliminar);
        eliminar = NULL;
      }
      else
      {
        TColProductos padreNV = padreN(colProd, raiz);
        padreNV->der = raiz->der;
        raiz->der = NULL;
        liberarColProductos(raiz);
      }
    }
  }
  return colProd;
}

/*
  Devuelve una pila con los elementos de la colección ordenados por identificador
  de menor a mayor.
*/
void crearPilaR(TColProductos colProd, TPila pila)
{
  if (colProd == NULL)
    return;
  crearPilaR(colProd->izq, pila);
  pila = apilar(colProd->prod, pila);
  crearPilaR(colProd->der, pila);
}

TPila colProdAPila(TColProductos colProd)
{

  if (colProd != NULL)
  {
    TPila pila = crearPila();
    crearPilaR(colProd, pila);
    return pila;
  }
  else
    return NULL;
}
