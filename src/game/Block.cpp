/*
    -------------------------
    Block.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/game/Block.hpp"
#include <string>

Block::Block(std::string blockType, std::string texture):blockType_(blockType), textureId_(texture) {};

std::string Block::getBlockType() {
    return blockType_;
}

std::string Block::getTextureId() {
    return textureId_;
}