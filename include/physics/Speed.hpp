/*
    -------------------------
    Speed.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include <SFML/System/Vector2.hpp>
#include <chrono>
#include <iostream>

class Acceleration;

class Speed {
    private:
    float speed_;
    public:
    enum Unit {bps, bph, kbps, kbph};

    Speed() = default;
    Speed(float distance, std::chrono::nanoseconds duration);
    Speed(float speed, Unit unit);

    /*
    Retourne la vitesse dans l'unité indiquée.
    */
    float getSpeed(Unit unit) const;

    Speed& operator+=(const Speed& v);
    Speed& operator-=(const Speed& v);
    Speed& operator*=(float f);
    Speed& operator/=(float f);
};

Speed operator-(const Speed& s);

Speed operator+(const Speed& s1, const Speed& s2);
Speed operator-(const Speed& s1, const Speed& s2);

Speed operator*(const Speed& s, float f);
Speed operator/(const Speed& s, float f);

float operator*(const Speed& s, std::chrono::nanoseconds duration);
Acceleration operator/(const Speed& s, std::chrono::nanoseconds duration);

std::ostream& operator<<(std::ostream& os, const Speed& speed);

/*
Retourne une vitesse en blocs par seconde.
*/
Speed operator"" _bps(long double speed);

/*
Retourne une vitesse en "kiloblocs" par heure (un "kilobloc" étant équivalent à mille blocs).
*/
Speed operator"" _kbph(long double speed);

namespace std {
    Speed pow(Speed x, float y);
    Speed sqrt(Speed x);
}