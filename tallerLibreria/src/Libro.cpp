#include "/workspaces/Pooc-/tallerLibreria/include/Libro.h"

// Constructor
Libro::Libro(const std::string& isbn, const std::string& titulo, const std::string& genero,
             const std::string& autor, int paginas, bool disponible)
    : Libreria(titulo, genero, disponible), isbn(isbn), autor(autor), paginas(paginas) {}

// Método para mostrar la información del libro
void Libro::mostrarInfo() const {
    std::cout << "[LIBRO] ISBN: " << isbn << "\n"
              << "  Título: " << titulo << "\n"
              << "  Autor: " << autor << "\n"
              << "  Género: " << genero << "\n"
              << "  Páginas: " << paginas << "\n"
              << "  Disponible: " << (disponible ? "Sí" : "No") << std::endl;
}
