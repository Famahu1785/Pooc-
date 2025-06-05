#include "/workspaces/Pooc-/tallerLibreria/include/Usuario.h"
#include <iostream>
using namespace std;

Usuario::Usuario(string n) : nombre(n) {}

bool Usuario::prestar(Material* m) {
    if (cantidadPrestamos() >= 3 || !m->estaDisponible())
        return false;
    prestamos.push_back(m);
    m->setDisponible(false);
    return true;
}

// Ahora devuelve bool: true si se devolvió, false si no lo tenía
bool Usuario::devolver(string id) {
    for (auto it = prestamos.begin(); it != prestamos.end(); ++it) {
        if ((*it)->getID() == id) {
            (*it)->setDisponible(true);
            prestamos.erase(it);
            return true;
        }
    }
    return false;
}

void Usuario::mostrarPrestamos() {
    cout << "Préstamos de " << nombre << ":\n";
    for (auto m : prestamos)
        m->mostrar();
}

int Usuario::cantidadPrestamos() const {
    return prestamos.size();
}

string Usuario::getNombre() const {
    return nombre;
}
