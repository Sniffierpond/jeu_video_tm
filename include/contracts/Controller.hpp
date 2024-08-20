/*
    -------------------------
    Controller.hpp
    auteur: Jonathan Rochat
    -------------------------
*/
#pragma once

#include "InputHandler.hpp"
#include "Viewable.hpp"

#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Vector2.hpp>

/*
Représente un controller chargé de faire le lien entre l'affichage d'un état de l'application, la logique de cet état et les actions de l'utilisateur.
*/
class Controller {
    public:
    virtual void setInputHandler(InputHandler& inputHandler) = 0;
    virtual void setViewable(Viewable& viewable) = 0;

    /*
    Met uniquement à jour l'affichage.
    */
    virtual void refresh() = 0;
    
    virtual void update() = 0;
    
    virtual void pressKey(sf::Keyboard::Key keyCode) = 0;
    virtual void releaseKey(sf::Keyboard::Key keyCode) = 0;

    virtual void leftClick(sf::Vector2f position) = 0;
    virtual void rightClick(sf::Vector2f position) = 0;

    virtual void moveMouse(sf::Vector2f position) = 0;

    virtual bool stopped() const = 0;

    virtual void exit() = 0;

    virtual ~Controller() = 0;
};
