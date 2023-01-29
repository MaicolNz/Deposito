/* 5209148 */

/*
  Módulo de definición de 'Deposito'.

  Los elementos de tipo 'Deposito' son punteros a una estructura (que debe
  definirse en deposito.cpp).

  Laboratorio de Programación 2 2do semestre 2022.
  InCo-FIng-UDELAR
 */

#include "../include/deposito.h"
#include "../include/fecha.h"
#include "../include/colProductos.h"
#include "../include/pila.h"
#include "../include/producto.h"

// Representación de 'Deposito'.
// Se debe definir en deposito.cpp.
// struct _rep_deposito;
// Declaración del tipo 'Deposito'.
struct _rep_deposito
{
  TColProductos productos;
};

/* Operaciones de deposito */

/*
  Devuelve un 'deposito'.
 */
TDeposito crearDeposito()
{
  TDeposito deposito = new _rep_deposito;
  deposito->productos = crearColProductos();
  return deposito;
}

/*
  Libera la memoria reservada por 'deposito' y de todos sus elementos.
 */
void liberarDeposito(TDeposito deposito)
{
  liberarColProductos(deposito->productos);
  delete (deposito);
}

/*
  Devuelve las unidades del producto con identificador 'identificador'
  en el deposito 'deposito'. O(log(n))
 */
nat obtenerCantidadUnidades(TDeposito deposito, int identificador)
{

  return obtenerCantidad(buscarProductoEnColProductos(identificador, deposito->productos));
}

/*
  Agrega un producto al depósito con el identificador y el nombre que se pasan como parametros. O(log(n))
  Pre: !existeProducto().
 */
void agregarProducto(TDeposito deposito, nat identificador, char *nombre)
{

  Producto nuevoP = crearProducto(identificador, nombre);
  deposito->productos = insertarEnColProductos(nuevoP, deposito->productos);
}

/*
  Devuelve true si existe un producto con identificador 'identificador'. O(log(n))
*/
bool existeProducto(TDeposito deposito, nat identificador)
{
  if (deposito->productos != NULL)
  {
    return existeProductoEnColProductos(identificador, deposito->productos);
  }
  else
    return false;
}
/*
  Quita del depósito todas las unidades que tengan fecha de vencimiento anterior
  o igual a la fecha pasada como parámetro.
*/
void quitarVencidosDeposito(TDeposito deposito, TFecha fecha)
{

  TPila pila = colProdAPila(deposito->productos);
  int cant = cantidadEnPila(pila);
  for (int i = 0; i < cant; i++)
  {
    quitarVencidos(cima(pila), fecha);
    pila = desapilar(pila);
  }
  liberarPila(pila);
}

/*
  Agrega cantidad unidades con fecha de vencimiento fVenc al producto de identificador
  'identificador'.
  Pre: existeProducto().
*/
void agregarUnidades(TDeposito deposito, nat identificador, nat cantidad, TFecha fVenc)
{
  if (existeProducto(deposito, identificador))
  {
    agregarUnidades(buscarProductoEnColProductos(identificador, deposito->productos), cantidad, fVenc);
  }
}

/*
    Quita cantidad elementos al producto con identificador 'identificador'.
    Se quitan los elementos con fecha de vencimiento más próxima.
    Pueden existir productos con cantidad 0 pero no con cantidad menor a cero.
    Pre: existeProducto() && obtenerCantidadUnidades() >= cantidad.
*/
void quitarUnidades(TDeposito deposito, nat identificador, nat cantidad)
{
  if (obtenerCantidadUnidades(deposito, identificador) >= cantidad)
  {
    quitarUnidades(buscarProductoEnColProductos(identificador, deposito->productos), cantidad);
  }
  else
    deposito->productos = removerDeColProductos(identificador, deposito->productos);
}

/*
    Si el producto existe, entonces lo elimina. También se deben eliminar todas
    las unidades del producto.
*/
void eliminarProducto(TDeposito deposito, nat identificador)
{
  deposito->productos = removerDeColProductos(identificador, deposito->productos);
}

/*
  Se debe imprimir el resumen del depósito de la forma que está aclarada en
  el archivo de especificación gestionDeposito.h
*/
void imprimirResumenDeposito(TDeposito deposito)
{
  if (deposito->productos != NULL)
  {
    TPila pila = colProdAPila(deposito->productos);
    int cant = cantidadEnPila(pila);
    for (int i = 0; i < cant; i++)
    {
      imprimirProducto(cima(pila));
      pila = desapilar(pila);
    }
    liberarPila(pila);
  }
}

/*
  Imprime los datos del producto en el formato específicado en la letra. O(log(n))
  Pre: existeProducto()
 */
void imprimirProducto(TDeposito deposito, int identificador)
{

  imprimirProducto(buscarProductoEnColProductos(identificador, deposito->productos));
}
