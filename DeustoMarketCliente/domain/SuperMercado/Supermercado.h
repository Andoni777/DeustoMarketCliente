/*
 * Supermercado.h
 *
 * Created on: 16 may 2026
 * Author: andoni.g
 */

#ifndef DOMAIN_SUPERMERCADO_SUPERMERCADO_H_
#define DOMAIN_SUPERMERCADO_SUPERMERCADO_H_

#include <iostream>

class SuperMercado {
private:
    int id_super;
    char* nombre_super;
    char* direccion;

public:
    // Constructores y Destructor
    SuperMercado(); // Constructor por defecto
    SuperMercado(int id_super, const char* nombre_super, const char* direccion); // Constructor con parámetros
    SuperMercado(const SuperMercado& otro); // Constructor de copia (Vital para pasar objetos a vectores)
    ~SuperMercado(); // Destructor para liberar la memoria dinámica

    // Getters
    int getIdSuper() const;
    const char* getNombreSuper() const;
    const char* getDireccion() const;

    // Setters
    void setIdSuper(int id_super);
    void setNombreSuper(const char* nombre_super);
    void setDireccion(const char* direccion);
};

#endif /* DOMAIN_SUPERMERCADO_SUPERMERCADO_H_ */
