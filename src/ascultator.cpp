#include "ascultator.h"
void Ascultator::print() {
    std::cout << "ID: " << getId()
              << " - Nume: " << getNume()
              << " (isVIP: " << isVIP << ")\n";
};