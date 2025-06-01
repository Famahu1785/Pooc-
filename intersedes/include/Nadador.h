#ifndef NADADOR_H
#define NADADOR_H


#include "Deportista.h"
#include <iostream>
#include <string>



class Nadador: public Deportista {

    private:
        std::string estilo;
        float tiempos[5], peso;       

        static Nadador nadadores[2];
        static int cantidadNadadores;
    public:
        void setEstilo(std::string estilo);
        std::string getEstilo();
        void setTiempos(float tiempos[5]);
        float* getTiempos();
        void setPeso(float peso);
        float getPeso();

        float calcularPromedioTiempo();
        void mostrarMejorTiempo();
        void mostrarDatos();

        static bool regitroNadador();
        static void modificarNadaorcodigo(std::string codigo);
        static float promedioGeneralTiempos();
    protected:
        
};

#endif 