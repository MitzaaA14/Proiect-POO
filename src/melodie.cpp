#include "melodie.h"
void Melodie::print() {
    std::cout << "ID: " << getId()
              << " - Nume: " << getNume()
              << " (album: " << autor
              << ") : " << durataSecunde << "s\n";
};