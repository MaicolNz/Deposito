/*
  Módulo de definición de 'Deposito'.

  Los elementos de tipo 'Deposito' son punteros a una estructura (que debe
  definirse en deposito.cpp).

  Laboratorio de Programación 2 2do semestre 2022.
  InCo-FIng-UDELAR
 */

#ifndef _DEPOSITO_H
#define _DEPOSITO_H

#include "utils.h"
#include "fecha.h"

// Representación de 'Deposito'.
// Se debe definir en deposito.cpp.
// struct _rep_deposito;
// Declaración del tipo 'Deposito'.
typedef struct _rep_deposito *TDeposito;

/* Operaciones de deposito */

/*
  Devuelve un 'deposito'.
 */
TDeposito crearDeposito();

/*
  Libera la memoria reservada por 'deposito' y de todos sus elementos.
 */
void liberarDeposito(TDeposito deposito); 

/*
  Devuelve las unidades del producto con identificador 'identificador'
  en el deposito 'deposito'. O(log(n))
 */
nat obtenerCantidadUnidades(TDeposito deposito, int identificador); 

/*
  Agrega un producto al depósito con el identificador y el nombre que se pasan como parametros. O(log(n))
  Pre: !existeProducto(). 
 */
void agregarProducto(TDeposito deposito, nat identificador, char* nombre); 

/*
  Devuelve true si existe un producto con identificador 'identificador'. O(log(n))
*/
bool existeProducto(TDeposito deposito, nat identificador); 

/*
  Quita del depósito todas las unidades que tengan fecha de vencimiento anterior 
  o igual a la fecha pasada como parámetro.
*/
void quitarVencidosDeposito(TDeposito deposito, TFecha fecha); 

/*
  Agrega cantidad unidades con fecha de vencimiento fVenc al producto de identificador
  'identificador'.
  Pre: existeProducto().
*/
void agregarUnidades(TDeposito deposito, nat identificador, nat cantidad, TFecha fVenc); 

/*
    Quita cantidad elementos al producto con identificador 'identificador'.
    Se quitan los elementos con fecha de vencimiento más próxima.
    Pueden existir productos con cantidad 0 pero no con cantidad menor a cero.
    Pre: existeProducto() && obtenerCantidadUnidades() >= cantidad.
*/
void quitarUnidades(TDeposito deposito, nat identificador, nat cantidad); 

/*
    Si el producto existe, entonces lo elimina. También se deben eliminar todas 
    las unidades del producto. 
*/
void eliminarProducto(TDeposito deposito, nat identificador); 

/*
  Se debe imprimir el resumen del depósito de la forma que está aclarada en
  el archivo de especificación gestionDeposito.h
*/
void imprimirResumenDeposito(TDeposito deposito); 

/*
  Imprime los datos del producto en el formato específicado en gestionDeposito.h.
  Pre: existeProducto()
*/
void imprimirProducto(TDeposito deposito, int identificador); 

#endif
