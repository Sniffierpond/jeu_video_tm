/*
    -------------------------
    SimpleBlockBuilder.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/game/SimpleBlockBuilder.hpp"
#include "../../include/game/Block.hpp"
#include <memory>
#include <stdexcept>

SimpleBlockBuilder& SimpleBlockBuilder::setBlockType(std::string blockType) {
    blockType_ = blockType;
    return *this;
}

std::shared_ptr<Block> SimpleBlockBuilder::build() const {
    std::string textureId;

    if (blockType_ == "base:bricks" ||
    blockType_ == "base:dirt:1" ||
    blockType_ == "base:dirt:2" ||
    blockType_ == "base:dirt:3" ||
    blockType_ == "base:grass:1" ||
    blockType_ == "base:grass:2" ||
    blockType_ == "base:grass:3" ||
    blockType_ == "base:leaves" ||
    blockType_ == "base:sand" ||
    blockType_ == "base:stone" ||
    blockType_ == "base:tree_log") {
        textureId = blockType_;
    }
    else if (blockType_ != "base:air") {
        throw std::runtime_error("Unable to build a block with given type");
    }

    return std::make_shared<Block>(blockType_, textureId);
};