#ifndef CONCENTRESE_H
#define CONCENTRESE_H

#include "Juego.h"
#include "Base.h"

class Concentrese : public Juego {
private:
    Base base;

public:
    Concentrese(Jugador* j1, Jugador* j2);
    ~Concentrese() override;
    void jugar() override;
};

#endif
