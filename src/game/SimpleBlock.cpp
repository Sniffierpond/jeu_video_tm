/*
    -------------------------
    SimpleBlock.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/game/SimpleBlock.hpp"

SimpleBlock::SimpleBlock(std::string blockType, sf::Texture& texture):blockType_(blockType), texture_(texture) {};

std::string SimpleBlock::getBlockType() {
    return blockType_;
}

sf::Texture& SimpleBlock::getTexture() {
    return texture_;
}