/*
    -------------------------
    BlockBuilder.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include "../game/Block.hpp"

class BlockBuilder {
    public:
    virtual Block build() = 0;
};