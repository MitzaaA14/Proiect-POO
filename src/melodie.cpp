#include "melodie.h"

void Melodie::print() {
    std::cout << "Melodie - ID: " << getId()
              << " - Nume: " << getNume()
              << " (album: " << autor
              << ") : " << durataSecunde << "s\n";
};