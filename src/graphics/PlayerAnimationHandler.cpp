/*
    -------------------------
    PlayerAnimationHandler.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/graphics/PlayerAnimationHandler.hpp"
#include "../../include/game/Player.hpp"
#include <chrono>

PlayerAnimationHandler::PlayerAnimationHandler(const Player& player): player_(&player), AnimationHandler(currentAnimation_) {}

std::string PlayerAnimationHandler::getTextureId() const {
    float playerSpeed = player_->movementHandler().getSpeed().x.getSpeed(Speed::bps);
    int playerDirection = playerSpeed == 0 ? 0 : playerSpeed / std::abs(playerSpeed);

    if (playerSpeed == 0) {
        return "base:player:idle";
    }
    else {
        return AnimationHandler::getTextureId();
    }
}

void PlayerAnimationHandler::update(std::chrono::nanoseconds timeDifference) {
    float playerSpeed = player_->movementHandler().getSpeed().x.getSpeed(Speed::bps);
    int playerDirection = playerSpeed == 0 ? 0 : playerSpeed / std::abs(playerSpeed);

    if (playerDirection < 0) {
        currentAnimation_ = playerAnimations::walkingLeft;
    }
    else {
        currentAnimation_ = playerAnimations::walkingRight;
    }

    if (player_->status() != Player::JUMPING && player_->status() != Player::FALLING) {
        AnimationHandler::update(timeDifference);
    }

    if (player_->status() == Player::STANDING) {
        timeElapsed_ = std::chrono::nanoseconds(0);
    }
}