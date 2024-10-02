/*
    -------------------------
    BlockRenderer.cpp
    auteur: Jonathan Rochat
    -------------------------
*/

#include "../../include/graphics/BlockRenderer.hpp"
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <cassert>

BlockRenderer::BlockRenderer(const BlockGrid& grid, sf::FloatRect renderArea, const TextureRegistry& registry): grid_(grid), renderArea_(renderArea), textureRegistry_(registry) {
    if (renderArea_. width < 0 || renderArea_.height < 0) {
        throw std::invalid_argument("Size of the render area must not be negative.");
    }
    if (renderArea_.left + renderArea_.width > grid.getWidth() || renderArea_.top + renderArea_.height > grid.getHeight()) {
        throw std::invalid_argument("Render area must be contained in block grid area.");
    }
}

void BlockRenderer::render(sf::RenderTarget& target) const {
    for (int x = 0; x < grid_.getWidth(); ++x) {
        for (int y = 0; y < grid_.getHeight(); ++y) {
            if (grid_.getBlock({x, y}).getBlockType() != "base:air") {
                std::optional<sf::Texture> optTexture = textureRegistry_.get(grid_.getBlock({x, y}).getTextureId());

                if(optTexture.has_value()) {
                    sf::Sprite blockSprite(*optTexture);

                    blockSprite.setPosition({static_cast<float>(x), static_cast<float>(grid_.getHeight() - 1 - y)});
                    blockSprite.setScale(1.0 / optTexture->getSize().x, 1.0 / optTexture->getSize().y);

                    target.draw(blockSprite);
                }
                else {
                    throw std::runtime_error("Texture " + grid_.getBlock({x, y}).getTextureId() + " not registered.");
                }
            }
        }
    }

    /* sf::RectangleShape rect({size.x, size.y});
    rect.setFillColor(sf::Color::Red);

    target.draw(rect); */
}