/*
    -------------------------
    View.hpp
    auteur: Jonathan Rochat
    -------------------------
*/
#pragma once

#include "../contracts/Viewable.hpp"
#include <SFML/System/Vector2.hpp>

class View: Viewable {
    private:
    Renderer* renderer_;

    unsigned int width_;
    unsigned int height_;

    sf::Vector2f windowPos0_;

    public:
    View(Renderer& renderer, unsigned int width, unsigned int height, sf::Vector2f windowPos0);

    void setRenderer(Renderer& renderer) override;

    void refresh() override;

    unsigned int getWidth() override;
    unsigned int getHeight() override;

    sf::Vector2f getWindowPos0() override;
};