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

class Player: Drawable, Movable/*, Animable*/ {
    private:
    MovementHandler movementHandler_;
    //AnimationHandler animationHandler_;

    public:
    enum Status {
        STANDING,
        WALKING,
        JUMPING,
        FALLING
    };

    //const static Animation playerAnimation_;
    
    Player(sf::Vector2f position);
    
    Status& status();
    const Status& status() const;

    MovementHandler& movementHandler() override;
    const MovementHandler& movementHandler() const;
    
    //AnimationHandler& animationHandler() override;
    //const AnimationHandler& animationHandler() const;

    std::string getTextureId() override;

    private:
    Status status_;
};
