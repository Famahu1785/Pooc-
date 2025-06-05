#ifndef MATERIAL_H
#define MATERIAL_H
#include <string>
using namespace std;

class Material {
protected:
    string titulo;
    string genero;
    bool disponible;

public:
    Material(string t, string g) : titulo(t), genero(g), disponible(true) {} // ← CORREGIDO
    virtual void mostrar() = 0;
    virtual string getID() = 0;
    bool estaDisponible() const { return disponible; }
    void setDisponible(bool d) { disponible = d; }
    string getTitulo() const { return titulo; }
    virtual ~Material() {}
};
#endif