#include "Supermercado.h"
#include <cstring>

// 1. Constructor por defecto
SuperMercado::SuperMercado() {
    this->id_super = 0;
    this->nombre_super = new char[1];
    this->nombre_super[0] = '\0';
    this->direccion = new char[1];
    this->direccion[0] = '\0';
}

// 2. Constructor con parámetros
SuperMercado::SuperMercado(int id_super, const char* nombre_super, const char* direccion) {
    this->id_super = id_super;

    // Reservar memoria exacta + 1 para el carácter nulo '\0'
    this->nombre_super = new char[strlen(nombre_super) + 1];
    strcpy(this->nombre_super, nombre_super);

    this->direccion = new char[strlen(direccion) + 1];
    strcpy(this->direccion, direccion);
}

// 3. Constructor copia
SuperMercado::SuperMercado(const SuperMercado& otro) {
    this->id_super = otro.id_super;

    this->nombre_super = new char[strlen(otro.nombre_super) + 1];
    strcpy(this->nombre_super, otro.nombre_super);

    this->direccion = new char[strlen(otro.direccion) + 1];
    strcpy(this->direccion, otro.direccion);
}

// 4. Destructor
SuperMercado::~SuperMercado() {
    delete[] this->nombre_super;
    delete[] this->direccion;
}

// --- GETTERS ---
int SuperMercado::getIdSuper() const {
    return this->id_super;
}

const char* SuperMercado::getNombreSuper() const {
    return this->nombre_super;
}

const char* SuperMercado::getDireccion() const {
    return this->direccion;
}

// --- SETTERS ---
void SuperMercado::setIdSuper(int id_super) {
    this->id_super = id_super;
}

void SuperMercado::setNombreSuper(const char* nuevo_nombre) {
    delete[] this->nombre_super;

    this->nombre_super = new char[strlen(nuevo_nombre) + 1];
    strcpy(this->nombre_super, nuevo_nombre);
}

void SuperMercado::setDireccion(const char* nueva_direccion) {
    delete[] this->direccion;

    this->direccion = new char[strlen(nueva_direccion) + 1];
    strcpy(this->direccion, nueva_direccion);
}
