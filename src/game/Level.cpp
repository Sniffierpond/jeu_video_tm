/*
    -------------------------
    Level.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/game/Level.hpp"

Level::Level(const BlockRegistry& registry, BlockGrid grid): registry_(&registry), grid_(sf::Vector2i(grid.getWidth() / 2, grid.getHeight() / 2), grid.getWidth(), grid.getHeight(), 0) {
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

            grid_.at(x, y) = intId;
        }
    }
}

Block Level::getBlock(sf::Vector2i position) const {
    return registry_->get(blockTypesIds_.at(grid_.at(position.x, position.y)))->get().build();
}

BlockGrid Level::getBlocks(sf::IntRect rectangle) const {
    std::vector<std::vector<Block>> blocks;

    for (int y = rectangle.top; y < rectangle.top + rectangle.height; ++y) {
        blocks.emplace_back();

        for (int x = rectangle.left; x < rectangle.left + rectangle.width; ++x) {
            blocks.at(y).push_back(getBlock(sf::Vector2i(x, y)));
        }
    }

    return blocks;
}