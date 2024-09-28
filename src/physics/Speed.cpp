/*
    -------------------------
    Speed.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/physics/Speed.hpp"
#include "../../include/physics/Acceleration.hpp"
#include <cmath>
#include <SFML/System/Vector2.hpp>

Speed::Speed(float distance, std::chrono::nanoseconds duration) {
    speed_ = distance / duration.count() * 1'000'000'000;
}

Speed::Speed(float speed, Unit unit) {
    switch (unit) {
    case bps:
        speed_ = speed;
        break;
    case bph:
        speed_ = speed / 3600;
        break;
    case kbps:
        speed_ = speed * 1000;
        break;
    case kbph:
        speed_ = speed / 3.6;
        break;
    }
}


float Speed::getSpeed(Unit unit) const {
    switch (unit) {
    case bps:
        return speed_;
    case bph:
        return speed_ * 3600;
    case kbps:
        return speed_ / 1000;
    case kbph:
        return speed_ * 3.6;
    }
}


Speed operator-(const Speed& s) {
    return s * -1;
}

Speed& Speed::operator+=(const Speed& s) {
    return *this = *this + s;
}

Speed& Speed::operator-=(const Speed& s) {
    return *this = *this - s;
}

Speed& Speed::operator*=(float f) {
    return *this = *this * f;
}

Speed& Speed::operator/=(float f) {
    return *this = *this / f;
}


Speed operator+(const Speed& s1, const Speed& s2) {
    return Speed(s1.getSpeed(Speed::bps) + s2.getSpeed(Speed::bps), Speed::bps);
}

Speed operator-(const Speed& s1, const Speed& s2) {
    return Speed(s1.getSpeed(Speed::bps) - s2.getSpeed(Speed::bps), Speed::bps);
}


Speed operator*(const Speed& s1, float f) {
    return Speed(s1.getSpeed(Speed::bps) * f, Speed::bps);
}

Speed operator/(const Speed& s1, float f) {
    return Speed(s1.getSpeed(Speed::bps) / f, Speed::bps);
}


float operator*(const Speed& s1, std::chrono::nanoseconds duration) {
    return s1.getSpeed(Speed::bps) * duration.count() / 1'000'000'000;
}

Acceleration operator/(const Speed& s1, std::chrono::nanoseconds duration) {
    return Acceleration(s1.getSpeed(Speed::bps) / duration.count() * 1'000'000'000, Acceleration::bps2);
}


std::ostream& operator<<(std::ostream& os, const Speed& speed) {
    return os << speed.getSpeed(Speed::bps) << "b/s";
}


Speed operator"" _bps(long double speed) {
    return Speed(speed, std::chrono::seconds(1));
}

Speed operator"" _kbph(long double speed) {
    return Speed(1000 * speed, std::chrono::hours(1));
}


namespace std {
    Speed pow(Speed x, float y) {
        return Speed(std::pow(x.getSpeed(Speed::bps), y), Speed::bps);
    }
    
    Speed sqrt(Speed x) {
        return std::pow(x, 0.5);
    }
}
