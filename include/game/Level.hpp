/*
    -------------------------
    Level.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include "../utils/Expandable2DArray.hpp"
#include "BlockRegistry.hpp"
#include "BlockGrid.hpp"

#include <SFML/System/Vector2.hpp>
#include <map>

class Level {
    protected:
    Expandable2DArray<int> grid_;
    
    const BlockRegistry* registry_;

    std::map<int, std::string> blockTypesIds_;
    public:
    Level(const BlockRegistry& registry, BlockGrid grid);

    Block getBlock(sf::Vector2i position) const;
    /*
    Retourne une portion de la grille du niveau sous forme de rectangle en considérant position0 comme le point inférieur gauche.
    */
    BlockGrid getBlocks(sf::Vector2i position0, int width, int height) const;
};