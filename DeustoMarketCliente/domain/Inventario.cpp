/*
 * Inventario.cpp
 *
 * Created on: 11 may 2026
 *      Author: eneko.l.fuertes
 */

#include "Inventario.h"

// Constructor por defecto
Inventario::Inventario() {
    this->id_super = 0;
    this->id_producto = 0;
    this->stock = 0;
}

// Constructor parametrizado
Inventario::Inventario(int id_super, int id_producto, int stock) {
    this->id_super = id_super;
    this->id_producto = id_producto;
    this->stock = stock;
}

// Destructor
Inventario::~Inventario() {
}

// Getters y Setters
int Inventario::getIdSuper() const {
    return id_super;
}

void Inventario::setIdSuper(int idSuper) {
    id_super = idSuper;
}

int Inventario::getIdProducto() const {
    return id_producto;
}

void Inventario::setIdProducto(int idProducto) {
    id_producto = idProducto;
}

int Inventario::getStock() const {
    return stock;
}

void Inventario::setStock(int stock) {
    this->stock = stock;
}



