#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <string>

using namespace std;
class Estudiante {
    private:
        string nombre;
        string codigo;
        float promedio;
        float notas[3];
        float adicional;
    public:
        Estudiante();
        Estudiante(string nombre, string codigo, float notas[3], float adicional);

        void setCodigo(string codigo);
        string getCodigo();

        void setNombre(string nombre);
        string getNombre();

        void setNotas(float notas[3]);

        void setAdicional(float adicional);
        float getAdicional();

        void calcularPromedio();
        float getPromedio();
    
} ;
#endif
