/*
    -------------------------
    Block.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include <SFML/Graphics/Texture.hpp>

class Block {
    private:
    std::string blockType_;
    sf::Texture& texture_;
    public:
    Block(std::string blockType, sf::Texture& texture);
    std::string getBlockType();
    sf::Texture& getTexture();
};