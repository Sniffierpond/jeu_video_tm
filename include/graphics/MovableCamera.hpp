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
    MovableCamera(sf::Vector2f position, float width, float height);

    sf::Vector2f getPosition() const override;

    float getWidth() const override;
    float getHeight() const override;

    MovementHandler& movementHandler() override;
    const MovementHandler& movementHandler() const;
};