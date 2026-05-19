/*
 * Producto.h
 *
 * Created on: 11 may 2026
 * Author: andoni.g
 */

#ifndef PRODUCTO_H_
#define PRODUCTO_H_
#include <string>
#include <iostream>

class Producto {

private:
	int id_producto;
	std::string nombre_producto;
	float precio_producto;
	int id_categoria;

public:
	// Constructor por defecto (Obligatorio para que funcionen los vectores del main)
	Producto();

	// Constructor con 3 parámetros (El que llama tu main.cpp en la línea 191)
	Producto(int id, const std::string& nombre, float precio);

	// Getters y Setters que necesita tu main.cpp para la caché local
	int getIdProducto() const;
	void setIdProducto(int id);

	std::string getNombreProducto() const;
	void setNombreProducto(const std::string& nombre);

	float getPrecio() const;
	void setPrecio(float precio);

	int getIdCategoria() const;
	void setIdCategoria(int idCat);
};

#endif /* PRODUCTO_H_ */
