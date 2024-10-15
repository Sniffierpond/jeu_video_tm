/*
    -------------------------
    BlockGrid.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include "../contracts/Drawable.hpp"
#include "../contracts/Movable.hpp"
#include "../contracts/Animable.hpp"
#include "../graphics/PlayerAnimationHandler.hpp"

class Player: Drawable, Movable, Animable {
    private:
    MovementHandler movementHandler_;
    PlayerAnimationHandler animationHandler_;

    public:
    enum Status {
        STANDING,
        WALKING,
        JUMPING,
        FALLING
    };
    
    Player(sf::Vector2f position);
    
    Status& status();
    const Status& status() const;

    MovementHandler& movementHandler() override;
    const MovementHandler& movementHandler() const;
    
    AnimationHandler& animationHandler() override;
    const AnimationHandler& animationHandler() const;

    std::string getTextureId() override;
    std::string getTextureId() const;

    private:
    Status status_;
};
