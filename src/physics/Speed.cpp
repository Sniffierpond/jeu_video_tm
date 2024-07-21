/*
    -------------------------
    Speed.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/physics/Speed.hpp"
#include <SFML/System/Vector2.hpp>

Speed operator"" _bps(long double speed) {
    return Speed(speed, std::chrono::seconds(1));
}

Speed operator"" _kbph(long double speed) {
    return Speed(1000 * speed, std::chrono::hours(1));
}
