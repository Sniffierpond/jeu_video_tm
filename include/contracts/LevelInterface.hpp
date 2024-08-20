/*
    -------------------------
    LevelInterface.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include <SFML/System/Vector2.hpp>

#include "Block.hpp"
#include "BlockGrid.hpp"
#include "Player.hpp"

class LevelInterface {
    public:
    virtual void update(int timeDiff) = 0;

    virtual void select(sf::Vector2i blockPosition) = 0;
    virtual void interact(sf::Vector2i blockPosition) = 0;
    
    virtual Block getBlock(sf::Vector2i) = 0;
    virtual BlockGrid getBlocks(sf::Vector2i pos0, sf::Vector2i pos1) = 0;

    virtual Player& getPlayer() = 0;

    virtual unsigned int getLevelId();

    virtual ~LevelInterface() = 0;
};