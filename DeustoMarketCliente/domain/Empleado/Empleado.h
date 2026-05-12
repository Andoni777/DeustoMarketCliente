/*
 * Empleado.h
 *
 *  Created on: 11 may 2026
 *      Author: andoni.g
 */

#ifndef DOMAIN_EMPLEADO_H_
#define DOMAIN_EMPLEADO_H_
#include <string>
#include <iostream>

#include "..\Persona\Persona.h"

class Empleado: public Persona {

private:
	char* puesto;
	int salario;



};


#endif /* DOMAIN_EMPLEADO_H_ */
