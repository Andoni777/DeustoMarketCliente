/*
 * Persona.h
 *
 *  Created on: 12 may 2026
 *      Author: miguel.menendez
 */

#ifndef DOMAIN_PERSONA_H_
#define DOMAIN_PERSONA_H_



class Persona
{
protected:
	int contador_id;
	int id;
	char* dni;
	char* nombre;
	int edad;
	int id_super;

public:

	Persona();
	Persona(char* dni, char* nombre, int edad, int id_super);
	virtual ~Persona();

	int getID() const;
	char* getDni() const;
	char* getNombre() const;
	int getEdad() const;
	int getSuper() const;

	void setDni(char* nuevo_dni);
	void setNombre(char* nuevo_nombre);
	void setEdad(int edadNueva);
	void setSuper(int super_nuevo);

	virtual void visualizar() const;
};




#endif /* DOMAIN_PERSONA_H_ */
