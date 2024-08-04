/*
    -------------------------
    View.hpp
    auteur: Jonathan Rochat
    -------------------------
*/
#pragma once

#include "../contracts/Viewable.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class View: Viewable {
    private:
    sf::RenderTarget* renderTarget_;

    Renderer* renderer_;

    unsigned int width_;
    unsigned int height_;

    sf::Vector2i windowPos0_;

    public:
    View(sf::RenderTarget& renderTarget, Renderer& renderer, unsigned int width, unsigned int height, sf::Vector2i windowPos0);

    void setRenderer(Renderer& renderer) override;

    /*
    Récupère une texture du Renderer et l'adapte à la zone graphique qu'elle doit couvrir
    en agrandissant cette texture et en tronquant les parties externes de la texture nécessaires.
    */
    void refresh() override;

    unsigned int getWidth() override;
    unsigned int getHeight() override;

    sf::Vector2i getWindowPos0() override;
};