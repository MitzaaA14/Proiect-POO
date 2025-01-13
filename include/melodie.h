#ifndef OOP_MELODIE_H
#define OOP_MELODIE_H

#include <iostream>
#include "common.h"

class Melodie: public Nume {
    private:
        std::string autor;
        int durataSecunde;
    public: 
        Melodie() {}
        Melodie(const std::string& nume, std::string autor, int durataSecunde)
            : Nume(nume), autor(autor), durataSecunde(durataSecunde) {}

        virtual ~Melodie() override {};

        void print() override;
};

#endif