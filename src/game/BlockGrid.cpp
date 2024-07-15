/*
    -------------------------
    BlockGrid.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/game/BlockGrid.hpp"
#include <SFML/System/Vector2.hpp>

BlockGrid::BlockGrid(const std::vector<std::vector<Block>>& blocks) {
    blocks_ = blocks;
}

Block BlockGrid::getBlock(sf::Vector2i position) const {
    return blocks_.at(position.y).at(position.x);
}

void BlockGrid::setBlock(sf::Vector2i position, Block block) {
    blocks_.at(position.y).at(position.x) = block;
}


int BlockGrid::getWidth() const {
    return blocks_.begin()->size();
}

int BlockGrid::getHeight() const {
    return blocks_.size();
}