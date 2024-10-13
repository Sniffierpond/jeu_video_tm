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

    bool paused_ = false;
    
    float width_, height_;
    unsigned int levelWidth_;
    unsigned int levelHeight_;

    sf::Vector2f position_;

    public:
    PlayerCamera(Player& player, float width, float height, unsigned int levelWidth, unsigned int levelHeight);

    sf::Vector2f getPosition() const override;

    float getWidth() const override;
    float getHeight() const override;

    void update(std::chrono::nanoseconds timeDifference) override;

    void pause();
    void resume();
};