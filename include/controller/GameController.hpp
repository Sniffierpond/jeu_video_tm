/*
    -------------------------
    GameController.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include "../contracts/Controller.hpp"
#include "../physics/PlayerPhysicsHandler.hpp"
#include "../game/Player.hpp"
#include "../graphics/PlayerCamera.hpp"
#include <chrono>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>

class GameController: public Controller {
    private:
    InputHandler* inputHandler_;
    Viewable* viewable_;

    PlayerPhysicsHandler* physicsHandler_;
    Player* player_;

    PlayerCamera* camera_;
    
    unsigned int levelWidth_;
    unsigned int levelHeight_;

    bool stopped_ = false;

    std::chrono::steady_clock clock_;
    std::chrono::time_point<std::chrono::steady_clock> start_;

    public:
    GameController(PlayerPhysicsHandler& PhysicsHandler, Player& player, InputHandler& inputHandler, Viewable& viewable, PlayerCamera& camera, unsigned int levelWidth, unsigned int levelHeight);
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