/*
 * Interfaz.h
 *
 *  Created on: 11 may 2026
 *      Author: andoni.g
 */

#ifndef DOMAIN_INTERFAZ_H_
#define DOMAIN_INTERFAZ_H_

class Interfaz {

public:
	int leerOpcion();

	// Menu Principal
	int mostrarMenu();

	//SubMenus
	int mostrarMenuGestSuper();
	int mostrarMenuGestIyP();
	int mostrarMenuGestEmpleado();
	int mostrarLogs();



};


#endif /* DOMAIN_INTERFAZ_H_ */
