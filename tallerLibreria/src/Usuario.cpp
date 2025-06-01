#include "/workspaces/Pooc-/tallerLibreria/include/Usuario.h"
#include <iostream>
#include <fstream>

Usuario::Usuario(const std::string& nombre) : nombre(nombre) {}

std::string Usuario::getNombre() const {
    return nombre;
}

bool Usuario::puedePrestar() const {
    return prestados.size() < 3;
}

void Usuario::mostrarPrestamos() const {
    std::cout << "\nMateriales prestados por " << nombre << ":\n";
    if (prestados.empty()) {
        std::cout << "Ninguno\n";
        return;
    }
    for (size_t i = 0; i < prestados.size(); ++i) {
        std::cout << i + 1 << ". ";
        prestados[i]->mostrarInfo();
    }
}

void Usuario::prestar(Libreria* libreria) {
    if (libreria->getDisponible() && puedePrestar()) {
        prestados.push_back(libreria);
        libreria->setDisponible(false);

        std::ofstream archivo("prestamos.txt", std::ios::app);
        archivo << nombre << " prestó: " << libreria->getTitulo() << "\n";
        archivo.close();
    } else {
        std::cout << "No se puede prestar el Libreria.\n";
    }
}

void Usuario::devolver(int index) {
    if (index >= 0 && index < prestados.size()) {
        Libreria* libreria = prestados[index];
        libreria->setDisponible(true);

        std::ofstream archivo("devoluciones.txt", std::ios::app);
        archivo << nombre << " devolvió: " << libreria->getTitulo() << "\n";
        archivo.close();

        prestados.erase(prestados.begin() + index);
        std::cout << "Devolución registrada.\n";
    } else {
        std::cout << "Índice inválido.\n";
    }
}

int Usuario::totalPrestados() const {
    return prestados.size();
}

Libreria* Usuario::getPrestado(int index) {
    return (index >= 0 && index < prestados.size()) ? prestados[index] : nullptr;
}
