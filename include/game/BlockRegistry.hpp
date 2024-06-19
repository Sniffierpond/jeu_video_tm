/*
    -------------------------
    BlockRegistry.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include <map>
#include "../contracts/BlockBuilder.hpp"
/*
Représente un registre
*/
class BlockRegistry {
    private:
    std::map<std::string, BlockBuilder&> registry_;
    public:
    void registerBlock(std::string blockType, BlockBuilder& builder);
    BlockBuilder& getBlockBuilder(std::string blockType);
};