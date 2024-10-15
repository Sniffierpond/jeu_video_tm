/*
    -------------------------
    PlayerAnimationHandler.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include "AnimationHandler.hpp"
#include "playerAnimations.hpp"

class Player;

class PlayerAnimationHandler: public AnimationHandler {
    private:
    const Player* const player_;
    mutable SimpleAnimation currentAnimation_ = playerAnimations::walkingLeft;

    public:
    PlayerAnimationHandler(const Player& player);

    std::string getTextureId() const override;

    void update(std::chrono::nanoseconds timeDifference) override;
};