#include <iostream>
#include "spotify.h"

int main() {
    std::cout << "Spotify, recomandari melodii!\n";

    int nr, melodiiAscultate;
    std::string ascultator, esteVip;

    std::cout << "Cate melodii introduceti?: ";

    std::cin >> nr;
    std::cin.ignore();

    Spotify* sp = Spotify::Instance();

    for(int i = 0; i < nr; ++i) {
        std::string melodie, autor;
        int durata;

        std::cout << "Melodie:\n";
        getline(std::cin, melodie);

        std::cout << "Autor:\n";
        getline(std::cin, autor);

        std::cout << "Durata (s):\n";
        std::cin >> durata;
        std::cin.ignore();

        sp->addMelodie(Melodie(melodie, autor, durata));
    }

    sp->getMelodii().print();

    std::cout << "\nCati utilizatori introduceti?: ";
    std::cin >> nr;
    std::cin.ignore();

    for(int i = 0; i < nr; ++i) {
        std::cout << "Ascultator:\n";
        getline(std::cin, ascultator);

        std::cout << "este vip? (da/nu):\n";
        getline(std::cin, esteVip);

        bool esteVipBool = esteVip.compare("da") == 0;
        Ascultator a = Ascultator(ascultator, esteVipBool);

        std::cout << "Cate melodii a ascultat?: \n";

        std::cin >> melodiiAscultate;
        std::cin.ignore();

        std::cout << "ID melodie (de mai sus)?:\n";
        int idMelodie;
        for(int mi = 0; mi < melodiiAscultate; ++mi) {
            std::cout << "ID ascultare nr " << mi+1 << ": ";
            std::cin >> idMelodie;
            std::cin.ignore();

            std::optional<Melodie> m = sp->getMelodii().cautaId(idMelodie);
            if (!m.has_value()) {
                mi--;
                std::cout << "Melodia cu id: " << idMelodie << " nu a fost gasita\n";
                continue;
            }

            a.asculta(*m);
        }

        sp->addAscultator(a);
    }

    auto ascultatori = sp->getAscultatori();
    Ascultator a;

    std::cout << "\n\n================================================================\nrezultate \n";

    while(ascultatori >> a) {
        a.print();
    }

    sp->printStatistici();

    return 0;
}