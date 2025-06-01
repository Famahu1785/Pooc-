#ifndef GATO_H
#define GATO_H

#include "Animal.h"
#include <iostream>


class Gato : public Animal {
    
    private:
    
    public:
        Gato();
        void hacerSonido() override {
            std::cout << "Miau" << std::endl;
        }


};

#endif // GATO_H



