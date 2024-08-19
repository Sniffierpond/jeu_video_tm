/*
    -------------------------
    PlayingGameState.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/core/PlayingGameState.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

PlayingGameState::PlayingGameState(const TextureRegistry& textureRegistry, const Level& level, sf::RenderWindow& window): 
    level_(level),
    camera_(sf::Vector2f(0, 0),16, 9), 
    renderer_(level, camera_, textureRegistry),
    viewable_(window, renderer_, window.getSize().x, window.getSize().y, sf::Vector2i(0, 0)),
    inputHandler_(window),
    controller_(camera_, inputHandler_, viewable_)
{}

void PlayingGameState::start() {
    active_ = true;
}


bool PlayingGameState::active() {
    return active_;
}


void PlayingGameState::update() {
    if (active()) {
        if (paused()) {
            controller_.refresh();
        }
        else {
            controller_.update();
        }
    }

    if (controller_.stopped()) {
        stop();
    }
}

void PlayingGameState::pause() {
    paused_ = true;
}

void PlayingGameState::resume() {
    paused_ = false;
}


bool PlayingGameState::paused() {
    return paused_;
}


void PlayingGameState::stop() {
    active_ = false;
}