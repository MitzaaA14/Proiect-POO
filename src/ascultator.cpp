#include "ascultator.h"

void Ascultator::print() {
    std::cout << "ID: " << getId()
              << " - Nume: " << getNume()
              << " (isVIP: " << isVIP << ")\n";

    auto ma = getMelodiiAscultate();
    std::cout << "Melodii ascultate: (total: " << ma.size() << ")\n";
    ma.print();

    std::cout << "Melodii recomandate:" << "\n";
    printRecomandari();

    std::cout << "===========================\n";
};