/*
    -------------------------
    BlockBuilder.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include "Block.hpp"

class BlockBuilder {
    public:
    virtual Block build() = 0;
};