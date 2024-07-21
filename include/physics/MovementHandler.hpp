/*
    -------------------------
    MovementHandler.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include <SFML/System/Vector2.hpp>
#include "../contracts/Updatable.hpp"
#include "Speed.hpp"
#include "Acceleration.hpp"

class MovementHandler: Updatable {
    private:
    sf::Vector2f position_;

    sf::Vector2<Speed> speed_;

    sf::Vector2<Acceleration> acceleration_;

    public:
    sf::Vector2f getPosition() const;
    void setPosition(sf::Vector2f position);

    void setSpeed(sf::Vector2<Speed> speed);
    sf::Vector2<Speed> getSpeed() const;

    void addSpeed(sf::Vector2<Speed> speed);

    void setAcceleration(sf::Vector2<Acceleration> acceleration);
    sf::Vector2<Acceleration> getAcceleration() const;

    void update(std::chrono::milliseconds timeDifference) override;
};