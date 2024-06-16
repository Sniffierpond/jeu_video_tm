/*
    -------------------------
    Block.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include "Drawable.hpp"
#include <string>

class Block: Drawable {
    public:
    virtual std::string getBlockType() = 0;
    virtual sf::Texture& getTexture() override = 0;
};