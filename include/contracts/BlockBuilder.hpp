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
    virtual Block build() const = 0 ;

    virtual ~BlockBuilder() = 0;
};