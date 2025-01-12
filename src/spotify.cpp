#include "spotify.h"

Spotify* Spotify::instance = nullptr;

Spotify* Spotify::Instance() {
    if (instance == nullptr) {
        instance = new Spotify();
    }
    return instance;
}