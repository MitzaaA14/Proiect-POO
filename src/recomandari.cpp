#include "recomandari.h"
#include "ascultator.h"
#include "spotify.h"
#include "melodiiascultate.h"

void Recomandari::printRecomandari() {
    const Ascultator* ascultatorCurent = dynamic_cast<const Ascultator*>(this);

    MelodiiAscultate rc;

    Container<Ascultator> ascultatori = Spotify::Instance()->getAscultatori();
    Ascultator altAscultator;
    Melodie melodieAscultata;

    ascultatori.resetIterator();
    melodiiAscultate.resetIterator();

    while(melodiiAscultate >> melodieAscultata) {
        rc += melodieAscultata;

        while(ascultatori >> altAscultator) {
            bool acelasiAscultator = ascultatorCurent->getId() == altAscultator.getId();
            if (acelasiAscultator) {
                continue;
            }

            Container<Melodie> melodiiAltAscultator = altAscultator.getMelodiiAscultate();
            melodiiAltAscultator.resetIterator();

            std::optional<Melodie>  melodieAltAscultator = melodiiAltAscultator.cautaId(melodieAscultata.getId());

            if (melodieAltAscultator.has_value()) {
                rc += melodieAscultata;
                rc += melodieAscultata;
            }
        }
    }

    rc.print();
}

void Recomandari::asculta(const Melodie& m) {
    melodiiAscultate << m;
}