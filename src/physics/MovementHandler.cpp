/*
    -------------------------
    MovementHandler.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/physics/MovementHandler.hpp"
#include <SFML/System/Vector2.hpp>

sf::Vector2f MovementHandler::getPosition() const {
    return position_;
}

void MovementHandler::setPosition(sf::Vector2f position) {
    position_ = position;
}


void MovementHandler::setSpeed(sf::Vector2<Speed> speed) {
    speed_ = speed;
}

sf::Vector2<Speed> MovementHandler::getSpeed() const {
    return speed_;
}


void MovementHandler::addSpeed(sf::Vector2<Speed> speed) {
    speed_ += speed;
}


void MovementHandler::setAcceleration(sf::Vector2<Acceleration> acceleration) {
    acceleration_ = acceleration;
}

sf::Vector2<Acceleration> MovementHandler::getAcceleration() const {
    return acceleration_;
}


void MovementHandler::update(std::chrono::milliseconds timeDifference) {
    /*
    Formules utilisées:
    Augmentation de la vitesse avec l'accélération:
    d1 / t1 + ((d2 / t2) / t3) * t4 = d1 / t1 + (d2 / (t2 / t4)) / t3
    = d1 / t1 + ((d2 / (t2 / t4)) * (t1 / t3)) / (t3 * (t1 / t3))
    = d1 / t1 + (d2 / ((t2 / t4) * (t3 / t1))) / (t3 * (t1 / t3))
    = (d1 + d2 / ((t2 / t4) * (t3 / t1))) / t1

    Changement de la position du joueur grâce à  la vitesse:
    d1 + d2 / t1 * t2 = d1 + d2 * (t1 / t2)

    NOTE: les termes utilisés ne sont pas les mêmes dans la première équation et dans la deuxième équation.
    */

    //Pour x:
    speed_.x.first += acceleration_.x.first.first / ((acceleration_.x.first.second / timeDifference) * (acceleration_.x.second / speed_.x.second));

    position_.x += speed_.x.first * (speed_.x.second / timeDifference);

    //Pour y:
    speed_.y.first += acceleration_.y.first.first / ((acceleration_.y.first.second / timeDifference) * (acceleration_.y.second / speed_.y.second));

    position_.y += speed_.y.first * (speed_.y.second / timeDifference);
}