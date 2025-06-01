#ifndef LIBRO_H
#define LIBRO_H

#include "Libreria.h"
#include <string>
#include <iostream>

// Clase que representa un libro en la librería
class Libro : public Libreria {
private:
    std::string isbn;
    std::string autor;
    int paginas;

public:
    // Constructor
    Libro(const std::string& isbn, const std::string& titulo, const std::string& genero,
          const std::string& autor, int paginas, bool disponible = true);

    // Método que muestra la información del libro
    void mostrarInfo() const override;
};

#endif // LIBRO_H
