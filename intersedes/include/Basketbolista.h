#ifndef BASKETBOLISTA_H
#define BASKETBOLISTA_H

#include "Deportista.h"
#include <iostream>
#include <string>

class Basketbolista: public Deportista {
    private:
        std::string posicion;
        int puntos, asistencias, rebotes, faltas, tirosLibres, tirosDeCampo; 
        static const int MAX_BASKETBOLISTAS = 7;
        static int cantidadBasketbolistas;
        static Basketbolista basketbolistas[MAX_BASKETBOLISTAS]; // Arreglo estático de basketbolistas

    public:
        void setPosicion(std::string posicion);
        std::string getPosicion();
        void setPuntos(int puntos);
        int getPuntos();
        void setAsistencias(int asistencias);
        int getAsistencias();
        void setRebotes(int rebotes);
        int getRebotes();
        void setFaltas(int faltas);
        int getFaltas();
        void setTirosLibres(int tirosLibres);
        int getTirosLibres();
        void setTirosDeCampo(int tirosDeCampo);
        int getTirosDeCampo();

        static bool registrarBasketbolista(Basketbolista& b);
        static bool modificarBasketbolistaPorCodigo(const std::string& codigo);
        static Basketbolista* obtenerMejorPuntero(); 
        static Basketbolista* obtenerMejorAsistente();
        static Basketbolista* obtenerMayorFaltas();
        void mostrarDatos() const;
};

#endif
