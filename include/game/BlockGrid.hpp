/*
    -------------------------
    BlockGrid.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include "../game/Block.hpp"
#include <SFML/System/Vector2.hpp>

/*
Classe représentant un ensemble de blocs sous forme de grille.
*/
class BlockGrid {
    private:
    std::vector<std::vector<Block>> blocks_;
    public:
    BlockGrid(const std::vector<std::vector<Block>>& blocks);

    Block getBlock(sf::Vector2i position) const;
    void setBlock(sf::Vector2i position, Block block);

    int getWidth() const;
    int getHeight() const;
};