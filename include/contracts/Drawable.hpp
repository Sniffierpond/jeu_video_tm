/*
    -------------------------
    Drawable.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <string>

class Drawable {
    virtual std::string getTextureId() = 0;
};