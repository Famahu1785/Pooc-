#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "/workspaces/Pooc-/notasArchivo/include/Estudiante.h"
using namespace std;

vector<string> separarcadena(string registro);

vector<Estudiante> generarEstudiantes(vector<string> elementos);
 
int main() {
    vector<string> resgistros;
    string linea;
    vector<string> palabras;
    vector<string> registrosCompleto;
    vector<Estudiante> Estudiantes;

    fstream archivo("/workspaces/Pooc-/notasArchivo/Notas.txt", ios::in);  
    
    while (getline(archivo, linea)){
        resgistros.push_back(linea);
    }

    for (size_t k=0; k< resgistros.size(); k++){
        palabras = separarcadena(resgistros[k]);

        // Tiene un tamaño máximo de 6 porque cada registro tiene 6 elementos
        for(int m =0; m<6; m++){
           registrosCompleto.push_back(palabras[m]);
        }
    }

    Estudiantes = generarEstudiantes(registrosCompleto);

    // Calcular promedio

    for(int i=0;i<Estudiantes.size(); i++){
        Estudiantes[].calcularPromedio();
    }

    for (int j=0; j<Estudiantes.size(); j++){
        cout << Estudiantes[j].getCodigo() << " " << Estudiantes[j].getNombre() << " " << Estudiantes[j].getPromedio() << endl;
    }
    // Imprimir los Estudiantes con su promedio

    return 0;
}

vector<Estudiante> generarEstudiantes(vector<string> elementos){
    string codigo, nombre;
    float notas[3], adicional;

    vector<Estudiante> salida;

    for(int j =0; j<elementos.size(); j+=6){
        codigo = elementos[j];
        nombre = elementos[j+1];
        notas[0] = stof(elementos[j+2]);
        notas[1] = stof(elementos[j+3]);
        notas[2] = stof(elementos[j+4]);
        adicional = stof(elementos[j+5]);
        Estudiante estu = Estudiante(codigo, nombre, notas, adicional);
        salida.push_back(estu);
    }
    return salida;
}

vector<string> separarcadena(string registro){
    char delimitador = '-';
    string auxiliar = "";
    vector<string> contenido;

    for(size_t i =0; i<registro.size(); i++){
        if (registro[i] != delimitador){
            auxiliar += registro[i];
        }else{
            contenido.push_back(auxiliar);
            auxiliar = "";
        }
    }
    contenido.push_back(auxiliar); // Agregar el último elemento al vector
    return contenido;
}
