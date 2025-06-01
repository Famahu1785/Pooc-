#ifndef FUTBOLISTA_H
#define FUTBOLISTA_H


#include "Deportista.h"
#include <iostream>
#include <string>


class Futbolista: public Deportista {
    /* Futbolistas hereda de Deportista, por lo que no es necesario
     declarar los atributos de Deportista nuevamente.
    Los atributos de Deportista son accesibles en Futbolistas
    */
    private:
        std::string posicion;
        int golesMarcados, asistencias, faltas, tarjetasAmarillas, tarjetasRojas; 

        static const int MAX_FUTBOLISTAS = 6;
        static int cantidadFutbolistas;
        static Futbolista futbolistas[MAX_FUTBOLISTAS];
    public:
        void setPosicion(std::string posicion);
        std::string getPosicion();
        void setGolesMarcados(int golesMarcados);
        int getGolesMarcados();
        void setAsistencias(int asistencias);
        int getAsistencias();
        void setFaltas(int faltas);
        int getFaltas();
        void setTarjetasAmarillas(int tarjetasAmarillas);
        int getTarjetasAmarillas();
        void setTarjetasRojas(int tarjetasRojas);
        int getTarjetasRojas();
        

        static bool registrarFutbolista();
        static void modificarFutbolista(const std::string codigo);
        void mostrarDatos();
        static Futbolista* obtenerMejorGoleador();
        static Futbolista* obtenerMejorAsistente();
        static Futbolista* obtenerMayorFaltas();
    protected:
        
};

#endif 