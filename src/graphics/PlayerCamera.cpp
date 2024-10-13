/*
    -------------------------
    PlayerCamera.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/graphics/PlayerCamera.hpp"

PlayerCamera::PlayerCamera(Player& player, float width, float height, unsigned int levelWidth, unsigned int levelHeight): 
    player_(player),
    width_(width),
    height_(height),
    levelWidth_(levelWidth),
    levelHeight_(levelHeight)
{
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
    if (!paused_)
        position_ = player_.get().movementHandler().getPosition();

    if (position_.x - width_ / 2 < 0)
        position_.x = width_ / 2;
    else if (position_.x + width_ / 2 >= levelWidth_)
        position_.x = levelWidth_ - 1 - width_ / 2;

    if (position_.y - height_ / 2 < 0)
        position_.y = height_ / 2;
    else if (position_.y + height_ / 2 >= levelHeight_)
        position_.y = levelHeight_ - 1 - height_ / 2;
}

void PlayerCamera::pause() {
    paused_ = true;
}

void PlayerCamera::resume() {
    paused_ = false;
}