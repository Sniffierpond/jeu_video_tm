/*
    -------------------------
    Speed.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include <SFML/System/Vector2.hpp>
#include <chrono>
#include <utility>

using Speed = std::pair<float, std::chrono::seconds>;

/*
Retourne une vitesse en blocs par seconde.
*/
Speed operator"" _bps(long double speed);

/*
Retourne une vitesse en "kiloblocs" par heure (un "kilobloc" étant équivalent à mille blocs).
*/
Speed operator"" _kbph(long double speed);

