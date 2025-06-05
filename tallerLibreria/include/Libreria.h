#ifndef LIBRERIA_H
#define LIBRERIA_H

#include "Libro.h"
#include "Revista.h"
#include "Dvd.h"
#include "Usuario.h"
#include <vector>
#include <string>
#include <fstream>

class Libreria {
private:
    // Vector de punteros a Material (puede ser Libro, Revista o Dvd)
    std::vector<Material*> materiales;
    // Vector de usuarios registrados en la biblioteca
    std::vector<Usuario> usuarios;

public:
    // Constructor de la clase Libreria
    Libreria();
    // Destructor de la clase Libreria
    ~Libreria(); // el ~ indica que es un destructor 

    // Carga los datos de materiales y usuarios desde archivos
    void cargarDatos();
    // Permite a un usuario prestar un material por su ID
    void prestarMaterial(const std::string& usuario, const std::string& id);
    // Permite a un usuario devolver un material por su ID
    void devolverMaterial(const std::string& usuario, const std::string& id);
    // Muestra todos los materiales disponibles en la biblioteca
    void mostrarMateriales();
    // Registra una operación (préstamo o devolución) en un archivo de registro
    void registrarOperacion(const std::string& tipo, const std::string& usuario, const std::string& id);

    // Devuelve la cantidad de préstamos que tiene un usuario
    int prestamosDeUsuario(const std::string& nombre) const;
};

#endif
