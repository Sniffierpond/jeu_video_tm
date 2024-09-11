/*
    -------------------------
    CameraController.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include "../contracts/Controller.hpp"
#include "../graphics/MovableCamera.hpp"
#include <chrono>

class CameraController: Controller {
    private:
    InputHandler* inputHandler_;
    Viewable* viewable_;
    MovableCamera* camera_;

    bool stopped_ = false;

    std::chrono::steady_clock clock_;
    std::chrono::time_point<std::chrono::steady_clock> start_;

    public:
    CameraController(MovableCamera* camera, InputHandler& inputHandler, Viewable& viewable);

    void setInputHandler(InputHandler& inputHandler) override;
    void setViewable(Viewable& viewable) override;

    void refresh() override;

    void update() override;

    void pressKey(sf::Keyboard::Key keyCode) override;
    void releaseKey(sf::Keyboard::Key keyCode) override;

    void leftClick(sf::Vector2f position) override;
    void rightClick(sf::Vector2f position) override;

    void moveMouse(sf::Vector2f position) override;

    bool stopped() const override;

    void exit() override;
};