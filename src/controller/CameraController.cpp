/*
    -------------------------
    CameraController.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/controller/CameraController.hpp"
#include "../../include/contracts/GameState.hpp"
#include <SFML/Window/Keyboard.hpp>

CameraController::CameraController(MovableCamera* camera, InputHandler& inputHandler, Viewable& viewable, unsigned int levelWidth, unsigned int levelHeight): camera_(camera), inputHandler_(&inputHandler), viewable_(&viewable), levelWidth_(levelWidth), levelHeight_(levelHeight) {
    start_ = clock_.now();
    inputHandler_->setController(*this);
}


void CameraController::setInputHandler(InputHandler& inputHandler) {
    inputHandler_ = &inputHandler;
    inputHandler_->setController(*this);
}

void CameraController::setViewable(Viewable& viewable) {
    viewable_ = &viewable;
}


void CameraController::refresh() {
    if (!stopped_) {
        viewable_->refresh();
    }
}


void CameraController::update() {
    if (!stopped_) {
        auto timeDiff = clock_.now() - start_;
        start_ = clock_.now();

        inputHandler_->handleInputs();
        camera_->movementHandler().update(timeDiff);
        
        if (camera_->getPosition().x + camera_->getWidth() > levelWidth_)
            camera_->movementHandler().setPosition({levelWidth_ - camera_->getWidth() - 1, camera_->getPosition().y});
        else if (camera_->getPosition().x < 0)
            camera_->movementHandler().setPosition({0, camera_->getPosition().y});
        
        if (camera_->getPosition().y + camera_->getHeight() > levelHeight_)
            camera_->movementHandler().setPosition({camera_->getPosition().x, levelHeight_ - camera_->getHeight() - 1});
        else if (camera_->getPosition().y < 0)
            camera_->movementHandler().setPosition({camera_->getPosition().x, 0});

        refresh();
    }
}


void CameraController::pressKey(sf::Keyboard::Key keyCode) {
    if (keyCode == sf::Keyboard::W || keyCode == sf::Keyboard::Up) {
        camera_->movementHandler().setSpeed(sf::Vector2<Speed>(0.0_bps, 4.0_bps));
    }
    else if (keyCode == sf::Keyboard::S || keyCode == sf::Keyboard::Down) {
        camera_->movementHandler().setSpeed(sf::Vector2<Speed>(0.0_bps, -4.0_bps));
    }
    else if (keyCode == sf::Keyboard::D || keyCode == sf::Keyboard::Right) {
        camera_->movementHandler().setSpeed(sf::Vector2<Speed>(4.0_bps, 0.0_bps));
    }
    else if (keyCode == sf::Keyboard::A || keyCode == sf::Keyboard::Left) {
        camera_->movementHandler().setSpeed(sf::Vector2<Speed>(-4.0_bps, 0.0_bps));
    }
}

void CameraController::releaseKey(sf::Keyboard::Key keyCode) {
    if (keyCode == sf::Keyboard::W || keyCode == sf::Keyboard::Up) {
        camera_->movementHandler().setSpeed(sf::Vector2<Speed>(0.0_bps, 0.0_bps));
    }
    else if (keyCode == sf::Keyboard::S || keyCode == sf::Keyboard::Down) {
        camera_->movementHandler().setSpeed(sf::Vector2<Speed>(0.0_bps, 0.0_bps));
    }
    else if (keyCode == sf::Keyboard::D || keyCode == sf::Keyboard::Right) {
        camera_->movementHandler().setSpeed(sf::Vector2<Speed>(0.0_bps, 0.0_bps));
    }
    else if (keyCode == sf::Keyboard::A || keyCode == sf::Keyboard::Left) {
        camera_->movementHandler().setSpeed(sf::Vector2<Speed>(0.0_bps, 0.0_bps));
    }
}


void CameraController::leftClick(sf::Vector2f position) {}

void CameraController::rightClick(sf::Vector2f position) {}


void CameraController::moveMouse(sf::Vector2f position) {}


bool CameraController::stopped() const {
    return stopped_;
}
void CameraController::exit() {
    stopped_ = true;
}