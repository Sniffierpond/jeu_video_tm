/*
    -------------------------
    Player.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/game/Player.hpp"

Player::Player(sf::Vector2f position): animationHandler_(playerAnimation_) {
    movementHandler_.setPosition(position);
}


Player::Status& Player::status() {
    return status_;
}

const Player::Status& Player::status() const {
    return status_;
}


MovementHandler& Player::movementHandler() {
    return movementHandler_;
}

const MovementHandler& Player::movementHandler() const {
    return movementHandler_;
}


AnimationHandler& Player::animationHandler() {
    return animationHandler_;
}

const AnimationHandler& Player::animationHandler() const {
    return animationHandler_;
}


std::string Player::getTextureId() {
    return animationHandler_.getTextureId();
}

std::string Player::getTextureId() const {
    return animationHandler_.getTextureId();
}

const SimpleAnimation Player::playerAnimation_ = []{
    SimpleAnimation animation(std::chrono::milliseconds(500));

    animation.addFrame("base:player:walking:1")
    .addFrame("base:player:walking:2")
    .addFrame("base:player:walking:3")
    .addFrame("base:player:walking:2");
    
    return animation;
}();