#ifndef LIBRO_H
#define LIBRO_H
#include "Material.h"

class Libro : public Material {
    string isbn, autor;
    int paginas;

public:
    Libro(string i, string t, string g, string a, int p);
    void mostrar() override;
    string getID() override;
};

#endif
