/*
  Módulo de definición de 'Vencimiento'.

  Los elementos de tipo 'Vencimiento' son punteros a una estructura (que debe
  definirse en vencimiento.cpp).

  Laboratorio de Programación 2 2do semestre 2022.
  InCo-FIng-UDELAR
 */

#ifndef _VENCIMIENTO_H
#define _VENCIMIENTO_H

#include "utils.h"
#include "fecha.h"

// Representación de 'Vencimiento'.
// Se debe definir en vencimiento.cpp.
// struct _rep_vencimiento;
// Declaración del tipo 'Vencimiento'.
typedef struct _rep_vencimiento *Vencimiento;

/* Operaciones de vencimiento */

/*
  Devuelve un 'vencimiento'.
 */
Vencimiento crearVencimiento(TFecha f_vencimiento, nat cantidad);

/*
  Libera la memoria reservada por 'vencimiento'.
 */
void liberarVencimiento(Vencimiento vencimiento);

/*
  Devuelve la fecha de vencimiento de 'vencimiento'.
 */
TFecha obtenerFVencimiento(Vencimiento vencimiento);

/*
  Devuelve la cantiadad de unidades 'vencimiento'.
 */
nat obtenerCantidad(Vencimiento vencimiento);

/*
    Agrega cantidad elementos a la unidad.
    Pre: cantidad debe ser mayor a cero. 
 */
void agregarUnidades(Vencimiento vencimiento, nat cantidad);

/*
    Quita cantidad elementos al vencimiento.
    Pre: cantidad debe ser mayor a cero y la cantidad a quitar 
    debe ser menor o igual a la cantidad de elementos
    del vencimiento.  
 */
void quitarUnidades(Vencimiento vencimiento, nat cantidad);

/*
  Imprime los datos del vencimiento en el formato específicado en la gestionDeposito.h.
 */
void imprimirVencimiento(Vencimiento vencimiento);

#endif
