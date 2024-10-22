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

class SfmlInputHandler: public InputHandler
{
    private:
    sf::Window* window_;
    Controller* controller_;
    public:
    /*
    Note: le contrôleur ne peut pas être fourni à la construction à cause du problème de dépendances cycliques entre
    Controller et SfmlInputHandler.
    */
    SfmlInputHandler(sf::Window& window);

    void setController(Controller& controller) override;
    void handleInputs() override;
};