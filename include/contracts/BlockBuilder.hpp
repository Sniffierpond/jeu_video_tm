/*
    -------------------------
    BlockBuilder.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include "../game/Block.hpp"
#include <memory>

class BlockBuilder {
    public:
    virtual std::shared_ptr<Block> build() const = 0 ;

    virtual ~BlockBuilder() = 0;
};