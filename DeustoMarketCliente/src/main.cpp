#include <winsock2.h>
#include <iostream>
#include <string>
#include <vector>
#include "../domain/Empleado/Empleado.h"
#include "../domain/SuperMercado/Supermercado.h"
#include "../domain/Protocolo.h"
#include "Interfaz.h"
using namespace std;

bool verificarLoginServidor(SOCKET s) {
    LoginData datos;
    cout << "=== LOGIN DEUSTOMARKET ===" << endl;
    cout << "Usuario: ";
    cin >> datos.usuario;
    cout << "Contrasena: ";
    cin >> datos.contrasena;

    // 1. Enviamos la operación de Login y los datos utilizando un entero estándar (4 bytes)
    int op = (int)OPC_LOGIN;
    send(s, (char*)&op, sizeof(int), 0);
    send(s, (char*)&datos, sizeof(LoginData), 0);

    // 2. Esperamos la respuesta del servidor (un simple int: 1 = OK, 0 = Error)
    int respuesta = 0;
    recv(s, (char*)&respuesta, sizeof(int), 0);

    if (respuesta == 1) {
        cout << "\n¡Login correcto! Bienvenido." << endl;
        return true;
    } else {
        cout << "\n[ERROR] Usuario o contrasena incorrectos." << endl;
        return false;
    }
}

