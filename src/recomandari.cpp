#include "recomandari.h"
#include "ascultator.h"
#include "spotify.h"
void Recomandari::printRecomandari() {
    Ascultator* ascultator = dynamic_cast<Ascultator*>(this);
    std::cout << "Recomandare pentru: " << ascultator->getNume() << "\n";
    std::vector<Recomandare> recomandri;
    Spotify::Instance();
}