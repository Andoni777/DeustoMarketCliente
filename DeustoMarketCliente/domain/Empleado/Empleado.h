

#ifndef DOMAIN_EMPLEADO_H_
#define DOMAIN_EMPLEADO_H_
#include <string>
#include <iostream>

#include "..\Persona\Persona.h"

class Empleado: public Persona {

private:
	char* puesto;
	int salario;

public:
	Empleado();
	Empleado(char* nombre, int edad, int id_super, char* puesto, int salario);

	char* getPuesto() const;
	int getSalario() const;

	void setPuesto(char* nuevo_puesto);
	void setSalario(int nuevo_salario);

	virtual void visualizar() const;



};


#endif /* DOMAIN_EMPLEADO_H_ */
