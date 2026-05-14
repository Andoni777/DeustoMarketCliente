/*
 * Cliente.h
 *
 *  Created on: 11 may 2026
 *      Author: andoni.g
 */

#ifndef DOMAIN_CLIENTE_H_
#define DOMAIN_CLIENTE_H_
#include <string>
#include <iostream>

#include "..\Persona\Persona.h"

class Cliente: public Persona {

private:
	char* email;

public:
	Cliente();
	Cliente(char* nombre, int edad, int id_super, char* email);

	char* getEmail() const;
	void setEmail(char* nuevo_email);

	virtual void visualizar() const;




};


#endif /* DOMAIN_CLIENTE_H_ */
