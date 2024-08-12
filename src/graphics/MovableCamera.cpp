/*
    -------------------------
    MovableCamera.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/graphics/MovableCamera.hpp"

MovableCamera::MovableCamera(sf::Vector2f position, float width, float height): width_(width), height_(height) {
    movementHandler_.setPosition(position);
}


sf::Vector2f MovableCamera::getPosition() const {
    return movementHandler_.getPosition();
}


float MovableCamera::getWidth() const {
    return width_;
}

float MovableCamera::getHeight() const {
    return height_;
}


MovementHandler& MovableCamera::movementHandler() {
    return movementHandler_;
}

const MovementHandler& MovableCamera::movementHandler() const {
    return movementHandler_;
}