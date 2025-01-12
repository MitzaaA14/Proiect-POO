#ifndef OOP_ASCULTATOR_H
#define OOP_ASCULTATOR_H

#include <iostream>
#include "common.h"
#include "recomandari.h"
#include "melodie.h"

class Ascultator : public Nume, public Recomandari {
private:
    bool isVIP;
public:
    Ascultator() : Nume(), isVIP(true) {}
    explicit Ascultator(const std::string& nume) : Nume(nume), isVIP(false) {}
    Ascultator(const std::string& nume, bool isVIP): Nume(nume), isVIP(isVIP) {}

    virtual ~Ascultator() override {};

    void print() override;
};

#endif