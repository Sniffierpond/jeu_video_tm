/*
    -------------------------
    StaticCamera.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include "../contracts/Camera.hpp"
#include <SFML/System/Vector2.hpp>

class StaticCamera: public Camera {
    private:
    sf::Vector2f position_;
    float width_;
    float height_;

    public:
    StaticCamera(sf::Vector2f position, float width, float height);

    void setPosition(sf::Vector2f position);
    sf::Vector2f getPosition() override;

    void setWidth(float width);
    float getWidth() override;

    void setHeight(float height);
    float getHeight() override;
};