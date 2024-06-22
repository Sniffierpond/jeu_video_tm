/*
    -------------------------
    Block.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/game/Block.hpp"

Block::Block(std::string blockType, sf::Texture& texture):blockType_(blockType), texture_(texture) {};

std::string Block::getBlockType() {
    return blockType_;
}

sf::Texture& Block::getTexture() {
    return texture_;
}