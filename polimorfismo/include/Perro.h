#ifndef PERRO_H
#define PERRO_H

#include "Animal.h"
#include <iostream>


class Perro : public Animal {
    
    private:
    
    public:
        Perro();
        void hacerSonido() override {
            std::cout << "Guau" << std::endl;
        }


};

#endif // GATO_H