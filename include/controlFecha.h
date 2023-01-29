/*
  Módulo de definición de 'TControlFecha'.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */

#ifndef _CONTROLFECHA_H
#define _CONTROLFECHA_H

#include <utils.h>
#include "fecha.h"

// Representación de 'TControlFecha'.
// Se debe definir en controlFecha.cpp.
// struct _rep_controlFecha;
// Declaración del tipo 'TControlFecha'
typedef struct _rep_controlFecha *TControlFecha;

/*
  Devuelve un TFecha vacío (sin fecha definida).
 */
TControlFecha crearControlFecha();

/*
  Libera la memoria asignada a 'f'.
*/
void liberarControlFecha(TControlFecha f);

/*
    Define la fecha actual de la aplicación. Si ya hay una fecha definida, la vuelve a redefinir.
	Ayuda: Tener cuidado con la memoria de la fecha anterior en caso de que se esté redefiniendo.
*/
void definirFecha(TControlFecha f, nat dia, nat mes, nat anio);

bool definidaFechaControl(TControlFecha f);

/*
    Incrementa en un día la fecha actual de la aplicación y luego imprime el texto "Se incrementó la fecha.\n".
    Si la fecha no está definida entonces imprime el mensaje "La fecha del sistema no se ha definido.\n".
*/
void aumentarFechaControl(TControlFecha f, nat cantDias);

/*
    Incrementa en un día la fecha actual de la aplicación y luego imprime el texto "Se aumentó un día.\n". 
	Si la fecha no está definida entonces imprime el mensaje "La fecha del sistema no se ha definido.\n".
*/
void siguienteDiaControl(TControlFecha f);

/*
	Compara f1 con f2. 
	Si f2 es posterior a f1 devuelve "Posterior a actual.\n". 
	Si f2 es igual a f1 devuelve "Fechas iguales.\n". 
    Si f2 es mayor a f1 devuelve "Anterior a actual.\n".
	Si la fecha no está definida entonces imprime el mensaje "La fecha del sistema no se ha definido.\n".
*/
void compararConActualControl(TControlFecha f1, TControlFecha f2);

/*
	Devuelve una copia de la fecha actual
*/
TFecha obtenerCopiaDeFecha(TControlFecha cf);

/*
    Imprime la fecha actual en formato corto (definido en el módulo fecha). 
    Si la fecha no está definida entonces imprime el mensaje "La fecha del sistema no se ha definido.\n".
*/
void fechaActualControl(TControlFecha f);

/*
    Imprime la fecha actual en formato corto (definido en el módulo fecha). 
    Si la fecha no está definida entonces imprime el mensaje "La fecha del sistema no se ha definido.\n".
*/
void fechaActualExtendidaControl(TControlFecha f);

#endif
