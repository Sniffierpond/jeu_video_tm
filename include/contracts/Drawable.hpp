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
    public:
    /*
    Retourne l'identifiant de la texture de l'objet.
    */
    virtual std::string getTextureId() = 0;

    virtual ~Drawable() = 0;
};