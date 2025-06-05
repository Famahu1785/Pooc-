#include "/workspaces/Pooc-/tallerLibreria/include/Revista.h"
#include <iostream>
using namespace std;

Revista::Revista(string i, string n, string t, int e) : Material(n, t) {
    id  = i; // este constructor inicializa el material base
    tematica = t;
    edicion = e;
    // Validar que el ID no esté vacío y que la edición sea un número positivo
}
void Revista::mostrar() {
    cout << "REVISTA | ID: " << id 
    << " | Nombre: " << titulo 
    << " | Temática: " << tematica
    << " | Edición: " << edicion << endl;
}

string Revista::getID() {
    return id;
}


