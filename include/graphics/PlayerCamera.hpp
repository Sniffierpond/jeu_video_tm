/*
    -------------------------
    PlayerCamera.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include "../contracts/Camera.hpp"
#include "../contracts/Updatable.hpp"
#include "../game/Player.hpp"
#include <SFML/System/Vector2.hpp>
#include <chrono>
#include <functional>

class PlayerCamera: public Camera, public Updatable {
    private:
    std::reference_wrapper<Player> player_;

    float width_, height_;

    sf::Vector2f position_;

    public:
    PlayerCamera(Player& player, float width, float height);

    sf::Vector2f getPosition() const override;

    float getWidth() const override;
    float getHeight() const override;

    void update(std::chrono::nanoseconds timeDifference) override;
};