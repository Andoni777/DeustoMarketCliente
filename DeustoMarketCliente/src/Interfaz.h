/*
 * Interfaz.h
 *
 *  Created on: 11 may 2026
 *      Author: andoni.g
 */

#ifndef SRC_INTERFAZ_H_
#define SRC_INTERFAZ_H_
#include "../domain/Protocolo.h"
class Interfaz {

public:
	Interfaz();
	int leerOpcion();

	// Menu Principal
	int mostrarMenu();

	// SubMenus
	int mostrarMenuGestSuper();
	int mostrarMenuGestIyP();
	int mostrarMenuGestEmpleado();
	int mostrarLogs();

	// Funciones auxiliares

	// Supers
	SupermercadoData pedirDatosSuper();
	int pedirIdSuper();
	void mostrarUnSuper(const SupermercadoData& s);

	// Empleados
	EmpleadoData pedirDatosEmpleado();
	void mostrarUnEmpleado(const EmpleadoData& e);
	void pedirDniEmpleado(char* dni);
};


#endif /* SRC_INTERFAZ_H_ */
