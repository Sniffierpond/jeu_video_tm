/*
    -------------------------
    Acceleration.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include "Speed.hpp"
#include <chrono>

class Acceleration {
    private:
    float acceleration_;
    public:
    enum Unit {bps2, bph2, kbps2, kbph2};

    Acceleration() = default;
    Acceleration(Speed speed, std::chrono::nanoseconds duration);
    Acceleration(float acceleration, Unit unit);

    /*
    Retourne la vitesse dans l'unité indiquée.
    */
    float getAcceleration(Unit unit) const;

    Acceleration& operator+=(const Acceleration& a);
    Acceleration& operator-=(const Acceleration& a);
    Acceleration& operator*=(float f);
    Acceleration& operator/=(float f);
};

Acceleration operator-(const Acceleration& a);

Acceleration operator+(const Acceleration& a1, const Acceleration& a2);
Acceleration operator-(const Acceleration& a1, const Acceleration& a2);

Acceleration operator*(const Acceleration& a, float f);
Acceleration operator/(const Acceleration& a, float f);

Speed operator*(const Acceleration& a, std::chrono::nanoseconds nanoseconds);

std::ostream& operator<<(std::ostream& os, const Acceleration& acceleration);

/*
Retourne une accélération en blocs par seconde au carré.
*/
Acceleration operator"" _bps2(long double acceleration);

/*
Retourne une accélération en "kiloblocs" par heure au carré (un "kilobloc" étant équivalent à mille blocs).
*/
Acceleration operator"" _kbph2(long double acceleration);