int main(int argc, char **argv) {
    Interfaz gui;
    int opcion;

    // Variables para optimizar accesos a la BDD (Cache local)
    vector<SuperMercado> cacheSupers;
    bool datosCargados = false; // Nos dice si ya hemos descargado los datos alguna vez

    vector<Empleado> cacheEmpleados;
    bool datosEmpleadosCargados = false;

    WSADATA wsaData;
    SOCKET s;
    struct sockaddr_in server;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cout << "Error en WSAStartup" << endl;
        return -1;
    }

    s = socket(AF_INET, SOCK_STREAM, 0);
    if (s == INVALID_SOCKET) {
        cout << "No se pudo crear el socket" << endl;
        WSACleanup();
        return -1;
    }

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(6000);

    if (connect(s, (struct sockaddr*)&server, sizeof(server)) < 0) {
        cout << "Error de conexion. ¿Esta el servidor encendido?" << endl;
        closesocket(s);
        WSACleanup();
        return -1;
    }

    cout << "Conectado al servidor de DeustoMarket!" << endl;

    while (!verificarLoginServidor(s)) {
        cout << "Inténtalo de nuevo.\n" << endl;
    }

    do {
        opcion = gui.mostrarMenu();
        switch(opcion) {

            case 1: { // Gestion supers
                int subOpcion = gui.mostrarMenuGestSuper();

                switch(subOpcion){

                    case 1: { // Añadir super
                        int op = (int)OPC_ADD_SUPER;
                        SupermercadoData data = gui.pedirDatosSuper();
                        send(s, (char*)&op, sizeof(int), 0);
                        send(s, (char*)&data, sizeof(SupermercadoData), 0);
                        cout << "Peticion de alta enviada." << endl;

                        if (datosCargados) {
                            SuperMercado nuevo(data.id_super, data.nombre, data.direccion);
                            cacheSupers.push_back(nuevo);
                        }
                        break;
                    }

                    case 2: { // Modificar super
                        int op = (int)OPC_UPDATE_SUPER;
                        SupermercadoData data = gui.pedirDatosSuper();
                        send(s, (char*)&op, sizeof(int), 0);
                        send(s, (char*)&data, sizeof(SupermercadoData), 0);
                        cout << "Peticion de modificacion enviada." << endl;

                        if (datosCargados) {
                            for (size_t i = 0; i < cacheSupers.size(); i++) {
                                if (cacheSupers[i].getIdSuper() == data.id_super) {
                                    cacheSupers[i].setNombreSuper(data.nombre);
                                    cacheSupers[i].setDireccion(data.direccion);
                                    break;
                                }
                            }
                        }
                        break;
                    }

                    case 3: { // Eliminar super
                        int op = (int)OPC_DEL_SUPER;
                        SupermercadoData data;
                        data.id_super = gui.pedirIdSuper();
                        send(s, (char*)&op, sizeof(int), 0);
                        send(s, (char*)&data, sizeof(SupermercadoData), 0);
                        cout << "Peticion de borrado enviada." << endl;

                        if (datosCargados) {
                            for (auto it = cacheSupers.begin(); it != cacheSupers.end(); ++it) {
                                if (it->getIdSuper() == data.id_super) {
                                    cacheSupers.erase(it);
                                    break;
                                }
                            }
                        }
                        break;
                    }

                    case 4: { // Mostrar supers
                    	if (!datosCargados) {
                    	    int opEnviar = (int)OPC_GET_ALL_SUPER;
                    	    send(s, (char*)&opEnviar, sizeof(int), 0);

                    	    SupermercadoData recibido;
                    	    while(recv(s, (char*)&recibido, sizeof(SupermercadoData), 0) > 0) {
                    	        if(recibido.id_super == -1) break;

                    	        SuperMercado sm(recibido.id_super, recibido.nombre, recibido.direccion);
                    	        cacheSupers.push_back(sm);
                    	    }
                    	    datosCargados = true;
                    	    cout << "\n[INFO] Datos descargados del servidor y almacenados en cache." << endl;
                    	}

                        cout << "\n--- LISTADO DE SUPERMERCADOS (CACHE LOCAL) ---" << endl;
                        for (size_t i = 0; i < cacheSupers.size(); i++) {
                            SupermercadoData temp;
                            temp.id_super = cacheSupers[i].getIdSuper();
                            strcpy(temp.nombre, cacheSupers[i].getNombreSuper());
                            strcpy(temp.direccion, cacheSupers[i].getDireccion());

                            gui.mostrarUnSuper(temp);
                        }
                        break;
                    }
                }
                break;
            }
            case 2:
                gui.mostrarMenuGestIyP();
                break;

            case 3: { // Gestion empleados
            	int subOpcion = gui.mostrarMenuGestEmpleado();

            	switch(subOpcion){
            		case 1: { // Añadir empleado
            			int op = (int)OPC_ADD_EMPLEADO;
            			EmpleadoData data = gui.pedirDatosEmpleado();
            			send(s, (char*)&op, sizeof(int), 0);
            			send(s, (char*)&data, sizeof(EmpleadoData), 0);
            			cout << "Peticion de alta enviada al servidor." << endl;
            			if (datosEmpleadosCargados) {
            			    Empleado nuevoEmp(data.dni_empleado, data.nombre_empleado, 0, data.id_super, data.puesto, 0);
            			    cacheEmpleados.push_back(nuevoEmp);
            			}
            			break;
            		}

            		case 2: { // Eliminar empleado
            			int op = (int)OPC_DEL_EMPLEADO;
            			EmpleadoData data;
            		    gui.pedirDniEmpleado(data.dni_empleado);
            		    send(s, (char*)&op, sizeof(int), 0);
            		    send(s, (char*)&data, sizeof(EmpleadoData), 0);
            		    cout << "Peticion de baja enviada al servidor." << endl;
            		    if (datosEmpleadosCargados) {
            		    	for (auto it = cacheEmpleados.begin(); it != cacheEmpleados.end(); ++it) {
            		    		if (strcmp(it->getDni(), data.dni_empleado) == 0) {
            		    			cacheEmpleados.erase(it);
            		    			break;
            		    		}
            		    	}
            		    }
            		    break;
            		}
            		case 3: { // Modificar empleado
            			int op = (int)OPC_UPDATE_EMPLEADO;
            			cout << "\n--- Modificando Empleado ---" << endl;
            			cout << "NOTA: Introduce el DNI del empleado que quieres modificar, y luego sus nuevos datos." << endl;

            			EmpleadoData data = gui.pedirDatosEmpleado();

            			send(s, (char*)&op, sizeof(int), 0);
            			send(s, (char*)&data, sizeof(EmpleadoData), 0);
            			cout << "Peticion de modificacion enviada al servidor." << endl;

            			if (datosEmpleadosCargados) {
            				for (size_t i = 0; i < cacheEmpleados.size(); i++) {
            					if (strcmp(cacheEmpleados[i].getDni(), data.dni_empleado) == 0) {
            						cacheEmpleados[i].setNombre(data.nombre_empleado);
            						cacheEmpleados[i].setPuesto(data.puesto);
            						cacheEmpleados[i].setSuper(data.id_super);
            						break;
            					}
            				}
            			}
            			break;
            		}
            		case 4: { // Mostrar todos los empleados
            			if (!datosEmpleadosCargados) {
            				int op = (int)OPC_GET_ALL_EMPLEADO;
            				send(s, (char*)&op, sizeof(int), 0);

            				EmpleadoData recibido;
            				while(recv(s, (char*)&recibido, sizeof(EmpleadoData), 0) > 0) {
            					if (strcmp(recibido.dni_empleado, "FIN") == 0) break;

            					Empleado emp(recibido.dni_empleado, recibido.nombre_empleado, 0, recibido.id_super, recibido.puesto, 0);
            					cacheEmpleados.push_back(emp);
            					}
            				datosEmpleadosCargados = true;
            				cout << "\n[INFO] Datos de empleados descargados del servidor y almacenados en cache." << endl;
            			}

            			cout << "\n--- LISTADO DE EMPLEADOS (CACHE LOCAL) ---" << endl;
            			for (size_t i = 0; i < cacheEmpleados.size(); i++) {
            				EmpleadoData temp;
            				strcpy(temp.dni_empleado, cacheEmpleados[i].getDni());
            				strcpy(temp.nombre_empleado, cacheEmpleados[i].getNombre());
            				strcpy(temp.puesto, cacheEmpleados[i].getPuesto());
            				temp.id_super = cacheEmpleados[i].getSuper();
            				gui.mostrarUnEmpleado(temp);
            			}
            			break;
            		}
            		case 5: { // Mostrar empleados de un supermercado
            			if (!datosEmpleadosCargados) {
            				cout << "\n[AVISO] Primero debes cargar la lista de empleados (Entra en la Opcion 4)." << endl;
            				break;
            			}

            			int idBuscado = gui.pedirIdSuper();
            			cout << "\n--- EMPLEADOS DEL SUPERMERCADO " << idBuscado << " ---" << endl;

            			bool encontrado = false;
            			for (size_t i = 0; i < cacheEmpleados.size(); i++) {
            				if (cacheEmpleados[i].getSuper() == idBuscado) {
            					EmpleadoData temp;
            					strcpy(temp.dni_empleado, cacheEmpleados[i].getDni());
            					strcpy(temp.nombre_empleado, cacheEmpleados[i].getNombre());
            					strcpy(temp.puesto, cacheEmpleados[i].getPuesto());
            					temp.id_super = cacheEmpleados[i].getSuper();
            					gui.mostrarUnEmpleado(temp);
            					encontrado = true;
            				}
            			}
            			if (!encontrado) cout << "No hay empleados registrados en este supermercado." << endl;
            			break;
            		}
            	}
            	break;
            }
        }
    } while (opcion != 0);

    int exit = (int)OPC_EXIT;
    send(s, (char*)&exit, sizeof(int), 0);
    closesocket(s);
    WSACleanup();
}
