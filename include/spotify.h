#ifndef OOP_SPOTIFY_H
#define OOP_SPOTIFY_H
#include "container.h"
#include "melodie.h"
#include "ascultator.h"

class Spotify {
private:
    Spotify() {};
    Spotify(const Spotify&) = delete;
    Spotify& operator=(const Spotify&) = delete;
    static Spotify* instance;

    Container<Melodie> melodii;
    // Container<Ascultator> ascultatori;
public:
    static Spotify* Instance();
};
#endif