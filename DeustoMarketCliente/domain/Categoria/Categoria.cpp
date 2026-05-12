#include "Categoria.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int Categoria::contador_ids = 0;

	Categoria::Categoria()
	{
		this->id_categoria = ++contador_ids;
		this->nombre_categoria = NULL;
	}

	Categoria::Categoria(int id_categoria)
	{
		this->id_categoria = ++contador_ids;
		this->nombre_categoria = nombre_categoria;
	}

	int Categoria::getID() const
	{
		return this->id_categoria;
	}
	char* Categoria::getNombre() const
	{
		return this->nombre_categoria;
	}

	void Categoria::setNombre(char* nuevo_nombre)
	{
		if (this->nombre_categoria != NULL) delete[] this->nombre_categoria;

			this->nombre_categoria = new char[strlen(nuevo_nombre) + 1];
			strcpy(this->nombre_categoria, nuevo_nombre);
	}

	void Categoria::visualizar() const
	{
		cout << "[ID: " << id_categoria << " | Nombre: " << nombre_categoria << " ]" << endl;
	}


