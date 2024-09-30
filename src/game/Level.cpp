/*
    -------------------------
    Level.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/game/Level.hpp"
#include <SFML/Graphics/Rect.hpp>

Level::Level(const BlockRegistry& registry, BlockGrid grid): registry_(&registry), grid_(sf::Vector2i(grid.getWidth() / 2, grid.getHeight() / 2), grid.getWidth(), grid.getHeight(), 0) {
    blockTypesIds_[0] = "base:air";

    for (int x = 0; x < grid.getWidth(); ++x) {
        for (int y = 0; y < grid.getHeight(); ++y) {
            std::string stringId = grid.getBlock(sf::Vector2i(x, y)).getBlockType();

            int intId;
            bool registered = false;

            for (auto& id: blockTypesIds_) {
                if (id == stringId) {
                    registered = true;
                    break;
                }
                ++intId;
            }

            if (!registered) {
                blockTypesIds_.push_back(stringId);
            }

            grid_.set(x, y, intId);
        }
    }
}

Level::Level(const BlockRegistry& registry, const std::vector<std::vector<unsigned int>>& blocks, sf::Vector2i origin, const std::vector<std::string> blockTypesIds): registry_(&registry), grid_(blocks, origin), blockTypesIds_(blockTypesIds) {}

Level::Level(Level&& other): grid_(std::move(other.grid_)), registry_(other.registry_), blockTypesIds_(std::move(other.blockTypesIds_)) {}

Block Level::getBlock(sf::Vector2i position) const {
    return registry_->get(blockTypesIds_.at(grid_.at(position.x, position.y)))->get().build();
}

BlockGrid Level::getBlocks(sf::IntRect rectangle) const {
    std::vector<std::vector<Block>> blocks;

    for (int y = 0; y < rectangle.height; ++y) {
        blocks.emplace_back();

        for (int x = 0; x < rectangle.width; ++x) {
            blocks.at(y).push_back(getBlock(sf::Vector2i(x, y)));
        }
    }

    return blocks;
}

unsigned int Level::width() const {
    return grid_.width();
}

unsigned int Level::height() const {
    return grid_.height();
}