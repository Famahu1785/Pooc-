#ifndef DVD_H
#define DVD_H
#include "Material.h"

class Dvd : public Material {
    string id, director;
    int duracion;

public:
    Dvd(string i, string t, string g, string d, int dur);
    void mostrar() override; // El metodo override indica que estamos sobreescribiendo un metodo virtual de la clase base
    // En este caso, el metodo mostrar() de la clase Material
    string getID() override;
};

#endif

