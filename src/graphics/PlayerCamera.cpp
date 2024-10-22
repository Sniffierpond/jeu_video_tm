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
    auto playerPos = player_.get().movementHandler().getPosition();
    position_ = {playerPos.x, playerPos.y + 1};
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
    if (!paused_) {
        auto playerPos = player_.get().movementHandler().getPosition();
        position_ = {playerPos.x, playerPos.y + 1};
    }

    if (position_.x - width_ / 2 < 0)
        position_.x = width_ / 2;
    else if (position_.x + width_ / 2 >= levelWidth_)
        position_.x = levelWidth_ - width_ / 2;

    if (position_.y - height_ / 2 < 0)
        position_.y = height_ / 2;
    else if (position_.y + height_ / 2 >= levelHeight_)
        position_.y = levelHeight_ - height_ / 2;
}

void PlayerCamera::pause() {
    paused_ = true;
}

void PlayerCamera::resume() {
    paused_ = false;
}