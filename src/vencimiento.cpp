/* 5209148 */

/*
  Módulo de implementación de 'Vencimiento'.

  Los elementos de tipo 'Vencimiento' son punteros a una estructura (que debe
  definirse en vencimiento.cpp).

  Laboratorio de Programación 2 2do semestre 2022.
  InCo-FIng-UDELAR
 */

#include "../include/utils.h"
#include "../include/vencimiento.h"

// Representación de 'Vencimiento'.
// Se debe definir en vencimiento.cpp.
// struct _rep_vencimiento;
// Declaración del tipo 'Vencimiento'.
struct _rep_vencimiento
{
  TFecha f_vencimiento;
  nat cantidad;
};

/* Operaciones de vencimiento */

/*
  Devuelve un 'vencimiento'.
 */
Vencimiento crearVencimiento(TFecha f_vencimiento, nat cantidad)
{
  Vencimiento ven = new _rep_vencimiento;
  ven->cantidad = cantidad;
  ven->f_vencimiento = crearCopiaFecha(f_vencimiento);
  ;

  return ven;
}

/*
  Libera la memoria reservada por 'vencimiento' y la de sus elementos.
 */
void liberarVencimiento(Vencimiento vencimiento)
{
  if (vencimiento != NULL)
  {
    liberarFecha(vencimiento->f_vencimiento);
    delete (vencimiento);
  }
}

/*
  Devuelve la fecha de vencimiento de 'vencimiento'.
 */
TFecha obtenerFVencimiento(Vencimiento vencimiento) { return vencimiento->f_vencimiento; }

/*
  Devuelve la cantiadad de unidades 'vencimiento'.
 */
nat obtenerCantidad(Vencimiento vencimiento)
{
  return vencimiento->cantidad;
}

/*
    Agrega cantidad elementos a la unidad.
    Pre: cantidad debe ser mayor a cero.
 */
void agregarUnidades(Vencimiento vencimiento, nat cantidad)
{

  if (cantidad > 0)
  {
    vencimiento->cantidad += cantidad;
  }
}

/*
    Quita cantidad elementos al vencimiento.
    Pre: cantidad debe ser mayor a cero y la cantidad a quitar
    debe ser menor o igual a la cantidad de elementos
    del vencimiento.
 */
void quitarUnidades(Vencimiento vencimiento, nat cantidad)
{
  if (cantidad >= 0 && cantidad <= vencimiento->cantidad)
  {
    vencimiento->cantidad -= cantidad;
  }
}

/*
  Imprime los datos del vencimiento en el formato específicado en la gestionDeposito.h.
 */
void imprimirVencimiento(Vencimiento vencimiento)
{
  if (vencimiento != NULL)
  {
    char *fecha = fechaActual(vencimiento->f_vencimiento);
    printf("%s -> %d \n", fecha, vencimiento->cantidad);
    delete[] (fecha);
  }
}
