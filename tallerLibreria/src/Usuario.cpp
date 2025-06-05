#include "/workspaces/Pooc-/tallerLibreria/include/Usuario.h"
#include <iostream>
using namespace std;

// el .size  se utiliza para obtener el tamaño del vector

Usuario::Usuario(string n) {
    nombre = n; // Constructor que inicializa el nombre del usuario
}

bool Usuario::prestar(Material* m) {
    if (cantidadPrestamos() >= 3 || !m->estaDisponible())
        return false;
    prestamos.push_back(m);
    m->setDisponible(false);
    return true;
}


bool Usuario::devolver(string id) {
    for (auto it = prestamos.begin(); it != prestamos.end(); ++it) {
        if ((*it)->getID() == id) { // el *it se usa para acceder al objeto Material apuntado
            (*it)->setDisponible(true); // marcar el material como disponible
            prestamos.erase(it); // eliminar el préstamo de la lista
            return true;
        }
    }
    return false;
}

void Usuario::mostrarPrestamos() {
    cout << "Préstamos de " << nombre << ":\n";
    for (unsigned int i = 0; i < prestamos.size(); i++){ // el usamos unsigned int para evitar problemas con el tamaño del vector
        prestamos[i]-> mostrar(); // Llamar al método mostrar de cada material prestado
    }
}

int Usuario::cantidadPrestamos() const { // aqui el const se utiliza para indicar que no se modificará el objeto
    // Devuelve la cantidad de préstamos actuales del usuario
    return prestamos.size();
}

string Usuario::getNombre() const { // Método para obtener el nombre del usuario
    // el const se utiliza para indicar que no se modificará el objeto
    return nombre;
}
