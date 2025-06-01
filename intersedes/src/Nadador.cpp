#include "../include/Nadador.h"
#include <string>
using namespace std;



// Inicialización de variables estáticas
Nadador Nadador::nadadores[2];
int Nadador::cantidadNadadores = 0;

// Setters y Getters
void Nadador::setEstilo(string estilo) {
    this->estilo = estilo;
}

string Nadador::getEstilo() {
    return estilo;
}

void Nadador::setTiempos(float tiempos[5]) {
    for (int i = 0; i < 5; i++) {
        this->tiempos[i] = tiempos[i];
    }
}

float* Nadador::getTiempos() {
    return tiempos;
}

void Nadador::setPeso(float peso) {
    this->peso = peso;
}

float Nadador::getPeso() {
    return peso;
}

// Funciones adicionales
float Nadador::calcularPromedioTiempo() {
    float suma = 0;
    for (int i = 0; i < 5; i++) {
        suma += tiempos[i];
    }
    return suma / 5;
}

void Nadador::mostrarMejorTiempo() {
    float mejorTiempo = tiempos[0];
    for (int i = 1; i < 5; i++) {
        if (tiempos[i] < mejorTiempo) {
            mejorTiempo = tiempos[i];
        }
    }
    cout << "El mejor tiempo es: " << mejorTiempo << " segundos." << endl;
}

void Nadador::mostrarDatos() {
    cout << "Nombre: " << getNombre() << endl;
    cout << "Cédula: " << getCedula() << endl;
    cout << "Código: " << getCodigo() << endl;
    cout << "Sexo: " << getSexo() << endl;
    cout << "Edad: " << getEdad() << endl;
    cout << "Programa: " << getPrograma() << endl;
    cout << "Estilo: " << estilo << endl;
    cout << "Peso: " << peso << " kg" << endl;
    cout << "Tiempos: ";
    for (int i = 0; i < 5; i++) {
        cout << tiempos[i] << " ";
    }
    cout << endl;
}


bool Nadador::regitroNadador() {
    if (cantidadNadadores >= 2) {
        return false;
    }

    Nadador& n = nadadores[cantidadNadadores];
    string nombre, cedula, codigo, sexo, estilo;
    int edad, programa;
    float peso, tiempos[5];

    cout << "Nombre: "; cin >> nombre;
    cout << "Cédula: "; cin >> cedula;
    cout << "Código: "; cin >> codigo;
    cout << "Sexo: "; cin >> sexo;
    cout << "Edad: "; cin >> edad;
    cout << "Programa: "; cin >> programa;
    cout << "Estilo: "; cin >> estilo;
    cout << "Peso: "; cin >> peso;
    cout << "Ingrese 5 tiempos (en segundos): ";
    for (int i = 0; i < 5; i++) {
        cin >> tiempos[i];
    }

    n.setNombre(nombre);
    n.setCedula(cedula);
    n.setCodigo(codigo);
    n.setSexo(sexo);
    n.setEdad(edad);
    n.setPrograma(programa);
    n.setEstilo(estilo);
    n.setPeso(peso);
    n.setTiempos(tiempos);

    cantidadNadadores++;
    cout << "Nadador registrado con éxito." << endl;
    return true;
}

// Modificar por código
void Nadador::modificarNadaorcodigo(std::string codigo) {
    bool encontrado = false;

    for (int i = 0; i < cantidadNadadores; i++) {
        if (nadadores[i].getCodigo() == codigo) {
            encontrado = true;
            cout << "Nadador encontrado:\n";
            nadadores[i].mostrarDatos();

            cout << "¿Qué desea modificar?\n";
            cout << "1. Nombre\n2. Cédula\n3. Sexo\n4. Edad\n5. Programa\n6. Estilo\n7. Peso\n";
            int opcionMod;
            cin >> opcionMod;

            string texto;
            int entero;
            float decimal;

            switch (opcionMod) {
                case 1:
                    cout << "Nuevo nombre: ";
                    cin >> texto;
                    nadadores[i].setNombre(texto);
                    break;
                case 2:
                    cout << "Nueva cédula: ";
                    cin >> texto;
                    nadadores[i].setCedula(texto);
                    break;
                case 3:
                    cout << "Nuevo sexo: ";
                    cin >> texto;
                    nadadores[i].setSexo(texto);
                    break;
                case 4:
                    cout << "Nueva edad: ";
                    cin >> entero;
                    nadadores[i].setEdad(entero);
                    break;
                case 5:
                    cout << "Nuevo programa: ";
                    cin >> entero;
                    nadadores[i].setPrograma(entero);
                    break;
                case 6:
                    cout << "Nuevo estilo: ";
                    cin >> texto;
                    nadadores[i].setEstilo(texto);
                    break;
                case 7:
                    cout << "Nuevo peso: ";
                    cin >> decimal;
                    nadadores[i].setPeso(decimal);
                    break;
                default:
                    cout << "Opción inválida.\n";
            }

            cout << "Datos actualizados correctamente.\n";
            break;
        }
    }

    if (!encontrado) {
        cout << "Nadador no encontrado.\n";
    }
}

float Nadador::promedioGeneralTiempos() {
    if (cantidadNadadores == 0) return 0.0f;

    float sumaTotal = 0;
    int totalTiempos = 0;

    for (int i = 0; i < cantidadNadadores; i++) {
        float* tiempos = nadadores[i].getTiempos();
        for (int j = 0; j < 5; j++) {
            sumaTotal += tiempos[j];
            totalTiempos++;
        }
    }

    return sumaTotal / totalTiempos;
}
