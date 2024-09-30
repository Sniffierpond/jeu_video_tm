/*
    -------------------------
    Renderer.cpp
    auteur: Jonathan Rochat
    -------------------------
*/
#pragma once

#include <SFML/Graphics/Texture.hpp>
class Viewable;

/*
Représente un objet effectuant le rendu de quelque chose.
*/
class Renderer {
    public:
    /*
    Retourne une texture contenant les éléments rendus.
    */
    virtual void render(sf::RenderTarget& target) const = 0;

    virtual ~Renderer() = 0;
};