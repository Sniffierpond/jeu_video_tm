/*
    -------------------------
    Acceleration.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include "Speed.hpp"
#include <chrono>
#include <utility>

using Acceleration = std::pair<Speed, std::chrono::seconds>;

/*
Retourne une accélération en blocs par seconde au carré.
*/
Acceleration operator"" _bps2(long double speed);

/*
Retourne une accélération en "kiloblocs" par heure au carré (un "kilobloc" étant équivalent à mille blocs).
*/
Acceleration operator"" _kbph2(long double speed);