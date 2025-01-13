#ifndef OOP_MELODIIASCULTATE_H
#define OOP_MELODIIASCULTATE_H

#include <iostream>
#include "melodie.h"

class MelodiiAscultate{
    private:
        class MelodieAscultata {
            private: 
                Melodie melodie;
                int scor;
            
            public:
                MelodieAscultata(const Melodie& melodie, int scor) : melodie(melodie), scor(scor) {}
                void print() const {
                    std::cout << "Melodie: " << melodie.getNume() << " - scor: " << scor << "\n";
                }

                int getScor() const {
                    return scor;
                }

                const Melodie& getMelodie() const {
                    return melodie;
                }

                MelodieAscultata& operator++() {
                    ++scor;
                    return *this;
                }
        };

        std::vector<MelodieAscultata> recomandri;
        int scorInitial;

    public:
        MelodiiAscultate() { scorInitial = 1; }
        explicit MelodiiAscultate(const int scorInitial) : scorInitial(scorInitial) {}

        void print() {
            std::sort(recomandri.begin(), recomandri.end(), [](const MelodieAscultata& a, const MelodieAscultata& b) {
                return a.getScor() > b.getScor();
            });

            for (const auto& recomandare : recomandri) {
                recomandare.print();
            }
        }

        MelodiiAscultate& operator+=(const Melodie& melodie) {
            for (auto& recomandare : recomandri) { 
                if (recomandare.getMelodie().getId() == melodie.getId()) {
                    ++recomandare;

                    return *this;
                }
            }

            recomandri.emplace_back(melodie, scorInitial);
            return *this;
        }                
};
#endif