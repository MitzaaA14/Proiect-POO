#ifndef OOP_RECOMANDARI_H
#define OOP_RECOMANDARI_H

#include <iostream>
#include "container.h"
#include "melodie.h"

class Ascultator;

class Recomandari {
private:
    Container<Melodie> melodiiAscultate;
public:
    virtual ~Recomandari() {}
    void asculta(const Melodie& m);
    Container<Melodie> getMelodiiAscultate() {
        melodiiAscultate.resetIterator();
        return melodiiAscultate;
    }
    void printRecomandari();
};



#endif