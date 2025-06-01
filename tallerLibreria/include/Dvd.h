#ifndef DVD_H
#define DVD_H

#include "Libreria.h"
#include <string>

// Clase que representa un DVD en la librería
class DVD : public Libreria {
private:
    std::string id;
    std::string director;
    int duracion;

public:
    // Constructor del DVD
    DVD(const std::string& id,
        const std::string& titulo,
        const std::string& genero,
        const std::string& director,
        int duracion,
        bool disponible = true);

    // Muestra la información del DVD (override del método virtual de Libreria)
    void mostrarInfo() const override;
};

#endif // DVD_H
