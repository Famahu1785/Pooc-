#include "/workspaces/Pooc-/tallerLibreria/include/Revista.h"
#include <iostream>
using namespace std;

Revista::Revista(string i, string n, string t, int e)
    : Material(n, t), id(i), tematica(t), edicion(e) {}

void Revista::mostrar() {
    cout << "REVISTA | ID: " << id << " | Nombre: " << titulo << " | Temática: " << tematica
         << " | Edición: " << edicion << endl;
}

string Revista::getID() {
    return id;
}


