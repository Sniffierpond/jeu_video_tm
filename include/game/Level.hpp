/*
    -------------------------
    Level.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include "../utils/Array2.hpp"
#include "BlockRegistry.hpp"
#include "BlockGrid.hpp"

#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <map>

class Level {
    protected:
    Array2<unsigned int> grid_;
    
    const BlockRegistry* registry_;

    std::vector<std::string> blockTypesIds_;
    public:
    Level(const BlockRegistry& registry, BlockGrid grid);
    Level(const BlockRegistry& registry, const std::vector<std::vector<unsigned int>>& blocks, sf::Vector2i origin, const std::vector<std::string> blockTypesIds);
    Level(Level&& other);

    Block getBlock(sf::Vector2i position) const;
    /*
    Retourne une portion de la grille du niveau sous forme de rectangle.
    */
    BlockGrid getBlocks(sf::IntRect rectangle) const;
};