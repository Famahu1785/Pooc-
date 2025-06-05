#include "/workspaces/Pooc-/tallerLibreria/include/Libreria.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

// Elimina espacios en blanco al inicio y final de una cadena
std::string trim(const std::string& s) {
    int i = 0, j = s.size() - 1;
    while (i < (int)s.size() && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\r')) i++;
    while (j >= i && (s[j] == ' ' || s[j] == '\t' || s[j] == '\n' || s[j] == '\r')) j--;
    return s.substr(i, j - i + 1);
}

// Constructor: carga los datos de los materiales
Libreria::Libreria() {
    cargarDatos();
}

// Destructor: libera la memoria de los materiales
Libreria::~Libreria() {
    for (unsigned int i = 0; i < materiales.size(); i++) {
        delete materiales[i];
    }
}

// Carga los datos de libros, DVDs y revistas desde archivos de texto
void Libreria::cargarDatos() {
    std::ifstream file;
    std::string linea;

    // Libros
    file.open("libros.txt");
    while (getline(file, linea)) {
        if (linea == "") continue;
        std::stringstream ss(linea);
        std::string isbn, titulo, autor, genero, paginasStr;
        int paginas = 0;
        getline(ss, isbn, '-');
        getline(ss, titulo, '-');
        getline(ss, autor, '-');
        getline(ss, genero, '-');
        getline(ss, paginasStr, '-');
        isbn = trim(isbn);
        titulo = trim(titulo);
        autor = trim(autor);
        genero = trim(genero);
        paginasStr = trim(paginasStr);
        if (paginasStr == "") continue;
        try {
            paginas = std::stoi(paginasStr);
        } catch (...) {
            continue;
        }
        materiales.push_back(new Libro(isbn, titulo, genero, autor, paginas));
    }
    file.close();

    // DVDs
    file.open("DVDs.txt");
    while (getline(file, linea)) {
        if (linea == "") continue;
        std::stringstream ss(linea);
        std::string id, titulo, genero, director, duracionStr;
        int duracion = 0;
        getline(ss, id, '-');
        getline(ss, titulo, '-');
        getline(ss, genero, '-');
        getline(ss, director, '-');
        getline(ss, duracionStr, '-');
        id = trim(id);
        titulo = trim(titulo);
        genero = trim(genero);
        director = trim(director);
        duracionStr = trim(duracionStr);
        if (duracionStr == "") continue;
        try {
            duracion = std::stoi(duracionStr);
        } catch (...) {
            continue;
        }
        materiales.push_back(new Dvd(id, titulo, genero, director, duracion));
    }
    file.close();

    // Revistas
    file.open("Revistas.txt");
    while (getline(file, linea)) {
        if (linea == "") continue;
        std::stringstream ss(linea);
        std::string id, nombre, tematica, edicionStr;
        int edicion = 0;
        getline(ss, id, '-');
        getline(ss, nombre, '-');
        getline(ss, tematica, '-');
        getline(ss, edicionStr, '-');
        id = trim(id);
        nombre = trim(nombre);
        tematica = trim(tematica);
        edicionStr = trim(edicionStr);
        if (edicionStr == "") continue;
        try {
            edicion = std::stoi(edicionStr);
        } catch (...) {
            continue;
        }
        materiales.push_back(new Revista(id, nombre, tematica, edicion));
    }
    file.close();
}

// Permite a un usuario prestar un material si cumple las condiciones
void Libreria::prestarMaterial(const std::string& usuario, const std::string& id) {
    std::string idBuscado = trim(id);
    Usuario* u = nullptr;
    // Busca el usuario, si no existe lo crea
    for (unsigned int i = 0; i < usuarios.size(); i++) {
        if (usuarios[i].getNombre() == usuario) {
            u = &usuarios[i];
            break;
        }
    }
    if (u == nullptr) {
        usuarios.push_back(Usuario(usuario));
        u = &usuarios[usuarios.size() - 1];
    }

    // Verifica si el usuario ya tiene 3 préstamos
    if (u->cantidadPrestamos() >= 3) {
        std::cout << "No puedes prestar más de 3 materiales a la vez.\n";
        return;
    }

    // Busca el material y realiza el préstamo si está disponible
    for (unsigned int i = 0; i < materiales.size(); i++) {
        std::string idMaterial = trim(materiales[i]->getID());
        if (idMaterial == idBuscado && materiales[i]->estaDisponible()) {
            if (u->prestar(materiales[i])) {
                registrarOperacion("PRESTAMO", usuario, idBuscado);
                std::cout << "Préstamo exitoso.\n";
            } else {
                std::cout << "No se puede prestar el material.\n";
            }
            return;
        }
    }
    std::cout << "Material no encontrado o no disponible.\n";
}

// Permite a un usuario devolver un material prestado
void Libreria::devolverMaterial(const std::string& usuario, const std::string& id) {
    std::string idBuscado = trim(id);
    for (unsigned int i = 0; i < usuarios.size(); i++) {
        if (usuarios[i].getNombre() == usuario) {
            if (usuarios[i].devolver(idBuscado)) {
                registrarOperacion("DEVOLUCION", usuario, idBuscado);
                std::cout << "Devolución registrada.\n";
            } else {
                std::cout << "El usuario no tiene prestado ese material.\n";
            }
            return;
        }
    }
    std::cout << "Usuario no encontrado.\n";
}

// Muestra todos los materiales y su estado (disponible o prestado)
void Libreria::mostrarMateriales() {
    for (unsigned int i = 0; i < materiales.size(); i++) {
        materiales[i]->mostrar();
        std::cout << " | Estado: ";
        if (materiales[i]->estaDisponible())
            std::cout << "Disponible (1/1)";
        else
            std::cout << "Prestado (0/1)";
        std::cout << std::endl;
    }
}

// Registra una operación de préstamo o devolución en un archivo de texto
void Libreria::registrarOperacion(const std::string& tipo, const std::string& usuario, const std::string& id) {
    std::ofstream archivo;
    if (tipo == "PRESTAMO")
        archivo.open("prestamos.txt", std::ios::app);
    else
        archivo.open("devoluciones.txt", std::ios::app);

    archivo << tipo << " | " << usuario << " | " << id << std::endl;
    archivo.close();
}

// Devuelve la cantidad de préstamos activos de un usuario
int Libreria::prestamosDeUsuario(const std::string& nombre) const {
    for (unsigned int i = 0; i < usuarios.size(); i++) {
        if (usuarios[i].getNombre() == nombre)
            return usuarios[i].cantidadPrestamos();
    }
    return 0;
}