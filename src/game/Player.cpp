/*
    -------------------------
    Player.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include "../../include/game/Player.hpp"

Player::Player(sf::Vector2f position)/*: animationHandler_(playerAnimation_)*/ {
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


std::string Player::getTextureId() {
    return "base:player";
}

/* const Animation Player::playerAnimation_ = []{
    Animation animation(std::chrono::milliseconds(500));

    animation.addFrame("base:player:1")
    .addFrame("base:player:2")
    .addFrame("base:player:3")
    .addFrame("base:player:4");
    
    return animation;
}(); */