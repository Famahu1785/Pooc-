#include "/workspaces/Pooc-/tallerLibreria/include/Libreria.h"

// Constructor
Libreria::Libreria(const std::string& titulo, const std::string& genero, bool disponible)
    : titulo(titulo), genero(genero), disponible(disponible) {}

// Destructor
Libreria::~Libreria() {}

// Métodos
bool Libreria::getDisponible() const {
    return disponible;
}

void Libreria::setDisponible(bool estado) {
    disponible = estado;
}

std::string Libreria::getTitulo() const {
    return titulo;
}

std::string Libreria::getGenero() const {
    return genero;
}
