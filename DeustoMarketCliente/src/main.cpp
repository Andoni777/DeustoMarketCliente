#include <winsock2.h>
#include <iostream>
#include <string>
#include <vector>
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

    // 1. Enviamos la operación de Login y los datos
    OpCode op = OPC_LOGIN;
    send(s, (char*)&op, sizeof(OpCode), 0);
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

    if (!verificarLoginServidor(s)) {
    	OpCode exit = OPC_EXIT;
    	send(s, (char*)&exit, sizeof(OpCode), 0);
    	closesocket(s);
    	WSACleanup();
    	return 0;
    }

    do {
        opcion = gui.mostrarMenu();
        switch(opcion) {

            case 1: { // Gestion supers
                int subOpcion = gui.mostrarMenuGestSuper();

                switch(subOpcion){

                    case 1: { // Añadir super
                        OpCode op = OPC_ADD_SUPER;
                        SupermercadoData data = gui.pedirDatosSuper();
                        send(s, (char*)&op, sizeof(OpCode), 0);
                        send(s, (char*)&data, sizeof(SupermercadoData), 0);
                        cout << "Peticion de alta enviada." << endl;

                        // Si la cache estaba cargada, añadimos el nuevo objeto localmente
                        if (datosCargados) {
                            SuperMercado nuevo(data.id_super, data.nombre, data.direccion);
                            cacheSupers.push_back(nuevo);
                        }
                        break;
                    }

                    case 2: { // Modificar super
                        OpCode op = OPC_UPDATE_SUPER;
                        SupermercadoData data = gui.pedirDatosSuper();
                        send(s, (char*)&op, sizeof(OpCode), 0);
                        send(s, (char*)&data, sizeof(SupermercadoData), 0);
                        cout << "Peticion de modificacion enviada." << endl;

                        // Modificamos localmente el objeto
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
                        OpCode op = OPC_DEL_SUPER;
                        SupermercadoData data;
                        data.id_super = gui.pedirIdSuper();
                        send(s, (char*)&op, sizeof(OpCode), 0);
                        send(s, (char*)&data, sizeof(SupermercadoData), 0);
                        cout << "Peticion de borrado enviada." << endl;

                        // OPTIMIZACIÓN: Eliminamos de nuestra lista local
                        if (datosCargados) {
                            for (auto it = cacheSupers.begin(); it != cacheSupers.end(); ++it) {
                                if (it->getIdSuper() == data.id_super) {
                                    cacheSupers.erase(it); // Se elimina del vector y el destructor de la clase libera su memoria
                                    break;
                                }
                            }
                        }
                        break;
                    }

                    case 4: { // Mostrar supers
                        // Si NO están cargados, vamos al servidor
                        if (!datosCargados) {
                            OpCode op = OPC_GET_ALL_SUPER;
                            send(s, (char*)&op, sizeof(OpCode), 0);

                            SupermercadoData recibido;
                            while(recv(s, (char*)&recibido, sizeof(SupermercadoData), 0) > 0) {
                                if(recibido.id_super == -1) break;

                                // Convertimos el STRUCT de red a OBJETO de C++
                                SuperMercado sm(recibido.id_super, recibido.nombre, recibido.direccion);
                                // Lo metemos en el vector
                                cacheSupers.push_back(sm);
                            }
                            datosCargados = true; // Ya no volveremos a pedirlo al servidor
                            cout << "\n[INFO] Datos descargados del servidor y almacenados en cache." << endl;
                        }

                        // Pintamos los datos leyendo EXCLUSIVAMENTE de la memoria RAM del Cliente
                        cout << "\n--- LISTADO DE SUPERMERCADOS (CACHE LOCAL) ---" << endl;
                        for (size_t i = 0; i < cacheSupers.size(); i++) {
                            // Convertimos el objeto de vuelta a un struct temporal para reutilizar tu funcion gui.mostrarUnSuper
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

            case 3:
                gui.mostrarMenuGestEmpleado();
                break;
        }
    } while (opcion != 0);

    OpCode exit = OPC_EXIT;
    send(s, (char*)&exit, sizeof(OpCode), 0);
    closesocket(s);
    WSACleanup();
}
