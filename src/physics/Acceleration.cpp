/*
    -------------------------
    Acceleration.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/physics/Acceleration.hpp"

Acceleration operator"" _bps2(long double speed) {
    return Acceleration(Speed(speed, std::chrono::seconds(1)), std::chrono::seconds(1));
}

Acceleration operator"" _kbps2(long double speed) {
    return Acceleration(Speed(1000 * speed, std::chrono::hours(1)), std::chrono::hours(1));
}