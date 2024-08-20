/*
    -------------------------
    Viewable.hpp
    auteur: Jonathan Rochat
    -------------------------
*/
#pragma once

#include "Renderer.hpp"
#include <SFML/System/Vector2.hpp>

/*
Interface représentant une zone graphique dont le contenu peut être affiché dans une fenêtre.
*/
class Viewable {
    public:
    virtual void setRenderer(Renderer& renderer) = 0;
    
    /*
    Rafraîchit l'affichage.
    */
    virtual void refresh() = 0;

    virtual unsigned int getWidth() = 0;
    virtual unsigned int getHeight() = 0;

    /*
    Retourne la position de la zone graphique du Viewable relativement au coin supérieur gauche de la fenêtre.
    */
    virtual sf::Vector2i getWindowPos0() = 0;

    virtual ~Viewable() = 0;
};