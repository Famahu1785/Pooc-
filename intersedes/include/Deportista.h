#ifndef DEPORTISTA_H
#define DEPORTISTA_H

#include <iostream>
#include <string>

/*
Esta es la superclase que hereda los atributos base a los
deportistas
*/ 

class Deportista {
    private:

    public:
        void setNombre(std::string nombre);
        std::string getNombre();
        void setCedula(std::string cedula);
        std::string getCedula();
        void setCodigo(std::string codigo);
        std::string getCodigo();
        void setSexo(std::string sexo);
        std::string getSexo();
        void setEdad(int edad);
        int getEdad();
        void setPrograma(int programa);
        int getPrograma();
        void setCantParticipantes(int cantparticipantes);
        int getCantParticipantes();

    protected:
        std::string nombre, cedula, codigo, sexo;
        int edad, programa, cantparticipantes; 
};

#endif 

/*Los 6 futbolistas, 7 basketbolistas y 2 de natacion
1) crearlos
2) Modificarlos
3) Mostrar goleador / o con mas puntos en basket
4) Mostrar mas faltas
5) Promedio  de tiempos natacion
6) Mostrar con mas asistencias

*/