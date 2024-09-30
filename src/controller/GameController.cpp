/*
    -------------------------
    GameController.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/controller/GameController.hpp"
#include <SFML/Window/Keyboard.hpp>

GameController::GameController(PhysicsHandler& physicsHandler, Player& player, InputHandler& inputHandler, Viewable& viewable, unsigned int levelWidth, unsigned int levelHeight):
    physicsHandler_(&physicsHandler),
    player_(&player),
    inputHandler_(&inputHandler),
    viewable_(&viewable),
    levelWidth_(levelWidth),
    levelHeight_(levelHeight)
{}


void GameController::setInputHandler(InputHandler &inputHandler) {
    inputHandler_ = &inputHandler;
}

void GameController::setViewable(Viewable &viewable) {
    viewable_ = &viewable;
}


void GameController::refresh() {
    if (!stopped_) {
        viewable_->refresh();
    }
}

void GameController::update() {
    if (!stopped_) {
        auto timeDiff = clock_.now() - start_;
        start_ = clock_.now();

        physicsHandler_->update(timeDiff);

        refresh();
    }
}


void GameController::pressKey(sf::Keyboard::Key keyCode) {
    if (keyCode == sf::Keyboard::A || keyCode == sf::Keyboard::Left) {
        if (!movingLeft_) {
            player_->movementHandler().setAcceleration({-2.0_bps2, player_->movementHandler().getAcceleration().y});
            movingLeft_ = true;
        }
    }
    else if (keyCode == sf::Keyboard::D || keyCode == sf::Keyboard::Right) {
        if (!movingRight_) {
            player_->movementHandler().setAcceleration({2.0_bps2, player_->movementHandler().getAcceleration().y});
            movingRight_ = true;
        }
    }
}

void GameController::releaseKey(sf::Keyboard::Key keyCode) {
    if (keyCode == sf::Keyboard::A || keyCode == sf::Keyboard::Left || keyCode == sf::Keyboard::D || keyCode == sf::Keyboard::Right) {
        player_->movementHandler().setAcceleration({0.0_bps2, player_->movementHandler().getAcceleration().y});
        
        movingLeft_ = false;
        movingRight_ = false;
    }
}

void GameController::leftClick(sf::Vector2f position) {}

void GameController::rightClick(sf::Vector2f position) {}


void GameController::moveMouse(sf::Vector2f position) {}


bool GameController::stopped() const {
    return stopped_;
}

void GameController::exit() {
    stopped_ = true;
}