
#include <iostream>
#include <fstream>
#include <vector>
#include "/workspaces/Pooc-/tallerLibreria/include/Libreria.h"
#include "/workspaces/Pooc-/tallerLibreria/include/Libro.h"
#include "/workspaces/Pooc-/tallerLibreria/include/Revista.h"
#include "/workspaces/Pooc-/tallerLibreria/include/Dvd.h"
#include "/workspaces/Pooc-/tallerLibreria/include/Usuario.h"

using namespace std;

void cargarLibros(vector<Libreria*>& materiales) {
    ifstream archivo("libros.txt");
    string linea;
    while (getline(archivo, linea)) {
        size_t pos = 0;
        string campos[5];
        for (int i = 0; i < 4; ++i) {
            size_t sig = linea.find("-", pos);
            campos[i] = linea.substr(pos, sig - pos);
            pos = sig + 2;
        }
        campos[4] = linea.substr(pos);
        materiales.push_back(new Libro(campos[0], campos[1], campos[3], campos[2], stoi(campos[4])));
    }
    archivo.close();
}

void cargarRevistas(vector<Libreria*>& materiales) {
    ifstream archivo("Revistas.txt");
    string linea;
    while (getline(archivo, linea)) {
        size_t pos = 0;
        string campos[4];
        for (int i = 0; i < 3; ++i) {
            size_t sig = linea.find("-", pos);
            campos[i] = linea.substr(pos, sig - pos);
            pos = sig + 2;
        }
        campos[3] = linea.substr(pos);
        materiales.push_back(new Revista(campos[0], campos[1], campos[2], stoi(campos[3]), ""));
    }
    archivo.close();
}

void cargarDVDs(vector<Libreria*>& materiales) {
    ifstream archivo("DVDs.txt");
    string linea;
    while (getline(archivo, linea)) {
        size_t pos = 0;
        string campos[5];
        for (int i = 0; i < 4; ++i) {
            size_t sig = linea.find("-", pos);
            campos[i] = linea.substr(pos, sig - pos);
            pos = sig + 2;
        }
        campos[4] = linea.substr(pos);
        materiales.push_back(new DVD(campos[0], campos[1], campos[2], campos[3], stoi(campos[4])));
    }
    archivo.close();
}

void mostrarMaterialesDisponibles(const vector<Libreria*>& materiales) {
    for (size_t i = 0; i < materiales.size(); ++i) {
        if (materiales[i]->getDisponible()) {
            cout << i + 1 << ". ";
            materiales[i]->mostrarInfo();
        }
    }
}

int main() {
    vector<Libreria*> materiales;
    cargarLibros(materiales);
    cargarRevistas(materiales);
    cargarDVDs(materiales);

    string nombre;
    cout << "Ingrese su nombre: ";
    getline(cin, nombre);
    Usuario usuario(nombre);

    int opcion;
    do {
        cout << "\n--- MENU BIBLIOTECA ---\n";
        cout << "1. Ver materiales disponibles\n";
        cout << "2. Prestar material\n";
        cout << "3. Ver mis préstamos\n";
        cout << "4. Devolver material\n";
        cout << "5. Salir\n";
        cout << "Opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                mostrarMaterialesDisponibles(materiales);
                break;
            case 2:
                if (!usuario.puedePrestar()) {
                    cout << "\n[!] Ya tienes 3 materiales prestados.\n";
                    break;
                }
                mostrarMaterialesDisponibles(materiales);
                cout << "Seleccione el número del material a prestar: ";
                int n;
                cin >> n;
                if (n >= 1 && n <= static_cast<int>(materiales.size()))
                    usuario.prestar(materiales[n - 1]);
                else
                    cout << "Opción inválida.\n";
                break;
            case 3:
                usuario.mostrarPrestamos();
                break;
            case 4:
                usuario.mostrarPrestamos();
                cout << "Seleccione el número del material a devolver: ";
                int d;
                cin >> d;
                usuario.devolver(d - 1);
                break;
            case 5:
                cout << "Saliendo del sistema...\n";
                break;
            default:
                cout << "Opción inválida.\n";
        }
    } while (opcion != 5);

    for (auto m : materiales) delete m;
    return 0;
}
