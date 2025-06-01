#ifndef LIBRERIA_H
#define LIBRERIA_H

#include <string>
#include <iostream>

// Clase base abstracta para representar un elemento de la librería
class Libreria {
protected:
    std::string titulo;
    std::string genero;
    bool disponible;

public:
    // Constructor
    Libreria(const std::string& titulo, const std::string& genero, bool disponible = true);

    // Destructor virtual
    virtual ~Libreria();

    // Método virtual puro: debe implementarse en clases derivadas
    virtual void mostrarInfo() const = 0;

    // Métodos para acceder y modificar los atributos
    bool getDisponible() const;
    void setDisponible(bool estado);

    std::string getTitulo() const;
    std::string getGenero() const;
};

#endif // LIBRERIA_H
