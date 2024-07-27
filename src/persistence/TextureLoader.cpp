/*
    -------------------------
    TextureLoader.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/persistence/TextureLoader.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <stdexcept>

sf::Texture TextureLoader::load(const std::string& filename) const {
    sf::Texture texture;

    if (!texture.loadFromFile(filename)) {
        throw std::runtime_error("Error: unable to load texture from file " + filename);
    }
    
    return texture;
}

sf::Texture TextureLoader::load(const std::string& filename, sf::Vector2i topLeft, unsigned int width, unsigned int height) const {
    sf::Texture texture;

    if (!texture.loadFromFile(filename, sf::IntRect(topLeft.x, topLeft.y, width, height))) {
        throw std::runtime_error("Error: unable to load texture from file " + filename);
    }

    return texture;
}