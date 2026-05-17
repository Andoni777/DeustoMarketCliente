#include "Persona.h"
#include <iostream>
#include <string.h>

using namespace std;

int contador_id = 0;

	Persona::Persona()
	{
		this->id = ++contador_id;
		this->dni = NULL;
		this->edad = 0;
		this->id_super = 0;
		this->nombre = NULL;
	}

	Persona::Persona(char* dni, char* nombre, int edad, int id_super)
	{
		this->id = ++contador_id;
		this->edad = edad;
		this->id_super = id_super;
		this->dni = new char[strlen(dni) + 1];
		strcpy(this->dni, dni);
		this->nombre = new char[strlen(nombre) + 1];
		strcpy(this->nombre, nombre);
	}

	Persona::~Persona()
	{
		if (this->nombre != NULL) delete[] this->nombre;
		if (this->dni != NULL) delete[] this->dni;
	}

	int Persona::getID() const
	{
		return this->id;
	}
	char* Persona::getDni() const {
		return this->dni;
	}
	char* Persona::getNombre() const
	{
		return this->nombre;
	}

	int Persona::getEdad() const
	{
		return this->edad;
	}

	int Persona::getSuper() const
	{
		return this->id_super;
	}

	void Persona::setDni(char* nuevo_dni) {
	    if (this->dni != NULL) delete[] this->dni;
	    this->dni = new char[strlen(nuevo_dni) + 1];
	    strcpy(this->dni, nuevo_dni);
	}

	void Persona::setNombre(char* nuevo_nombre)
	{
		if ( this->nombre != NULL) delete [] this->nombre;
			this->nombre = new char[strlen(nuevo_nombre) + 1];
			strcpy(this->nombre, nuevo_nombre);
	}

	void Persona::setEdad(int edad_nueva)
	{
		this->edad = edad_nueva;
	}

	void Persona::setSuper(int super_nuevo)
	{
		this->id_super = super_nuevo;
	}

	void Persona::visualizar() const
	{
		cout << "==========================" << endl;
		cout << "ID: " << this->id << endl;
		cout << "DNI: " << this->dni << endl;
		cout << "Nombre: " << this->nombre << endl;
		cout << "Edad: " <<this->edad << endl;
	}
