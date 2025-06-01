#include "../include/Futbolista.h"
#include <string>
using namespace std;


int Futbolista::cantidadFutbolistas = 0;
Futbolista Futbolista::futbolistas[MAX_FUTBOLISTAS];

// Métodos setters y getters

void Futbolista::setPosicion(string posicion) {
    this->posicion = posicion;
}
string Futbolista::getPosicion() {
    return posicion;
}

void Futbolista::setGolesMarcados(int golesMarcados) {
    this->golesMarcados = golesMarcados;
}
int Futbolista::getGolesMarcados() {
    return golesMarcados;
}

void Futbolista::setAsistencias(int asistencias) {
    this->asistencias = asistencias;
}
int Futbolista::getAsistencias() {
    return asistencias;
}

void Futbolista::setFaltas(int faltas) {
    this->faltas = faltas;
}
int Futbolista::getFaltas() {
    return faltas;
}

void Futbolista::setTarjetasAmarillas(int tarjetasAmarillas) {
    this->tarjetasAmarillas = tarjetasAmarillas;
}
int Futbolista::getTarjetasAmarillas() {
    return tarjetasAmarillas;
}

void Futbolista::setTarjetasRojas(int tarjetasRojas) {
    this->tarjetasRojas = tarjetasRojas;
}
int Futbolista::getTarjetasRojas() {
    return tarjetasRojas;
}

// Métodos funcionales

bool Futbolista::registrarFutbolista() {
    if (cantidadFutbolistas >= MAX_FUTBOLISTAS) {
        cout << "No se pueden registrar más futbolistas.\n";
        return false;
    }

    Futbolista f;
    string nombre, cedula, codigo, sexo, posicion;
    int edad, programa, goles, asistencias, faltas, amarillas, rojas;

    cout << "Nombre: "; cin >> nombre;
    cout << "Cedula: "; cin >> cedula;
    cout << "Codigo: "; cin >> codigo;
    cout << "Sexo: "; cin >> sexo;
    cout << "Edad: "; cin >> edad;
    cout << "Programa: "; cin >> programa;
    cout << "Posición: "; cin >> posicion;
    cout << "Goles marcados: "; cin >> goles;
    cout << "Asistencias: "; cin >> asistencias;
    cout << "Faltas: "; cin >> faltas;
    cout << "Tarjetas amarillas: "; cin >> amarillas;
    cout << "Tarjetas rojas: "; cin >> rojas;

    f.setNombre(nombre);
    f.setCedula(cedula);
    f.setCodigo(codigo);
    f.setSexo(sexo);
    f.setEdad(edad);
    f.setPrograma(programa);
    f.setPosicion(posicion);
    f.setGolesMarcados(goles);
    f.setAsistencias(asistencias);
    f.setFaltas(faltas);
    f.setTarjetasAmarillas(amarillas);
    f.setTarjetasRojas(rojas);

    futbolistas[cantidadFutbolistas++] = f;
    cout << "Futbolista registrado exitosamente.\n";
    return true;
}

void Futbolista::mostrarDatos() {
    cout << "Nombre: " << getNombre() << endl;
    cout << "Código: " << getCodigo() << endl;
    cout << "Edad: " << getEdad() << endl;
    cout << "Sexo: " << getSexo() << endl;
    cout << "Posición: " << posicion << endl;
    cout << "Goles: " << golesMarcados << ", Asistencias: " << asistencias << ", Faltas: " << faltas << endl;
    cout << "Tarjetas amarillas: " << tarjetasAmarillas << ", Tarjetas rojas: " << tarjetasRojas << endl;
}

void Futbolista::modificarFutbolista(const std::string codigo) {
    for (int i = 0; i < cantidadFutbolistas; ++i) {
        if (futbolistas[i].getCodigo() == codigo) {
            cout << "Futbolista encontrado:\n";
            futbolistas[i].mostrarDatos();

            cout << "¿Qué desea modificar?\n1. Nombre\n2. Cedula\n3. Sexo\n4. Edad\n5. Programa\n";
            int opcion; cin >> opcion;
            string texto;
            int numero;

            switch (opcion) {
                case 1: cout << "Nuevo nombre: "; cin >> texto; futbolistas[i].setNombre(texto); break;
                case 2: cout << "Nueva cedula: "; cin >> texto; futbolistas[i].setCedula(texto); break;
                case 3: cout << "Nuevo sexo: "; cin >> texto; futbolistas[i].setSexo(texto); break;
                case 4: cout << "Nueva edad: "; cin >> numero; futbolistas[i].setEdad(numero); break;
                case 5: cout << "Nuevo programa: "; cin >> numero; futbolistas[i].setPrograma(numero); break;
                default: cout << "Opción inválida.\n";
            }

            cout << "Datos actualizados correctamente.\n";
            return;
        }
    }

    cout << "No se encontró ningún futbolista con ese código.\n";
}

Futbolista* Futbolista::obtenerMejorGoleador() {
    Futbolista* mejor = nullptr;
    for (int i = 0; i < cantidadFutbolistas; ++i) {
        if (!mejor || futbolistas[i].getGolesMarcados() > mejor->getGolesMarcados()) {
            mejor = &futbolistas[i];
        }
    }
    return mejor;
}

Futbolista* Futbolista::obtenerMejorAsistente() {
    Futbolista* mejor = nullptr;
    for (int i = 0; i < cantidadFutbolistas; ++i) {
        if (!mejor || futbolistas[i].getAsistencias() > mejor->getAsistencias()) {
            mejor = &futbolistas[i];
        }
    }
    return mejor;
}
Futbolista* Futbolista::obtenerMayorFaltas() {
    Futbolista* mejor = nullptr;
    for (int i = 0; i < cantidadFutbolistas; ++i) {
        if (!mejor || futbolistas[i].getFaltas() > mejor->getFaltas()) {
            mejor = &futbolistas[i];
        }
    }
    return mejor;
}