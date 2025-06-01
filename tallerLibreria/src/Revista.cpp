#include "/workspaces/Pooc-/tallerLibreria/include/Revista.h"

// Constructor
Revista::Revista(const std::string& id, const std::string& nombre, const std::string& tematica,
                 int edicion, const std::string& genero, bool disponible)
    : Libreria(nombre, genero, disponible), id(id), tematica(tematica), edicion(edicion) {}

// Método para mostrar la información de la revista
void Revista::mostrarInfo() const {
    std::cout << "[REVISTA] ID: " << id << "\n"
              << "  Nombre: " << titulo << "\n"
              << "  Temática: " << tematica << "\n"
              << "  Edición: " << edicion << "\n"
              << "  Género: " << genero << "\n"
              << "  Disponible: " << (disponible ? "Sí" : "No") << std::endl;
}
