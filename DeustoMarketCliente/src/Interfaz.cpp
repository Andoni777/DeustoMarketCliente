/*
 * Interfaz.cpp
 *
 * Created on: 11 may 2026
 * Author: andoni.g
 */

#include "Interfaz.h"

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

Interfaz::Interfaz() {
}

int Interfaz::leerOpcion(){
	int seleccion;
	std::cin >> seleccion;
	return seleccion;
}

int Interfaz::mostrarMenuGestSuper(){
	std::cout << "\n =================================================";
	std::cout << "\n       DEUSTOMARKET - GESTION DE SUPERMERCADOS     ";
	std::cout << "\n =================================================";
	std::cout << "\n 1. Anadir nuevo supermercado";
	std::cout << "\n 2. Modificar supermercado existente";
	std::cout << "\n 3. Eliminar supermercado";
	std::cout << "\n 4. Mostrar lista de supermercados";
	std::cout << "\n 0. Salir al menu principal";
	std::cout << "\n =================================================";
	std::cout << "\n\nIntroduce el numero de tu seleccion: ";

	return leerOpcion();
}

int Interfaz::mostrarMenuGestIyP(){
	std::cout << "\n =====================================================";
	std::cout << "\n       DEUSTOMARKET - GESTION DE INVENTARIO/PRODUCTOS ";
	std::cout << "\n =====================================================";
	std::cout << "\n 1. Anadir nuevo producto al catalogo";
	std::cout << "\n 2. Eliminar producto";
	std::cout << "\n 3. Modificar precio de producto";
	std::cout << "\n 4. Actualizar stock de un supermercado";
	std::cout << "\n 5. Mostrar stock de supermercados";
	std::cout << "\n 0. Salir al menu principal";
	std::cout << "\n =====================================================";
	std::cout << "\n\nIntroduce el numero de tu seleccion: ";

	return leerOpcion();
	}

int Interfaz::mostrarMenuGestEmpleado(){
	std::cout << "\n =========================================";
	std::cout << "\n       DEUSTOMARKET - GESTION DE PERSONAL  ";
	std::cout << "\n =========================================";
	std::cout << "\n 1. Dar de alta nuevo empleado";
	std::cout << "\n 2. Dar de baja (eliminar) empleado";
    std::cout << "\n 3. Modificar datos de empleado";
    std::cout << "\n 4. Mostrar lista de todos los empleados";
    std::cout << "\n 5. Mostrar lista de empleados de un supermercado especifico";
    std::cout << "\n 0. Salir al menu principal";
    std::cout << "\n =========================================";
    std::cout << "\n\nIntroduce el numero de tu seleccion: ";

	return leerOpcion();
}

int Interfaz::mostrarMenu(){
	std::cout << "\n ==========================================";
	std::cout << "\n       DEUSTOMARKET - PANEL DE CONTROL     ";
	std::cout << "\n ==========================================";
	std::cout << "\n1. Gestion de Supermercados";
	std::cout << "\n2. Gestion de Inventario y Productos";
	std::cout << "\n3. Gestion de Empleados";
	std::cout << "\n4. Ver Logs del Sistema";
	std::cout << "\n0. Salir";
	std::cout << "\n\nIntroduce el numero de tu seleccion: ";

	return leerOpcion();
}

// Funciones auxiliares

//Supers

SupermercadoData Interfaz::pedirDatosSuper(){
	SupermercadoData nuevo;
	string temp;

	cout << "\n--- INTRODUCIR DATOS DEL SUPERMERCADO ---" << endl;

	cout << "ID del Supermercado (numero): ";
	cin >> nuevo.id_super;

	// Limpiar el buffer del cin por si acaso
	cin.ignore(1000, '\n');

	cout << "Nombre: ";
	getline(cin, temp);
	strncpy(nuevo.nombre, temp.c_str(), sizeof(nuevo.nombre) - 1);
	nuevo.nombre[sizeof(nuevo.nombre) - 1] = '\0'; // Aseguramos el cierre del string

	cout << "Direccion: ";
	getline(cin, temp);
	strncpy(nuevo.direccion, temp.c_str(), sizeof(nuevo.direccion) - 1);
	nuevo.direccion[sizeof(nuevo.direccion) - 1] = '\0';

	return nuevo;
}

int Interfaz::pedirIdSuper(){
	int id;
	cout << "Introduce el ID del supermercado: ";
	cin >> id;
	return id;
}


void Interfaz::mostrarUnSuper(const SupermercadoData& d){
	cout << "-------------------------------------------" << endl;
	cout << "  ID:        " << d.id_super << endl;
	cout << "  NOMBRE:    " << d.nombre << endl;
	cout << "  DIRECCION: " << d.direccion << endl;

}

EmpleadoData Interfaz::pedirDatosEmpleado() {
    EmpleadoData nuevo;
    string temp;

    cout << "\n--- INTRODUCIR DATOS DEL EMPLEADO ---" << endl;

    cout << "DNI: ";
    cin >> nuevo.dni_empleado;
    cin.ignore(1000, '\n'); // Limpiamos el buffer tras usar cin

    cout << "Nombre: ";
    getline(cin, temp);
    strncpy(nuevo.nombre_empleado, temp.c_str(), sizeof(nuevo.nombre_empleado) - 1);
    nuevo.nombre_empleado[sizeof(nuevo.nombre_empleado) - 1] = '\0';

    cout << "Puesto: ";
    getline(cin, temp);
    strncpy(nuevo.puesto, temp.c_str(), sizeof(nuevo.puesto) - 1);
    nuevo.puesto[sizeof(nuevo.puesto) - 1] = '\0';

    cout << "ID del Supermercado asignado: ";
    cin >> nuevo.id_super;

    return nuevo;
}

void Interfaz::pedirDniEmpleado(char* dni) {
    cout << "Introduce el DNI del empleado: ";
    cin >> dni;
    cin.ignore(1000, '\n');
}

void Interfaz::mostrarUnEmpleado(const EmpleadoData& e) {
    cout << "-------------------------------------------" << endl;
    cout << "  DNI:       " << e.dni_empleado << endl;
    cout << "  NOMBRE:    " << e.nombre_empleado << endl;
    cout << "  PUESTO:    " << e.puesto << endl;
    cout << "  ID SUPER:  " << e.id_super << endl;
}
