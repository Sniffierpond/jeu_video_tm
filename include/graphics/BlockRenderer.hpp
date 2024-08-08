/*
    -------------------------
    BlockRenderer.hpp
    auteur: Jonathan Rochat
    -------------------------
*/

#pragma once

#include "../contracts/Renderer.hpp"
#include "../game/Level.hpp"
#include "TextureRegistry.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "../game/BlockGrid.hpp"

/*
Effectue le rendu d'une grille de blocs.
*/
class BlockRenderer: public Renderer {
    private:
    const BlockGrid& grid_;
    const TextureRegistry& textureRegistry_;
    sf::FloatRect renderArea_;

    public:
    BlockRenderer(const BlockGrid& grid, sf::FloatRect renderArea, const TextureRegistry& registry);

    sf::Texture render() const override;
};