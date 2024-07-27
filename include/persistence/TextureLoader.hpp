/*
    -------------------------
    TextureLoader.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include <SFML/Graphics/Texture.hpp>

/*
Classe utilitaire permettant de charger des textures depuis le système de fichier.
*/
class TextureLoader {
    public:
    /*
    Charge une texture à partir du fichier indiqué.
    */
    sf::Texture load(const std::string& filename) const;

    /*
    Charge une texture se trouvant dans une zone rectangulaire de longueur width et de largeur height
    et de coin supérieur gauche topLeft à partir du fichier indiqué.
    */
    sf::Texture load(const std::string& filename, sf::Vector2i topLeft, unsigned int width, unsigned int height) const;
};