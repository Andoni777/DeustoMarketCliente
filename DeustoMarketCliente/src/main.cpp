#include <winsock2.h>
#include <iostream>
#include <string>
#include "Protocolo.h"
#include "../domain/Interfaz.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv) {
	Interfaz gui;
	int opcion;

	WSADATA wsaData;
	SOCKET s;
	struct sockaddr_in server;

	// 1. Inicializar Winsock
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		cout << "Error en WSAStartup" << endl;
		return -1;
	}

	// 2. Crear el socket
	s = socket(AF_INET, SOCK_STREAM, 0);
	if (s == INVALID_SOCKET) {
		cout << "No se pudo crear el socket" << endl;
		WSACleanup();
		return -1;
	}

	// 3. Configurar la dirección del servidor
	server.sin_addr.s_addr = inet_addr("127.0.0.1"); // IP local (el mismo PC)
	server.sin_family = AF_INET;
	server.sin_port = htons(6000); // El mismo puerto que el servidor

	// 4. Conectar
	if (connect(s, (struct sockaddr*)&server, sizeof(server)) < 0) {
		cout << "Error de conexion. ¿Esta el servidor encendido?" << endl;
		closesocket(s);
		WSACleanup();
		return -1;
	}

	cout << "Conectado al servidor de DeustoMarket!" << endl;

	do {
	    opcion = gui.mostrarMenu(); // Recibimos la opción
	    switch(opcion) {

	    	case 1: { // Gestion supers
	    			int subOpcion = gui.mostrarMenuGestSuper();

	    			switch(subOpcion){

	    				case 1: {// Añadir super
	    					OpCode op = OPC_ADD_SUPER;
							SupermercadoData data = gui.pedirDatosSuper(); // Interfaz pide datos al usuario
							send(s, (char*)&op, sizeof(OpCode), 0);
							send(s, (char*)&data, sizeof(SupermercadoData), 0);
							cout << "Peticion de alta enviada." << endl;
							break;
	    				}

	    				case 2: { // Modificar super
	    					OpCode op = OPC_UPDATE_SUPER;
	    					SupermercadoData data = gui.pedirDatosSuper(); // Pedimos los nuevos datos
	    					send(s, (char*)&op, sizeof(OpCode), 0);
							send(s, (char*)&data, sizeof(SupermercadoData), 0);
							break;
	    				}

	    				case 3: { // Eliminar super
	    					OpCode op = OPC_DEL_SUPER;
	    					SupermercadoData data;
							data.id_super = gui.pedirIdSuper(); // Solo necesitamos el ID para borrar
							send(s, (char*)&op, sizeof(OpCode), 0);
							send(s, (char*)&data, sizeof(SupermercadoData), 0);
							break;
	    				}

	    				case 4: {// Mostrar supers
	    					OpCode op = OPC_GET_ALL_SUPER;
							send(s, (char*)&op, sizeof(OpCode), 0);

							SupermercadoData recibido;
							cout << "\n--- LISTADO DE SUPERMERCADOS ---" << endl;

							// El cliente esta em escucha hasta recibir id = -1
							while(recv(s, (char*)&recibido, sizeof(SupermercadoData), 0) > 0) {
								if(recibido.id_super == -1) break; // Señal de fin enviada por el server
								gui.mostrarUnSuper(recibido);
							}
							break;
	    				}
	    			}
	                break;

	            }
	    	case 2:
	    		 	 gui.mostrarMenuGestIyP();
	    		 	 break;

	        case 3:
	             	 gui.mostrarMenuGestEmpleado();

	        }
	    } while (opcion != 0);

		OpCode exit = OPC_EXIT;
		send(s, (char*)&exit, sizeof(OpCode), 0);
		closesocket(s);
	    WSACleanup();
	}




