#include <iostream>

#include "Animal.h"
#include "Gato.h"
#include "Perro.h"


using namespace std;
int main(){
    vector< Animal*> animales;
    int opcion;
    do {
        cout << "1. Crear Gato\n2. Crear Perro\n3. Mostrar Animales\n4. Salir\nElija una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string nombre, raza;
                cout << "Ingrese el nombre del gato: ";
                cin >> nombre;
                cout << "Ingrese la raza del gato: ";
                cin >> raza;
                animales.push_back(new Gato(nombre, raza));
                break;
            }
            case 2: {
                string nombre, raza;
                cout << "Ingrese el nombre del perro: ";
                cin >> nombre;
                cout << "Ingrese la raza del perro: ";
                cin >> raza;
                animales.push_back(new Perro(nombre, raza));
                break;
            }
            case 3: {
                for (Animal* animal : animales) {
                    animal->hacerSonido();
                    animal->mostrarInfo();
                }
                break;
            }
            case 4:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción inválida." << endl;
        }
    } while (opcion != 4);
    
}