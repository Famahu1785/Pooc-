#include "/workspaces/Pooc-/tallerLibreria/include/Libro.h"
#include <iostream>
using namespace std;

Libro::Libro(string i, string t, string g, string a, int p)
    : Material(t, g), isbn(i), autor(a), paginas(p) {}

void Libro::mostrar() {
    cout << "LIBRO | ISBN: " << isbn << " | Título: " << titulo << " | Autor: " << autor
         << " | Género: " << genero << " | Páginas: " << paginas << endl;
}

string Libro::getID() {
    return isbn;
}
