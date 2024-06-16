/*
    -------------------------
    Drawable.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include <SFML/Graphics/Texture.hpp>

class Drawable {
    virtual sf::Texture& getTexture() = 0;
};