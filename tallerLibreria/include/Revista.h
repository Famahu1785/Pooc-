#ifndef REVISTA_H
#define REVISTA_H

#include "Libreria.h"
#include <string>
#include <iostream>

// Clase que representa una revista en la librería
class Revista : public Libreria {
private:
    std::string id;
    std::string tematica;
    int edicion;

public:
    // Constructor
    Revista(const std::string& id, const std::string& nombre, const std::string& tematica,
            int edicion, const std::string& genero, bool disponible = true);

    // Muestra la información de la revista
    void mostrarInfo() const override;
};

#endif // REVISTA_H

