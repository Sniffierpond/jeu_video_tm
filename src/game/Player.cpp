/*
    -------------------------
    Player.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/game/Player.hpp"

Player::Player(sf::Vector2f position): animationHandler_(*this) {
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
