/*
    -------------------------
    PlayingGameState.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/core/PlayingGameState.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath>

PlayingGameState::PlayingGameState(const TextureRegistry& textureRegistry, Level&& level, sf::RenderWindow& window, sf::Vector2f playerInitPos):
    player_(playerInitPos),              //En attendant de mettre au point un système de "spawpoint"
    level_(std::move(level)),   //Transfert du ownership
    physicsHandler_(player_, gravityAcceleration_, maxHorSpeed_, maxVertSpeed_, jumpSpeed_, level_),
    camera_(player_,level_.width() < 10 ? level_.width() - 1 : 10, level_.height() < (90.0 / 16) ? level_.height() - 1: (90 / 16), level_.width(), level_.height()),
    renderer_(&level_, player_, camera_, textureRegistry),
    viewable_(window, renderer_, window.getSize().x, window.getSize().y, sf::Vector2i(0, 0)),
    inputHandler_(window),
    controller_(physicsHandler_, player_, inputHandler_, viewable_, camera_, level_.width(), level_.height())
{}

void PlayingGameState::start() {
    std::cout << "PlayingGameState démarré." << std::endl;
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
    std::cout << "PlayingGameState mis en pause" << std::endl;
    paused_ = true;
}

void PlayingGameState::resume() {
    std::cout << "Reprise de l'exécution de PlayingGameState" << std::endl;
    paused_ = false;
}


bool PlayingGameState::paused() {
    return paused_;
}


void PlayingGameState::stop() {
    std::cout << "PlayingGameState arrêté" << std::endl;
    active_ = false;
}