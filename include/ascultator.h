#ifndef OOP_ASCULTATOR_H
#define OOP_ASCULTATOR_H

#include <iostream>
#include "common.h"

class Ascultator : public Nume {
private:
    bool isVIP;
public:
    Ascultator() : Nume() {}

    Ascultator(std::string nume) : Nume(nume) {}
    Ascultator(std::string nume, bool isVIP): Nume(nume), isVIP(isVIP) {}

    virtual ~Ascultator() {};

    void print() override;
};
#endif