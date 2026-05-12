/*
 * Categoria.h
 *
 *  Created on: 11 may 2026
 *      Author: andoni.g
 */

#ifndef DOMAIN_CATEGORIA_H_
#define DOMAIN_CATEGORIA_H_
#include <string>
#include <iostream>
class Categoria {

private:
	static int contador_ids;
	int id_categoria;
	char* nombre_categoria;

public:

	Categoria();
	Categoria(int id_categoria);

	int getID() const;
	char* getNombre() const;

	void setNombre(char* nuevo_nombre);

	void visualizar() const;


};

#endif /* DOMAIN_CATEGORIA_H_ */
