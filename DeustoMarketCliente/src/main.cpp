/*
 * main.cpp
 *
 *  Created on: 11 may 2026
 *      Author: andoni.g
 */
#include "../domain/Interfaz.h"
#include <iostream>
int main(int argc, char **argv) {
	Interfaz gui;
	int opcion;

	do {
	    opcion = gui.mostrarMenu(); // Recibimos la opción
	    switch(opcion) {
	    	case 1: {
	    			gui.mostrarMenuGestSuper();
	                break;
	            }
	            case 2:
	                gui.mostrarMenuGestIyP();
	                break;
	            case 3:
	            	gui.mostrarMenuGestEmpleado();

	        }
	    } while (opcion != 0);

	    return 0;
	}




