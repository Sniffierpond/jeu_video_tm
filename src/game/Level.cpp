/*
    -------------------------
    Level.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/game/Level.hpp"

Level::Level(const BlockRegistry& registry, BlockGrid grid): registry_(&registry) {
    blockTypesIds_[0] = "base:air";

    for (int x = 0; x < grid.getWidth(); ++x) {
        for (int y = 0; y < grid.getHeight(); ++y) {
            std::string stringId = grid.getBlock(sf::Vector2i(x, y)).getBlockType();

            int intId = blockTypesIds_.size() - 1;
            bool registered = false;

            for (auto it = blockTypesIds_.begin(); it != blockTypesIds_.end(); ++it) {
                if (it->second == stringId) {
                    registered = true;
                    intId = it->first;
                    break;
                }
            }

            if (!registered) {
                blockTypesIds_[intId] = stringId;
            }

            grid_.set(intId, x, y, 0);
        }
    }
}

Block Level::getBlock(sf::Vector2i position) const {
    return registry_->getBlockBuilder(blockTypesIds_.at(grid_.at(position.x, position.y))).build();
}

BlockGrid Level::getBlocks(sf::Vector2i position0, int width, int height) const {
    std::vector<std::vector<Block>> blocks;

    for (int y = position0.y; y < position0.y + height; ++y) {
        blocks.emplace_back();

        for (int x = position0.x; x < position0.x + width; ++x) {
            blocks.at(y).push_back(getBlock(sf::Vector2i(x, y)));
        }
    }

    return blocks;
}