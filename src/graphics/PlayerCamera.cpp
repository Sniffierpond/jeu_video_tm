/*
    -------------------------
    PlayerCamera.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/graphics/PlayerCamera.hpp"

PlayerCamera::PlayerCamera(Player& player, float width, float height): player_(player), width_(width), height_(height) {
    position_ = player_.get().movementHandler().getPosition();
}


sf::Vector2f PlayerCamera::getPosition() const {
    return position_;
}


float PlayerCamera::getWidth() const {
    return width_;
}

float PlayerCamera::getHeight() const {
    return height_;
}


void PlayerCamera::update(std::chrono::nanoseconds timeDifference) {
    position_ = player_.get().movementHandler().getPosition();
}