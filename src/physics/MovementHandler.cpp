/*
    -------------------------
    MovementHandler.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/physics/MovementHandler.hpp"
#include <SFML/System/Vector2.hpp>
#include <chrono>

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


void MovementHandler::update(std::chrono::nanoseconds timeDifference) {
    //Pour x:
    speed_.x += acceleration_.x * timeDifference;

    position_.x +=  speed_.x * timeDifference;

    //Pour y:
    speed_.y += acceleration_.y * timeDifference;

    position_.y +=  speed_.y * timeDifference;
}