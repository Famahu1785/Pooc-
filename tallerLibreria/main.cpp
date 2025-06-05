#include <iostream>
#include <string>
#include <limits>
#include "/workspaces/Pooc-/tallerLibreria/include/Libreria.h"

int main() {
    Libreria biblioteca; // Creamos el objeto de la biblioteca
    int opcion = 0;
    std::string usuario, idMaterial;

    // Menú principal
    while (opcion != 4) {
        std::cout << "\n1. Mostrar materiales\n";
        std::cout << "2. Prestar material\n";
        std::cout << "3. Devolver material\n";
        std::cout << "4. Salir\n";
        std::cout << "Elige una opción: ";

        // Validar entrada de opción
        if (!(std::cin >> opcion)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Por favor ingresa un número válido.\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar buffer

        switch (opcion) {
            case 1:
                // Mostrar todos los materiales disponibles
                biblioteca.mostrarMateriales();
                break;
            case 2: {
                // Solicitar nombre del usuario
                std::cout << "Ingresa tu nombre: ";
                std::getline(std::cin, usuario);

                // Verificar cuántos materiales tiene prestados el usuario
                int prestados = biblioteca.prestamosDeUsuario(usuario);
                int disponibles = 3 - prestados;
                if (disponibles <= 0) {
                    std::cout << "Ya tienes el máximo de materiales prestados (3).\n";
                    break;
                }

                int cuantos = 0;
                std::cout << "¿Cuántos materiales quieres llevar? (máximo " << disponibles << "): ";
                std::cin >> cuantos;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if (cuantos < 1 || cuantos > disponibles) {
                    std::cout << "Cantidad no permitida.\n";
                    break;
                }

                // Pedir los IDs de los materiales a prestar
                for (int i = 0; i < cuantos; i++) {
                    std::cout << "ID del material #" << (i + 1) << ": ";
                    std::getline(std::cin, idMaterial);
                    biblioteca.prestarMaterial(usuario, idMaterial);
                }
                break;
            }
            case 3:
                // Devolver material
                std::cout << "Ingresa tu nombre: ";
                std::getline(std::cin, usuario);
                std::cout << "ID del material a devolver: ";
                std::getline(std::cin, idMaterial);
                biblioteca.devolverMaterial(usuario, idMaterial);
                break;
            case 4:
                std::cout << "Hasta luego!\n";
                break;
            default:
                std::cout << "Opción no válida. Intenta de nuevo.\n";
        }
    }

    return 0;
}