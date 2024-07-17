/*
    -------------------------
    Block.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include <SFML/Graphics/Texture.hpp>
#include "../contracts/Drawable.hpp"

class SimpleBlockBuilder;

class Block: Drawable {
    private:
    std::string blockType_;
    std::string textureId_;
    Block(std::string blockType, std::string textureId);

    friend SimpleBlockBuilder;    
    public:
    std::string getBlockType();
    std::string getTextureId() override;
};