#ifndef MATERIAL_H
#define MATERIAL_H
#include <string>
using namespace std;

class Material {
protected:
    string titulo;
    string genero;
    bool disponible; // se declaro como booleano ya que solo necesitamos saber si el material está disponible o no

public:
    Material(string t, string g) : titulo(t), genero(g), disponible(true) {} // este constructor inicializa el material como disponible
    virtual void mostrar() = 0; // Método virtual puro para mostrar los detalles del material
    virtual string getID() = 0; // Método virtual puro para obtener el ID del material, se coloca igual a 0 ya que cada tipo de material tendrá su propia implementación
    bool estaDisponible() const { return disponible; } // Método para verificar si el material está disponible
    void setDisponible(bool d) { disponible = d; } // Método para cambiar el estado de disponibilidad
    string getTitulo() const { return titulo; } // Método para obtener el título del material
    virtual ~Material() {} // Destructor virtual para asegurar que los destructores de las clases derivadas se llamen correctamente
};
#endif