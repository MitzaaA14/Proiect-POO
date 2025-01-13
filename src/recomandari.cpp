#include "recomandari.h"
#include "ascultator.h"
#include "spotify.h"
#include "melodiiascultate.h"

void Recomandari::printRecomandari() {
    const Ascultator* ascultatorCurent = dynamic_cast<const Ascultator*>(this);

    MelodiiAscultate rc;

    Melodie melodieAscultata; //adaugare melodii ascultate de ascultatorul curent (+1)
    melodiiAscultate.resetIterator();
    while(melodiiAscultate >> melodieAscultata) {
        rc += melodieAscultata;
    }

    //adaugam +2 daca ascultatorul este altul
    Container<Ascultator> ascultatori = Spotify::Instance()->getAscultatori();
    Ascultator altAscultator;

    for(auto m : melodiiAscultate.getUnice() ) {
        ascultatori.resetIterator();

        while(ascultatori >> altAscultator) {
            bool acelasiAscultator = ascultatorCurent->getId() == altAscultator.getId();
            if (acelasiAscultator) {
                continue;
            }

            Container<Melodie> melodiiAltAscultator = altAscultator.getMelodiiAscultate();
            melodiiAltAscultator.resetIterator();

            std::optional<Melodie>  melodieAltAscultator = melodiiAltAscultator.cautaId(m.getId());
            if (melodieAltAscultator.has_value()) {
                rc += m;
                rc += m;
            }
        }
    }

    rc.print();
}

void Recomandari::asculta(const Melodie& m) {
    melodiiAscultate << m;
}