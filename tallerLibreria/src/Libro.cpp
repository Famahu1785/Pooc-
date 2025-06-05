#include "/workspaces/Pooc-/tallerLibreria/include/Libro.h"
#include <iostream>
using namespace std;

Libro::Libro(string i, string t, string g, string a, int p) : Material(t, g){ // este constructor inicializa el material base
    isbn = i;
    autor = a;
    paginas = p;
    // Validar que el ISBN no esté vacío y que las páginas sean un número positivo
}

void Libro::mostrar() {
    cout << "LIBRO | ISBN: " << isbn 
    << " | Título: " << titulo 
    << " | Autor: " << autor 
    << " | Género: " << genero 
    << " | Páginas: " << paginas << endl;
}

string Libro::getID() {
    return isbn;
}
