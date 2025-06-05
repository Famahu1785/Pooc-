#ifndef LIBRO_H
#define LIBRO_H
#include "Material.h"

class Libro : public Material {
    string isbn, autor;
    int paginas;

public:
    Libro(string i, string t, string g, string a, int p);
    void mostrar() override; // el override indica que estamos sobreescribiendo un método virtual de la clase base
    // Métodos específicos de Libro
    string getID() override;
};

#endif
