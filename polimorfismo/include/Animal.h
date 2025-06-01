#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>


class Animal {
    protected:
        std::string nombre;
        int edad;
    
    private:
    
    public:
    
    protected:
    virtual void hacerSonido() = 0;
};
#endif // ANIMAL_H