/*
    -------------------------
    BlockRegistry.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include "../contracts/Block.hpp"
#include <SFML/Graphics/Texture.hpp>

class SimpleBlock: Block {
    private:
    std::string blockType_;
    sf::Texture& texture_;
    public:
    SimpleBlock(std::string blockType, sf::Texture& texture);
    std::string getBlockType() override;
    sf::Texture& getTexture() override;
};