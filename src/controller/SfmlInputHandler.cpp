/*
    -------------------------
    SfmlInputHandler.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/controller/SfmlInputHandler.hpp"
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>

SfmlInputHandler::SfmlInputHandler(sf::Window& window, Controller& controller): window_(&window), controller_(&controller) {};

void SfmlInputHandler::setController(Controller& controller) {
    controller_ = &controller;
}

void SfmlInputHandler::handleInputs() {
    sf::Event event;

    while (window_->pollEvent(event)) {
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                controller_->leftClick(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
            }
            else if (event.mouseButton.button == sf::Mouse::Right) {
                controller_->rightClick(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
            }
        }
        else if (event.type == sf::Event::MouseMoved) {
            controller_->moveMouse(sf::Vector2f(event.mouseMove.x, event.mouseMove.y));
        }
        else if (event.type == sf::Event::KeyPressed) {
            controller_->pressKey(event.key.code);
        }
        else if (event.type == sf::Event::KeyReleased) {
            controller_->releaseKey(event.key.code);
        }
        else if(event.type == sf::Event::Closed) {
            controller_->exit();
        }
    }
}