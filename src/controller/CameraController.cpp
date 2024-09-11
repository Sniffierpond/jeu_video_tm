/*
    -------------------------
    CameraController.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/controller/CameraController.hpp"
#include "../../include/contracts/GameState.hpp"
#include <SFML/Window/Keyboard.hpp>

CameraController::CameraController(MovableCamera* camera, InputHandler& inputHandler, Viewable& viewable): camera_(camera), inputHandler_(&inputHandler), viewable_(&viewable) {
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

        camera_->movementHandler().update(timeDiff);
        inputHandler_->handleInputs();

        refresh();
    }
}


void CameraController::pressKey(sf::Keyboard::Key keyCode) {
    if (keyCode == sf::Keyboard::W || keyCode == sf::Keyboard::Up) {
        camera_->movementHandler().addSpeed(sf::Vector2<Speed>(0.0_bps, 2.0_bps));
    }
    else if (keyCode == sf::Keyboard::S || keyCode == sf::Keyboard::Down) {
        camera_->movementHandler().addSpeed(sf::Vector2<Speed>(0.0_bps, -2.0_bps));
    }
    else if (keyCode == sf::Keyboard::D || keyCode == sf::Keyboard::Right) {
        camera_->movementHandler().addSpeed(sf::Vector2<Speed>(2.0_bps, 0.0_bps));
    }
    else if (keyCode == sf::Keyboard::A || keyCode == sf::Keyboard::Left) {
        camera_->movementHandler().addSpeed(sf::Vector2<Speed>(-2.0_bps, 0.0_bps));
    }
}

void CameraController::releaseKey(sf::Keyboard::Key keyCode) {
    if (keyCode == sf::Keyboard::W || keyCode == sf::Keyboard::Up) {
        camera_->movementHandler().addSpeed(sf::Vector2<Speed>(0.0_bps, -2.0_bps));
    }
    else if (keyCode == sf::Keyboard::S || keyCode == sf::Keyboard::Down) {
        camera_->movementHandler().addSpeed(sf::Vector2<Speed>(0.0_bps, 2.0_bps));
    }
    else if (keyCode == sf::Keyboard::D || keyCode == sf::Keyboard::Right) {
        camera_->movementHandler().addSpeed(sf::Vector2<Speed>(-2.0_bps, 0.0_bps));
    }
    else if (keyCode == sf::Keyboard::A || keyCode == sf::Keyboard::Left) {
        camera_->movementHandler().addSpeed(sf::Vector2<Speed>(2.0_bps, 0.0_bps));
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