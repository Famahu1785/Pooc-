#include <iostream>
#include <string>
#include <limits>
#include "/workspaces/Pooc-/tallerLibreria/include/Libreria.h"

int main() {
    Libreria biblioteca; // se crea el objeto de la biblioteca
    int opcion = 0;
    string usuario, idMaterial; // se esta declarando las variables para el usuario y el id del material (codigo)

    // este es el menú principal (entrada)
    while (opcion != 4) {
        cout << "\n1. Mostrar materiales\n";
        cout << "2. Prestar material\n";
        cout << "3. Devolver material\n";
        cout << "4. Salir\n";
        cout << "Elige una opción: ";

        // Validar entrada de opción
        if (!(cin >> opcion)) {
            cin.clear(); // limpiar el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // se utilizo eel vector de streamsize para limpiar el buffer
            cout << "Por favor ingresa un número válido.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar buffer

        switch (opcion) {
            case 1:
                // Mostrar todos los materiales disponibles (mostrar todo "Libros", "Revistas", "DvDs")
                biblioteca.mostrarMateriales();
                break;
            case 2: {
                //Se socilita el nombre del usuario para empezar
                cout << "Ingresa tu nombre: ";
                getline(cin, usuario);

                // Verificar cuántos materiales tiene prestados el usuario para ver si se le puede prestar más
                int prestados = biblioteca.prestamosDeUsuario(usuario);
                int disponibles = 3 - prestados; // máximo 3 materiales prestados
                if (disponibles <= 0) { // se utiliza este if para validar que el usuario no tenga más de 3 materiales prestados
                    cout << "Ya tienes el máximo de materiales prestados (3).\n";
                    break;
                }

                int cuantos = 0;
                cout << "¿Cuántos materiales quieres llevar? (máximo " << disponibles << "): ";
                cin >> cuantos;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (cuantos < 1 || cuantos > disponibles) { // se valida que el usuario no ingrese un número menor a 1 o mayor a 3
                    cout << "Cantidad no permitida.\n";
                    break;
                }

                // Pedir los IDs de los materiales a prestar
                for (int i = 0; i < cuantos; i++) {
                    cout << "ID del material #" << (i + 1) << ": "; // se solicita el id del material
                    // Limpiar buffer antes de leer el ID
                    getline(cin, idMaterial);
                    biblioteca.prestarMaterial(usuario, idMaterial);
                }
                break;
            }
            case 3:
                cout << "Ingresa tu nombre: ";
                getline(cin, usuario); // se solicita el nombre del usuario para devolver el material
                cout << "ID del material a devolver: ";
                getline(cin, idMaterial); // se solicita el id del material a devolver
                // Validar que el usuario tenga el material prestado
                biblioteca.devolverMaterial(usuario, idMaterial);
                break;
            case 4:
                cout << "Hasta luego!\n";
                break;
            default:
                cout << "Opción no válida. Intenta de nuevo.\n";
        }
    }

    return 0;
}