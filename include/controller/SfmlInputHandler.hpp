/*
    -------------------------
    SfmlInputHandler.hpp
    auteur: Jonathan Rochat
    -------------------------
*/
#pragma once

#include "../contracts/InputHandler.hpp"
#include "../contracts/Controller.hpp"
#include <SFML/Window.hpp>

class SfmlInputHandler: InputHandler
{
    private:
    sf::Window* window_;
    Controller* controller_;
    public:
    SfmlInputHandler(sf::Window& window);

    void setController(Controller& controller) override;
    void handleInputs() override;
};