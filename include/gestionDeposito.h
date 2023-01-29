/*
  Módulo de definición de 'GestionDeposito'.

  Los elementos de tipo 'GestionDeposito' son punteros a una estructura (que debe
  definirse en gestionDeposito.cpp).

  Laboratorio de Programación 2 2do semestre 2022.
  InCo-FIng-UDELAR
 */

#ifndef _GESTIONDEPOSITO_H
#define _GESTIONDEPOSITO_H

#include "utils.h"
#include "fecha.h"

// Representación de 'GestionDeposito'.
// Se debe definir en gestionDeposito.cpp.
// struct _rep_gestionDeposito;
// Declaración del tipo 'GestionDeposito'.
typedef struct _rep_gestionDeposito *TGestionDeposito;

/* Operaciones para controlar el depósito.*/
/* Operaciones de gestionDeposito */

/*
  Devuelve un 'gestionDeposito' sin productos asignados.
 */
TGestionDeposito crearGestionDeposito(); 

/*
  Libera la memoria reservada por 'gestionDeposito' y por las subestructuras utilizadas. 
 */
void liberarGestionDeposito(TGestionDeposito gestionDeposito); 

/* 
  Se deben retirar todos los productos cuya fecha de 
  vencimiento sea menor o igual que la fecha que se pasa por parametro.
  Recordar que los productos pueden quedar con cantidad 0. 
*/
void quitarVencidosDeposito(TGestionDeposito gestionDeposito, TFecha fecha); 

/*
  Agrega un producto con identificador idProd y nombre nombreProducto al deposito.
*/
bool agregarProductoDeposito(TGestionDeposito gestionDeposito, nat idProd, char* nombreProducto); 


/*
  Agrega 'cantidad' productos con identificador 'idProd' y con fecha de vencimiento 'f' de tipo TFecha. Si 'f_actual' es mayor a la fecha 'f' entonces el producto no se deberá agregar y la función debe devolver false. En caso contrario la función debe devolver true. 
  Si no existen unidades con esa fecha de vencimiento, entonces crea un vencimiento y agrega cantidad unidades. 
*/
bool agregarCantidadProductoDeposito(TGestionDeposito gestionDeposito, nat idProd, nat cantidad, TFecha f, TFecha f_actual); 

/*
  Quita un producto con identificador idProd que no tiene unidades.
  Si el producto no existe o tiene unidades entonces devuelve falso.
*/
bool quitarCantidadProductoDeposito(TGestionDeposito gestionDeposito, nat idProd, nat cantidad); 

/*
  Quita un producto con identificador idProd del pedido idPed. Si el producto no existe en el pedido
  entonces devuelve falso.
*/
bool quitarProductoDeposito(TGestionDeposito gestionDeposito, nat idProd);

/*
  Imprime la información de un producto con el formato especificado. 
  Se listan los vencimientos y cantidad por vencimiento para el producto. 
  Si el pedido no existe, entonces devuelve falso. 
  La información se tiene que imprimir de la siguiente forma:
  Información del producto %idProd% - %Nombre producto%
  Total de unidades: %total unidades%
  %Fecha vencimiento% -> %cantidad unidades%
  %Fecha vencimiento% -> %cantidad unidades%
  %Fecha vencimiento% -> %cantidad unidades%
 */
bool imprimirProductoResumenDeposito(TGestionDeposito gestionDeposito, nat idProd);

/*
Quita todas las unidades de los productos que vencerán dentro de los próximos 7 días.
*/
void quitarProximosAVencerDeposito(TGestionDeposito gestionDeposito, TFecha fecha);

/*
  Imprime el resumen del depósito en el formato siguiente:
  Cantidad de productos: %cantidad%
  %Id Producto% - %Nombre producto% -> %cantidad unidades%
  %Id Producto% - %Nombre producto% -> %cantidad unidades%
  %Id Producto% - %Nombre producto% -> %cantidad unidades% 
 */
void imprimirResumenGestionDeposito(TGestionDeposito gestionDeposito);

#endif
