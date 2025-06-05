#include "/workspaces/Pooc-/tallerLibreria/include/Dvd.h"
#include <iostream>
using namespace std;

Dvd::Dvd(string i, string t, string g, string d, int dur) : Material(t, g) {
    id = i;
    director = d;
    duracion = dur;
}

void Dvd::mostrar() {
    cout << "DVD | ID: " << id 
    << " | Título: " << titulo
    << " | Director: " << director 
    << " | Género: " << genero
    << " | Duración: " << duracion << " min" << endl;
}

string Dvd::getID() {
    return  id;
}
