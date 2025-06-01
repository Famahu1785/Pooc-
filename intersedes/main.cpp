#include <iostream>
#include <string>
using namespace std;


#include "Futbolista.h"
#include "Basketbolista.h"
#include "Nadador.h"


void mostrarMenu() {
    cout << "1. Crear participante" << endl;
    cout << "2. Modificar o actualizar" << endl;
    cout << "3. Mostrar el goleador (puntos)" << endl;
    cout << "4. Mostrar con más asistencias" << endl;
    cout << "5. Mostrar con más faltas" << endl;
    cout << "6. Promedio tiempo (natación)" << endl;
    cout << "7. Salir" << endl;
    cout << "Elija una opción: ";
}

int main() {
    int opcion;
    string nombre, cedula, codigo, sexo;
    int edad, programa;

    do {
        mostrarMenu();
        cin >> opcion;

        if (cin.fail() || opcion < 1 || opcion > 7) {
            cout << "Opción inválida. Intente de nuevo.\n" << endl;
            cin.clear(); // limpia error en cin
            cin.ignore(1000, '\n'); // descarta entrada inválida
        } else {
            switch (opcion) {
                case 1: {
                    int tipo;
                    cout << "Tipo de deportista:\n";
                    cout << "1. Futbolista\n2. Basketbolista\n3. Nadador\n";
                    cout << "Seleccione una opción: ";
                    cin >> tipo;
                
                    if (tipo == 1) {
                        if (!Futbolista::registrarFutbolista()) {
                            cout << "\nNo se pueden registrar más futbolistas (límite alcanzado).\n";
                        }
                    } else if (tipo == 2) {
                        Basketbolista b;
                        if (Basketbolista::registrarBasketbolista(b)) {
                            cout << "Basketbolista registrado con éxito.\n";
                        } else {
                            cout << "No se pueden registrar más basketbolistas.\n";
                        }
                    } else if (tipo == 3) {
                        Nadador n;
                        if (Nadador::registroNadador(Nadador& n)) {
                            cout << "Nadador registrado con éxito.\n";
                        } else {
                            cout << "No se pueden registrar más nadadores.\n";
                        }
                    } else {
                        cout << "Tipo inválido.\n";
                    }
                
                    break;
                }
                
                case 2: {
                    cout << "Modificar o actualizar participante" << endl;
                    string codigoBusqueda;
                    cout << "Ingrese el código del participante para modificar: ";
                    cin >> codigoBusqueda;

                    bool encontrado = false;

                    if (Futbolista::modificarFutbolista(codigoBusqueda)) {
                        cout << "Futbolista modificado con éxito.\n";
                        encontrado = true;
                    } else if (Basketbolista::modificarBasketbolistaPorCodigo(codigoBusqueda)) {
                        cout << "Basketbolista modificado con éxito.\n";
                        encontrado = true;
                    } else if (Nadador::modificarNadadorPorCodigo(codigoBusqueda)) {
                        cout << "Nadador modificado con éxito.\n";
                        encontrado = true;
                    }

                    if (!encontrado) {
                        cout << "Participante no encontrado.\n";
                    }
                    break;
                case 3: {    
                        cout << "Mostrar el que contenga más goles o puntos (futbol/basketbol)" << endl;
                    
                     
                        Futbolista* mejorFutbolista = Futbolista::obtenerMejorGoleador();
                    
                        
                        Basketbolista* mejorBasketbolista = Basketbolista::obtenerMejorAnotador();
                    
                     
                        if (mejorFutbolista) {
                            cout << "El mejor goleador en fútbol es: " << mejorFutbolista->getNombre() 
                                 << " con " << mejorFutbolista->getGolesMarcados() << " goles." << endl;
                        } else {
                            cout << "No hay futbolistas registrados para determinar el mejor goleador." << endl;
                        }
                    
                        
                        if (mejorBasketbolista) {
                            cout << "El mejor anotador en baloncesto es: " << mejorBasketbolista->getNombre() 
                                 << " con " << mejorBasketbolista->getPuntos() << " puntos." << endl;
                        } else {
                            cout << "No hay basketbolistas registrados para determinar el mejor anotador." << endl;
                        }
                    
                        break;
                    }
                    
                }
                case 4: {
                    cout << "Mostrar el participante que contenga más asistencias (futbol/basketbol)\n";
                
                    Futbolista* mejorFut = Futbolista::obtenerMejorAsistente();
                    Basketbolista* mejorBask = Basketbolista::obtenerMejorAsistente();
                
                    if (mejorFut && (!mejorBask || mejorFut->getAsistencias() > mejorBask->getAsistencias())) {
                        cout << "El futbolista con más asistencias es:\n";
                        mejorFut->mostrar(); // Asumiendo que se tenga una función mostrar()
                    } else if (mejorBask) {
                        cout << "El basketbolista con más asistencias es:\n";
                        mejorBask->mostrar(); 
                    } else {
                        cout << "No hay asistentes registrados.\n";
                    }
                    break;
                }
                
                }
                case 5: {
                    cout << "Mostrar el participante con más faltas...\n";
                
                    Futbolista* faltosoFut = Futbolista::obtenerMayorFaltas();
                    Basketbolista* faltosoBask = Basketbolista::obtenerMayorFaltas();
                
                    if (faltosoFut && (!faltosoBask || faltosoFut->getFaltas() > faltosoBask->getFaltas())) {
                        cout << "El futbolista con más faltas es:\n";
                        faltosoFut->mostrar(); // Debes tener esta función implementada
                    } else if (faltosoBask) {
                        cout << "El basketbolista con más faltas es:\n";
                        faltosoBask->mostrar();
                    } else {
                        cout << "No hay participantes registrados con faltas.\n";
                    }
                    break;
                }
                
                case 6: {
                    cout << "Calcular promedio de tiempo (natación)..." << endl;
                    float promedio = Nadador::promedioGeneralTiempos();
                    if (promedio > 0)
                        cout << "El promedio de todos los tiempos de los nadadores es: " << promedio << " segundos.\n";
                    else
                        cout << "No hay nadadores registrados.\n";
                    break;
                }
                
                case 7:
                    cout << "Saliendo del programa..." << endl;
                    break;
            }
        }
    } while (opcion != 7);

    return 0;
}

/*Los 6 futbolistas, 7 basketbolistas y 2 de natacion
1) crearlos
2) Modificarlos
3) Mostrar goleador / o con mas puntos en basket
4) Mostrar mas faltas
5) Promedio  de tiempos natacion
6) Mostrar con mas asistencias

*/
/* presentacion del proyecto 4 de junio */