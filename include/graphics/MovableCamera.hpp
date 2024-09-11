/*
    -------------------------
    MovableCamera.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include "../contracts/Camera.hpp"
#include "../contracts/Movable.hpp"
#include <SFML/System/Vector2.hpp>

class MovableCamera: public Movable, public Camera {
    private:
    MovementHandler movementHandler_;
    float width_;
    float height_;

    public:
    /*
    Note le vecteur position représente les coordonnées du coin supérieur gauche
    si on considère que les "y" descendent et que les "x" vont à gauche.
    */
    MovableCamera(sf::Vector2f position, float width, float height);

    sf::Vector2f getPosition() const override;

    float getWidth() const override;
    float getHeight() const override;

    MovementHandler& movementHandler() override;
    const MovementHandler& movementHandler() const;
};