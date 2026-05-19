/*
 * Producto.cpp
 *
 *  Created on: 19 may 2026
 *      Author: eneko.l.fuertes
 */
#include "Producto.h"
#include <cstring>

// Constructor por defecto: Inicializa los atributos con valores seguros
Producto::Producto() {
	this->id_producto = 0;
	this->nombre_producto = "";
	this->precio_producto = 0.0f;
	this->id_categoria = 0;
}

// Constructor con 3 parámetros: El que está llamando tu main.cpp
Producto::Producto(int id, const std::string& nombre, float precio) {
	this->id_producto = id;
	this->nombre_producto = nombre;
	this->precio_producto = precio;
	this->id_categoria = 0; // Se le asigna un valor por defecto inicial
}

// Retorna el ID numérico del producto
int Producto::getIdProducto() const {
	return this->id_producto;
}

// Modifica el ID del producto
void Producto::setIdProducto(int id) {
	this->id_producto = id;
}

// Retorna el nombre en formato std::string
std::string Producto::getNombreProducto() const {
	return this->nombre_producto;
}

// Modifica el nombre del producto
void Producto::setNombreProducto(const std::string& nombre) {
	this->nombre_producto = nombre;
}

// Retorna el precio flotante
float Producto::getPrecio() const {
	return this->precio_producto;
}

// Modifica el precio (usado en el caso 3 del menú de inventario)
void Producto::setPrecio(float precio) {
	this->precio_producto = precio;
}

// Retorna el ID de la categoría asociada
int Producto::getIdCategoria() const {
	return this->id_categoria;
}

// Modifica la categoría del producto
void Producto::setIdCategoria(int idCat) {
	this->id_categoria = idCat;
}



