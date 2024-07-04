/*
    -------------------------
    BlockRegistry.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/game/BlockRegistry.hpp"
#include <exception>

void BlockRegistry::registerBlock(std::string blockType, BlockBuilder& builder) {
    if (registry_.find(blockType) == registry_.end()) {
        throw "Error: the block cannot be registered because it already is.";
    }
    else {
        registry_[blockType] = builder;
    }
}

BlockBuilder& BlockRegistry::getBlockBuilder(std::string blockType) const{
    return registry_.at(blockType);
}