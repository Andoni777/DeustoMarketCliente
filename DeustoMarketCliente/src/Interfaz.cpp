/*
 * Interfaz.cpp
 *
 *  Created on: 11 may 2026
 *      Author: andoni.g
 */

#include "../domain/Interfaz.h"
#include <iostream>

int Interfaz::leerOpcion(){
	int seleccion;
	std::cin >> seleccion;
	return seleccion;
}

int Interfaz::mostrarMenuGestSuper(){
	std::cout << "\n =================================================";
	std::cout << "\n       DEUSTOMARKET - GESTIÓN DE SUPERMERCADOS     ";
	std::cout << "\n =================================================";
	std::cout << "\n 1. Añadir nuevo supermercado";
	std::cout << "\n 2. Modificar supermercado existente";
	std::cout << "\n 3. Eliminar supermercado";
	std::cout << "\n 4. Mostrar lista de supermercados";
	std::cout << "\n 0. Salir al menú principal";
	std::cout << "\n =================================================";
	std::cout << "\n\nIntroduce el número de tu selección: ";

	return leerOpcion();
}

int Interfaz::mostrarMenuGestIyP(){
	std::cout << "\n =====================================================";
	std::cout << "\n       DEUSTOMARKET - GESTIÓN DE INVENTARIO/PRODUCTOS ";
	std::cout << "\n =====================================================";
	std::cout << "\n 1. Añadir nuevo producto al catálogo";
	std::cout << "\n 2. Eliminar producto";
	std::cout << "\n 3. Modificar precio de producto";
	std::cout << "\n 4. Actualizar stock de un supermercado";
	std::cout << "\n 5. Mostrar stock de supermercados";
	std::cout << "\n 0. Salir al menú principal";
	std::cout << "\n =====================================================";
	std::cout << "\n\nIntroduce el número de tu selección: ";

	return leerOpcion();
	}

int Interfaz::mostrarMenuGestEmpleado(){
	std::cout << "\n =========================================";
	std::cout << "\n       DEUSTOMARKET - GESTIÓN DE PERSONAL  ";
	std::cout << "\n =========================================";
	std::cout << "\n 1. Dar de alta nuevo empleado";
	std::cout << "\n 2. Dar de baja (eliminar) empleado";
    std::cout << "\n 3. Modificar datos de empleado";
    std::cout << "\n 4. Mostrar lista de todos los empleados";
    std::cout << "\n 5. Mostrar lista de empleados de un supermercado específico";
    std::cout << "\n 0. Salir al menú principal";
    std::cout << "\n =========================================";
    std::cout << "\n\nIntroduce el número de tu selección: ";

	return leerOpcion();
}

int Interfaz::mostrarMenu(){
	std::cout << "\n ==========================================";
	std::cout << "\n       DEUSTOMARKET - PANEL DE CONTROL     ";
	std::cout << "\n ==========================================";
	std::cout << "\n1. Gestión de Supermercados";
	std::cout << "\n2. Gestión de Inventario y Productos";
	std::cout << "\n3. Gestión de Empleados";
	std::cout << "\n4. Ver Logs del Sistema";
	std::cout << "\n0. Salir";
	std::cout << "\n\nIntroduce el numero de tu selección: ";

	return leerOpcion();
}





