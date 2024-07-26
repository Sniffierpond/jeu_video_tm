/*
    -------------------------
    Acceleration.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/physics/Acceleration.hpp"

Acceleration::Acceleration(Speed speed, std::chrono::nanoseconds duration) {
    acceleration_ = speed.getSpeed(Speed::bps) / duration.count() * 1'000'000'000; 
}

Acceleration::Acceleration(float acceleration, Unit unit) {
    switch (unit) {
    case bps2:
        acceleration_ = acceleration;
        break;
    case bph2:
        acceleration_ = acceleration / 3600 / 3600;
        break;
    case kbps2:
        acceleration_ = acceleration * 1000 * 1000;
        break;
    case kbph2:
        acceleration_ = acceleration / 3.6 / 3.6;
        break;
    }
}


float Acceleration::getAcceleration(Unit unit) const {
    switch (unit) {
    case bps2:
        return acceleration_;
    case bph2:
        return acceleration_ * 3600 * 3600;
    case kbps2:
        return acceleration_ / 1000 / 1000;
    case kbph2:
        return acceleration_ * 3.6 * 3.6;
    }
}


Acceleration operator-(const Acceleration& a) {
    return a * -1;
}


Acceleration& Acceleration::operator+=(const Acceleration& a) {
    return *this = *this + a;
}

Acceleration& Acceleration::operator-=(const Acceleration& a) {
    return *this = *this - a;
}

Acceleration& Acceleration::operator*=(float f) {
    return *this = *this * f;
}

Acceleration& Acceleration::operator/=(float f) {
    return *this = *this / f;
}


Acceleration operator+(const Acceleration& a1, const Acceleration& a2) {
    return Acceleration(a1.getAcceleration(Acceleration::bps2) + a2.getAcceleration(Acceleration::bps2), Acceleration::bps2);
}

Acceleration operator-(const Acceleration& a1, const Acceleration& a2) {
    return Acceleration(a1.getAcceleration(Acceleration::bps2) - a2.getAcceleration(Acceleration::bps2), Acceleration::bps2);
}


Acceleration operator*(const Acceleration& a, float f) {
    return Acceleration(a.getAcceleration(Acceleration::bps2) * f, Acceleration::bps2);
}

Acceleration operator/(const Acceleration& a, float f) {
    return Acceleration(a.getAcceleration(Acceleration::bps2) / f, Acceleration::bps2);
}


Speed operator*(const Acceleration& a, std::chrono::nanoseconds duration) {
    return Speed(a.getAcceleration(Acceleration::bps2) * duration.count() / 1'000'000'000, Speed::bps);
}


std::ostream& operator<<(std::ostream& os, const Acceleration& acceleration) {
    return os << acceleration.getAcceleration(Acceleration::bps2) << "b/s²";
}


Acceleration operator"" _bps2(long double acceleration) {
    return Acceleration(Speed(acceleration, std::chrono::seconds(1)), std::chrono::seconds(1));
}

Acceleration operator"" _kbps2(long double acceleration) {
    return Acceleration(Speed(1000 * acceleration, std::chrono::hours(1)), std::chrono::hours(1));
}