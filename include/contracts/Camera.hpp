/*
    -------------------------
    Camera.hpp
    auteur: Jonathan Rochat
    -------------------------
*/
#pragma once

#include <SFML/System/Vector2.hpp>

class Camera  {
    public:
    /*
    NOTE: La position de la caméra est celle du centre de la zone "vue" par celle-ci.
    */
    virtual sf::Vector2f getPosition() = 0;

    /*
    Retourne la longueur du "rectangle" représentant le champs de vision
    de la caméra.
    */
    virtual float getWidth() = 0;
    /*Retourne la largeur du "rectangle" représentant le champs de vision
    de la caméra.*/
    virtual float getHeight() = 0;
};