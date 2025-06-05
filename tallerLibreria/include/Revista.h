#ifndef REVISTA_H
#define REVISTA_H
#include "Material.h"

class Revista : public Material {
    string id, tematica;
    int edicion;

public:
    Revista(string i, string n, string t, int e);
    void mostrar() override;
    string getID() override;
};

#endif

