#include "Cliente.h"
#include <iostream>
#include <string.h>

#include "..\Persona\Persona.h"

using namespace std;

	Cliente::Cliente(): Persona()
	{
		this->email = NULL;
	}

	Cliente::Cliente(char* nombre, int edad, int id_super, char* email): Persona(dni, nombre, edad, id_super)
	{
		this->email = new char[strlen(email) + 1];
		strcpy(this->email, email);
	}

	char* Cliente::getEmail() const
	{
		return this->email;
	}
	void Cliente::setEmail(char* nuevo_email)
	{
		if ( this->email != NULL) delete [] this->email;
		this->nombre = new char[strlen(nuevo_email) + 1];
		strcpy(this->nombre, nuevo_email);
	}

	void Cliente::visualizar() const
	{
		Persona::visualizar();
		cout << "Email: " << this->email << endl;
		cout << "==========================" << endl;

	}

