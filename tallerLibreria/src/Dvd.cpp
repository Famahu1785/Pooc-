#include "/workspaces/Pooc-/tallerLibreria/include/Dvd.h"
#include <iostream>

DVD::DVD(const std::string& id, const std::string& titulo, const std::string& genero,
         const std::string& director, int duracion, bool disponible)
    : Libreria(titulo, genero, disponible), 
      id(id), 
      director(director), 
      duracion(duracion) 
{
}

void DVD::mostrarInfo() const {
    std::cout << "[DVD] ID: " << id << "\n"
              << "  Título: " << titulo << "\n"
              << "  Director: " << director << "\n"
              << "  Género: " << genero << "\n"
              << "  Duración: " << duracion << " min\n"
              << "  Disponible: " << (disponible ? "Sí" : "No") << std::endl;
}
