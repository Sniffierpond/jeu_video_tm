/*
    -------------------------
    BaseBlocksRegister.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include "BlockRegistry.hpp"

class BaseBlocksRegister {
    public:
    void registerBlocks(BlockRegistry& registry) const;
};