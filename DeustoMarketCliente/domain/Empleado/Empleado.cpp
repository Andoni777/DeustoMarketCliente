#include "Empleado.h"
#include <iostream>
#include <string.h>

#include "..\Persona\Persona.h"

using namespace std;

	Empleado::Empleado(): Persona()
	{
		this->puesto = NULL;
		this->salario = 0;
	}

	Empleado::Empleado(char* nombre, int edad, int id_super, char* puesto, int salario): Persona(nombre, edad, id_super)
	{
		this->puesto = new char[strlen(puesto) + 1];
		strcpy(this->puesto, puesto);
		this->salario = salario;
	}

	char* Empleado::getPuesto() const
	{
		return this->puesto;
	}

	int Empleado::getSalario() const
	{
		return this->salario;
	}

	void Empleado::setPuesto(char* nuevo_puesto)
	{
		if ( this->puesto != NULL) delete [] this->puesto;
		this->puesto = new char[strlen(nuevo_puesto) + 1];
		strcpy(this->nombre, nuevo_puesto);
	}

	void Empleado::setSalario(int nuevo_salario)
	{
		this->salario = salario;
	}

	void Empleado::visualizar() const
	{
		Persona::visualizar();
		cout << "Puesto: " << this->puesto << endl;
		cout << "Salario: " << this->salario<< endl;
		cout << "==========================" << endl;
	}
