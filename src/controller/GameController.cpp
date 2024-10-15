/*
    -------------------------
    GameController.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/controller/GameController.hpp"
#include <SFML/Window/Keyboard.hpp>

GameController::GameController(PlayerPhysicsHandler& physicsHandler, Player& player, InputHandler& inputHandler, Viewable& viewable, PlayerCamera& camera, unsigned int levelWidth, unsigned int levelHeight):
    physicsHandler_(&physicsHandler),
    player_(&player),
    inputHandler_(&inputHandler),
    viewable_(&viewable),
    camera_(&camera),
    levelWidth_(levelWidth),
    levelHeight_(levelHeight)
{
    inputHandler_->setController(*this);
    start_ = clock_.now();
}


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
        auto timeDiff = (clock_.now() - start_);
        start_ = clock_.now();

        inputHandler_->handleInputs();
        physicsHandler_->update(timeDiff);
        player_->animationHandler().update(timeDiff);
        camera_->update(timeDiff);

        refresh();
    }
}


void GameController::pressKey(sf::Keyboard::Key keyCode) {
    if (keyCode == sf::Keyboard::A || keyCode == sf::Keyboard::Left) {
        physicsHandler_->startGoingLeft();
    }
    else if (keyCode == sf::Keyboard::D || keyCode == sf::Keyboard::Right) {
        physicsHandler_->startGoingRight();
    }
    else if (keyCode == sf::Keyboard::Space || keyCode == sf::Keyboard::Up) {
        physicsHandler_->jump();
    }
    else if (keyCode == sf::Keyboard::P) {
        camera_->pause();
    }
    else if (keyCode == sf::Keyboard::R) {
        camera_->resume();
    }
}

void GameController::releaseKey(sf::Keyboard::Key keyCode) {
    if (keyCode == sf::Keyboard::A || keyCode == sf::Keyboard::Left || keyCode == sf::Keyboard::D || keyCode == sf::Keyboard::Right) {
        physicsHandler_->stop();
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