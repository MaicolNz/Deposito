/* 5209148 */
/*
  Módulo de definición de 'TFecha'.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */

#include "../include/utils.h"
#include "../include/fecha.h"
#include "stdio.h"
#include "string.h"

// Representación de 'TFecha'.
// Se debe definir en fecha.cpp.
// struct _rep_fecha;
// Declaración del tipo 'TFecha'
struct _rep_fecha
{
    nat dia;
    nat mes;
    nat anio;
};

/*
  Devuelve un TFecha con el día, mes y año definidos en los parámetros.
 */
TFecha crearFecha(nat dia, nat mes, nat anio)
{
    TFecha nuevo = new _rep_fecha();
    nuevo->dia = dia;
    nuevo->mes = mes;
    nuevo->anio = anio;
    return nuevo;
}

bool definidaFecha(TFecha f)
{
    return (f != NULL);
}

/*
  Devuelve un TFecha igual que f_a_copiar,
  La TFecha resultado no comparte memoria con f_a_copiar
 */
TFecha crearCopiaFecha(TFecha f_a_copiar)
{
    TFecha nuevo = new _rep_fecha();
    nuevo->dia = f_a_copiar->dia;
    nuevo->mes = f_a_copiar->mes;
    nuevo->anio = f_a_copiar->anio;
    return nuevo;
}

/*
  Libera la memoria asignada a 'f'.
*/
void liberarFecha(TFecha f)
{
    delete f;
    f = NULL;
}

/*
    Aumenta la fecha cantDias días.
*/
void aumentarFecha(TFecha f, nat cantDias)
{
    while (cantDias > 0)
    {
        siguienteDia(f);
        cantDias--;
    }
}

/*
    Incrementa en un día la fecha actual de la aplicación.
*/
void siguienteDia(TFecha f)
{
    f->dia++;
    switch (f->mes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
        if (f->dia > 31)
        {
            f->dia = 1;
            f->mes++;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (f->dia > 30)
        {
            f->dia = 1;
            f->mes++;
        }
        break;
    case 12:
        if (f->dia > 31)
        {
            f->dia = 1;
            f->mes = 1;
            f->anio++;
        }
        break;
    case 2:
        bool bisiesto = ((f->anio % 4 == 0) && ((f->anio % 100 != 0) || ((f->anio % 100 == 0) && (f->anio % 400 == 0))));
        if (bisiesto)
        {
            if (f->dia > 29)
            {
                f->dia = 1;
                f->mes++;
            }
        }
        else
        {
            if (f->dia > 28)
            {
                f->dia = 1;
                f->mes++;
            }
        }
        break;
    }
}

/*
    Compara f1 con f2. Si f1 es anterior a f2 devuelva -1. Si f1 es igual a f2 devuelve 0.
    Si f1 es mayor a f2 devuelve 1.
*/
int compararFechas(TFecha f1, TFecha f2)
{
    int ret = 0;
    if (f1->anio == f2->anio)
    {
        if (f1->mes == f2->mes)
        {
            if (f1->dia < f2->dia)
                ret = -1;
            else if (f1->dia > f2->dia)
                ret = 1;
        }
        else
        {
            if (f1->mes < f2->mes)
                ret = -1;
            else
                ret = 1;
        }
    }
    else
    {
        if (f1->anio < f2->anio)
            ret = -1;
        else
            ret = 1;
    }
    return ret;
}

/*
    Devuelve un char* que contiene la representación de la fecha en formato corto, es decir dd/mm/aaaa.
    Por ejemplo 01/01/2022.
*/
char *fechaActual(TFecha f)
{
    char *fechaStr = new char[11];
    sprintf(fechaStr, "%u/%u/%u", f->dia, f->mes, f->anio);
    return fechaStr;
}

/*
    Devuelve un char* que contiene la representación de la fecha en formato extendido.
    Por ejemplo para la fecha 01/01/2022 se debería imprimir '01 de enero de 2022'.
*/
char *fechaActualExtendida(TFecha f)
{
    char *fechaStr = new char[30];
    switch (f->mes)
    {
    case 1:
        sprintf(fechaStr, "%u de Enero de %u", f->dia, f->anio);
        break;
    case 2:
        sprintf(fechaStr, "%u de Febrero de %u", f->dia, f->anio);
        break;
    case 3:
        sprintf(fechaStr, "%u de Marzo de %u", f->dia, f->anio);
        break;
    case 4:
        sprintf(fechaStr, "%u de Abril de %u", f->dia, f->anio);
        break;
    case 5:
        sprintf(fechaStr, "%u de Mayo de %u", f->dia, f->anio);
        break;
    case 6:
        sprintf(fechaStr, "%u de Junio de %u", f->dia, f->anio);
        break;
    case 7:
        sprintf(fechaStr, "%u de Julio de %u", f->dia, f->anio);
        break;
    case 8:
        sprintf(fechaStr, "%u de Agosto de %u", f->dia, f->anio);
        break;
    case 9:
        sprintf(fechaStr, "%u de Setiembre de %u", f->dia, f->anio);
        break;
    case 10:
        sprintf(fechaStr, "%u de Octubre de %u", f->dia, f->anio);
        break;
    case 11:
        sprintf(fechaStr, "%u de Noviembre de %u", f->dia, f->anio);
        break;
    case 12:
        sprintf(fechaStr, "%u de Diciembre de %u", f->dia, f->anio);
        break;
    }
    return fechaStr;
}

nat getDia(TFecha f)
{
    return f->dia;
}

nat getMes(TFecha f)
{
    return f->mes;
}

nat getAnio(TFecha f)
{
    return f->anio;
}
