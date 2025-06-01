#include "../include/Basketbolista.h"
#include <iostream>
using namespace std;



void Basketbolista::setPosicion(string posicion) {
    this->posicion = posicion;
}

string Basketbolista::getPosicion() {
    return posicion;
}

void Basketbolista::setPuntos(int puntos) {
    this->puntos = puntos;
}

int Basketbolista::getPuntos() {
    return puntos;
}

void Basketbolista::setAsistencias(int asistencias) {
    this->asistencias = asistencias;
}

int Basketbolista::getAsistencias() {
    return asistencias;
}

void Basketbolista::setRebotes(int rebotes) {
    this->rebotes = rebotes;
}

int Basketbolista::getRebotes() {
    return rebotes;
}

void Basketbolista::setFaltas(int faltas) {
    this->faltas = faltas;
}

int Basketbolista::getFaltas() {
    return faltas;
}

void Basketbolista::setTirosLibres(int tirosLibres) {
    this->tirosLibres = tirosLibres;
}

int Basketbolista::getTirosLibres() {
    return tirosLibres;
}

void Basketbolista::setTirosDeCampo(int tirosDeCampo) {
    this->tirosDeCampo = tirosDeCampo;
}

int Basketbolista::getTirosDeCampo() {
    return tirosDeCampo;
}

// ----- Funciones para gestión externa sin vector -----

static Basketbolista registrados[2];   // Arreglo para almacenar los registrados
static int cantidadRegistrados = 0;    // Contador de registrados

Basketbolista Basketbolista::basketbolistas[7];  // Arreglo estático de basketbolistas
int Basketbolista::cantidadBasketbolistas = 0;   // Contador estático de basketbolistas

// Función para registrar un nuevo basketbolista
bool registrarBasketbolista() {
    if (cantidadRegistrados >= 2) {
        return false;  // Limite de registros alcanzado
    }

    Basketbolista b;
    string nombre, cedula, codigo, sexo, posicion;
    int edad, programa, puntos, asistencias, rebotes, faltas, tirosLibres, tirosDeCampo;

    cout << "Nombre: "; cin >> nombre;
    cout << "Cedula: "; cin >> cedula;
    cout << "Codigo: "; cin >> codigo;
    cout << "Sexo: "; cin >> sexo;
    cout << "Edad: "; cin >> edad;
    cout << "Programa: "; cin >> programa;
    cout << "Posicion: "; cin >> posicion;
    cout << "Puntos: "; cin >> puntos;
    cout << "Asistencias: "; cin >> asistencias;
    cout << "Rebotes: "; cin >> rebotes;
    cout << "Faltas: "; cin >> faltas;
    cout << "Tiros Libres: "; cin >> tirosLibres;
    cout << "Tiros de Campo: "; cin >> tirosDeCampo;

    b.setNombre(nombre);
    b.setCedula(cedula);
    b.setCodigo(codigo);
    b.setSexo(sexo);
    b.setEdad(edad);
    b.setPrograma(programa);
    b.setPosicion(posicion);
    b.setPuntos(puntos);
    b.setAsistencias(asistencias);
    b.setRebotes(rebotes);
    b.setFaltas(faltas);
    b.setTirosLibres(tirosLibres);
    b.setTirosDeCampo(tirosDeCampo);

    registrados[cantidadRegistrados++] = b;  // Añadir el nuevo basketbolista
    cout << "Basketbolista registrado.\n";
    return true;
}

// Función para modificar un basketbolista por su código
bool modificarBasketbolistaPorCodigo(const string& codigoBusqueda) {
    for (int i = 0; i < cantidadRegistrados; i++) {
        if (registrados[i].getCodigo() == codigoBusqueda) {
            cout << "Basketbolista encontrado.\n";
            cout << "1. Nombre\n2. Cedula\n3. Sexo\n4. Edad\n5. Programa\n";
            int opcionMod; cin >> opcionMod;
            string nuevoTexto; int nuevoNumero;

            switch (opcionMod) {
                case 1: cout << "Nuevo nombre: "; cin >> nuevoTexto; registrados[i].setNombre(nuevoTexto); break;
                case 2: cout << "Nueva cedula: "; cin >> nuevoTexto; registrados[i].setCedula(nuevoTexto); break;
                case 3: cout << "Nuevo sexo: "; cin >> nuevoTexto; registrados[i].setSexo(nuevoTexto); break;
                case 4: cout << "Nueva edad: "; cin >> nuevoNumero; registrados[i].setEdad(nuevoNumero); break;
                case 5: cout << "Nuevo programa: "; cin >> nuevoNumero; registrados[i].setPrograma(nuevoNumero); break;
                default: cout << "Opcion invalida.\n"; return false;
            }
            cout << "Datos actualizados correctamente.\n";
            return true;
        }
    }
    cout << "Basketbolista con codigo " << codigoBusqueda << " no encontrado.\n";
    return false;
}

// Función estática para obtener el mejor basketbolista por puntos
Basketbolista* Basketbolista::obtenerMejorPuntero() {
    Basketbolista* mejor = nullptr;
    for (int i = 0; i < cantidadBasketbolistas; ++i) {
        if (!mejor || basketbolistas[i].getPuntos() > mejor->getPuntos()) {
            mejor = &basketbolistas[i];
        }
    }
    return mejor;
}

Basketbolista* Basketbolista::obtenerMejorAsistente() {
    Basketbolista* mejor = nullptr;
    for (int i = 0; i < cantidadBasketbolistas; ++i) {
        if (!mejor || basketbolistas[i].getAsistencias() > mejor->getAsistencias()) {
            mejor = &basketbolistas[i];
        }
    }
    return mejor;
}
Basketbolista* Basketbolista::obtenerMayorFaltas() {
    Basketbolista* mayor = nullptr;
    for (int i = 0; i < cantidadBasketbolistas; ++i) {
        if (!mayor || basketbolistas[i].getFaltas() > mayor->getFaltas()) {
            mayor = &basketbolistas[i];
        }
    }
    return mayor;
}


