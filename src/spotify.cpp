#include "spotify.h"
#include "container.h"
#include "melodiiascultate.h"

Spotify* Spotify::instance = nullptr;

Spotify* Spotify::Instance() {
    if (instance == nullptr) {
        instance = new Spotify();
    }

    return instance;
}

void Spotify::printStatistici() {
    Ascultator a;
    Melodie tm, m;
    MelodiiAscultate rc(0);

    while(melodii >> tm) {
        rc += tm;

        while(ascultatori >> a) {
            auto melodiiAscultate = a.getMelodiiAscultate();

            while(melodiiAscultate >> m) {
                rc += m;
            }
        }
    }

    std::cout << "\n=======================Statistica ascultare melodii =====================================\n";

    rc.print();
}