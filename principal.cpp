/*
 Módulo principal de la tarea 1.

Intérprete de comandos para probar los módulos implementados.

Cada comando tiene un nombre y una secuencia (posiblemente vacía) de parámetros.
Se asume que los comandos están bien formados. Esto implica que:
- el nombre es uno de los descritos más abajo;
- la cantidad y tipo de los parámetros cumplen con lo requerido.

El comando 'Fin' termina el programa

El comando '# comentario' imprime comentario.

El comando 'reiniciarEstructuras' libera la memoria asignada a todas las estructuras y las vuelve a crear.

 Laboratorio de Programación 2.
 InCo-FIng-UDELAR
*/

#include "include/utils.h"
#include "include/fecha.h"
#include "include/controlFecha.h"
#include "include/gestionDeposito.h"
#include "include/lista.h"
#include "include/vencimiento.h"

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PALABRA 32
#define MAX_LINEA 256

#define MAX_CP 10
#define MAX_MAP 10
#define TAM_COL_CAD 10

// programa principal
int main()
{

	TControlFecha cf = crearControlFecha();
	TGestionDeposito gd = crearGestionDeposito();
	TLista lista = crearLista();

	char restoLinea[MAX_LINEA + 1];
	char nom_comando[MAX_PALABRA];

	int cont_comandos = 0;
	bool salir = false;
	while (!salir)
	{
		// mostrar el prompt
		cont_comandos++;
		printf("%u>", cont_comandos);

		// leer el comando
		leerChars(nom_comando);

		// procesar el comando
		if (0 == strcmp(nom_comando, "Fin"))
		{
			salir = true;
			printf("Fin.\n");

			// Funcionalidades tarea 1
		}
		else if (0 == strcmp(nom_comando, "#"))
		{
			leerRestoLinea(restoLinea);
			printf("# %s.\n", restoLinea);
		}
		else if (0 == strcmp(nom_comando, "definirFecha"))
		{
			nat *componentes = leerFecha();
			definirFecha(cf, componentes[0], componentes[1], componentes[2]);
			delete[] componentes;
			printf("Fecha definida en forma exitosa.\n");
			TFecha f = obtenerCopiaDeFecha(cf);
			quitarVencidosDeposito(gd, f);
			liberarFecha(f);
		}
		else if (0 == strcmp(nom_comando, "siguienteDia"))
		{
			siguienteDiaControl(cf);
			// TODO:: Llamar funcion para quitar a los productos vencidos.
			printf("siguienteDia.\n");
			TFecha f = obtenerCopiaDeFecha(cf);
			quitarVencidosDeposito(gd, f);
			liberarFecha(f);
		}
		else if (0 == strcmp(nom_comando, "aumentarDias"))
		{
			nat cantDias = leerNat();
			aumentarFechaControl(cf, cantDias);
			// TODO:: Llamar funcion para quitar a los productos vencidos.
			printf("aumentarDias %d.\n", cantDias);
			TFecha f = obtenerCopiaDeFecha(cf);
			quitarVencidosDeposito(gd, f);
			liberarFecha(f);
		}
		else if (0 == strcmp(nom_comando, "fechaActual"))
		{
			fechaActualControl(cf);
		}
		else if (0 == strcmp(nom_comando, "fechaActualExtendida"))
		{
			fechaActualExtendidaControl(cf);
		}
		else if (0 == strcmp(nom_comando, "compararFecha"))
		{
			nat *componentes = leerFecha();
			TControlFecha cfComp = crearControlFecha();
			definirFecha(cfComp, componentes[0], componentes[1], componentes[2]);
			delete[] componentes;
			compararConActualControl(cf, cfComp);
			liberarControlFecha(cfComp);

			// Funcionalidades tarea 2
		}
		else if (0 == strcmp(nom_comando, "agregarNuevoProducto"))
		{
			nat idProd = leerNat();
			char *nombreProducto = new char[30];
			leerChars(nombreProducto);
			if (agregarProductoDeposito(gd, idProd, nombreProducto))
				printf("Producto agregado %d - %s.\n", idProd, nombreProducto);
			else
				printf("Ya existe un producto con el identificador ingresado.\n");
			delete[] nombreProducto;
		}
		else if (0 == strcmp(nom_comando, "quitarProducto"))
		{
			nat idProd = leerNat();
			printf("quitarProducto %d.\n", idProd);
			if (quitarProductoDeposito(gd, idProd))
				printf("Producto %d quitado.\n", idProd);
			else
				printf("No fue posible realizar esta operación.\n");
		}
		else if (0 == strcmp(nom_comando, "vencimientosProducto"))
		{
			nat idProd = leerNat();
			// listar los vencimientos de todos los productos
			if (!imprimirProductoResumenDeposito(gd, idProd))
			{
				printf("No existe un producto con el identificador ingresado.\n");
			}
		}
		else if (0 == strcmp(nom_comando, "resumenDeposito"))
		{
			imprimirResumenGestionDeposito(gd);
		}
		else if (0 == strcmp(nom_comando, "agregarUnidades"))
		{
			nat idProd = leerNat();
			nat cantUnidades = leerNat();
			nat *fechaVenc = leerFecha();
			TFecha f = crearFecha(fechaVenc[0], fechaVenc[1], fechaVenc[2]);
			TFecha f_actual = definidaFechaControl(cf) ? obtenerCopiaDeFecha(cf) : NULL;
			if (agregarCantidadProductoDeposito(gd, idProd, cantUnidades, f, f_actual))
				printf("Al producto %d se le agregaron %d unidades con fecha de vencimiento %d/%d/%d.\n", idProd, cantUnidades, fechaVenc[0], fechaVenc[1], fechaVenc[2]);
			else
				printf("No fue posible agregar las unidades.\n");
			liberarFecha(f);
			liberarFecha(f_actual);
			delete[] fechaVenc;
		}
		else if (0 == strcmp(nom_comando, "quitarUnidades"))
		{
			nat idProd = leerNat();
			nat cantUnidades = leerNat();
			printf("quitarUnidades %d - %d.\n", idProd, cantUnidades);
			quitarCantidadProductoDeposito(gd, idProd, cantUnidades);
		}
		else if (0 == strcmp(nom_comando, "quitarProximasAVencer"))
		{
			// quitar unidades que vencen dentro de una semana
			printf("Se quitaron las proximas a vencer.\n");
			TFecha f = obtenerCopiaDeFecha(cf);
			quitarProximosAVencerDeposito(gd, f);
			liberarFecha(f);

			// Funcionalidades para probar el funcionamiento de lista vencimientos
		}
		else if (0 == strcmp(nom_comando, "agregarALista"))
		{
			nat cantUnidades = leerNat();
			nat *componentes = leerFecha();
			TFecha f = crearFecha(componentes[0], componentes[1], componentes[2]);
			lista = agregarAListaOrdenado(lista, f, cantUnidades);
			liberarFecha(f);
			printf("Se agregaron %d elementos con fecha %d/%d/%d.\n", cantUnidades, componentes[0], componentes[1], componentes[2]);
			delete[] componentes;
		}
		else if (0 == strcmp(nom_comando, "quitarDeLista"))
		{
			nat cantUnidades = leerNat();
			lista = quitarDeLista(lista, cantUnidades);
			printf("Se quitaron elementos de la lista.\n");
		}
		else if (0 == strcmp(nom_comando, "obtenerMasViejo"))
		{
			imprimirVencimiento(obtenerMasViejo(lista));
		}
		else if (0 == strcmp(nom_comando, "quitarMasViejo"))
		{
			if (!esVaciaLista(lista))
			{
				Vencimiento venc = obtenerMasViejo(lista);
				lista = quitarMasViejo(lista);
				liberarVencimiento(venc);
				printf("Se quitaron elementos de la lista.\n");
			}
			else
			{
				printf("La lista esta vacia.\n");
			}
		}
		else if (0 == strcmp(nom_comando, "esVaciaLista"))
		{
			if (esVaciaLista(lista))
				printf("La lista esta vacia.\n");
			else
				printf("La lista contiene elementos.\n");
		}
		else if (0 == strcmp(nom_comando, "imprimirInfoLista"))
		{
			if (esVaciaLista(lista))
				printf("La lista esta vacia.\n");
			else
				imprimirInfoLista(lista);
			// Funcionalidad para reiniciar las estructuras
		}
		else if (0 == strcmp(nom_comando, "reiniciarEstructuras"))
		{
			liberarControlFecha(cf);
			liberarGestionDeposito(gd);
			liberarLista(lista);
			cf = crearControlFecha();
			gd = crearGestionDeposito();
			lista = crearLista();
			printf("Estructuras reiniciadas.\n");
		}
		else
		{
			printf("Comando no reconocido.\n");
		} // if
		fgets(restoLinea, MAX_LINEA + 1, stdin);
	} // while

	liberarControlFecha(cf);
	liberarGestionDeposito(gd);
	liberarLista(lista);
	return 0;
} // main
